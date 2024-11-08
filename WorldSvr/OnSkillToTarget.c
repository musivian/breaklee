#include "ClientProtocol.h"
#include "ClientProcedures.h"
#include "ClientSocket.h"
#include "IPCProcedures.h"
#include "Notification.h"
#include "Server.h"

CLIENT_PROCEDURE_BINDING(SKILL_TO_TARGET) {
	if (!Character) goto error;

	S2C_DATA_SKILL_TO_TARGET_BUFF* Response = PacketBufferInit(Connection->PacketBuffer, S2C, SKILL_TO_TARGET_BUFF);
	Response->SkillIndex = Packet->SkillIndex;

	S2C_DATA_NFY_SKILL_TO_TARGET_BUFF* Notification = PacketBufferInit(Socket->PacketBuffer, S2C, NFY_SKILL_TO_TARGET_BUFF);
	Notification->CharacterIndex = (UInt32)Character->CharacterIndex;
	Notification->SkillIndex = Packet->SkillIndex;

	/*
	C2S_DATA_SKILL_TO_TARGET_WING_TARGET
		S2C_DATA_SKILL_TO_CHARACTER_WING
	*/

	if (!RTCharacterIsAlive(Runtime, Character)) goto error;

	RTMovementUpdateDeadReckoning(Runtime, &Character->Movement);

	RTSkillSlotRef SkillSlot = RTCharacterGetSkillSlotBySkillIndex(Runtime, Character, Packet->SkillIndex); 
	if (!SkillSlot) goto error;

	RTCharacterSkillDataRef SkillData = RTRuntimeGetCharacterSkillDataByID(Runtime, SkillSlot->ID);
	if (!SkillData) goto error;

	// TODO: Add SkillData validations
	// TODO: Add skill cast time and cooldown checks
	// TODO: Consume sp

	Int32 RequiredMP = RTCharacterCalculateRequiredMP(
		Runtime,
		Character,
		SkillData->Mp[0],
		SkillData->Mp[1],
		SkillSlot->Level // TODO: This level has to be set to the item grade for the astral skill as it can be level 0
	);

	if (Character->Attributes.Values[RUNTIME_ATTRIBUTE_MP_CURRENT] < RequiredMP) {
		// TODO: Send error notification
		goto error;
	}

	RTCharacterAddMP(Runtime, Character, -RequiredMP, false);

	if (SkillData->SkillGroup == RUNTIME_SKILL_GROUP_BUFF) {
		Int32 PacketLength = sizeof(C2S_DATA_SKILL_TO_TARGET) + sizeof(C2S_DATA_SKILL_TO_TARGET_BUFF);
		if (Packet->Length < PacketLength) goto error;

		C2S_DATA_SKILL_TO_TARGET_BUFF* PacketData = (C2S_DATA_SKILL_TO_TARGET_BUFF*)&Packet->Data[0];
		PacketLength += sizeof(C2S_DATA_SKILL_TO_TARGET_BUFF_TARGET) * PacketData->TargetCount + sizeof(C2S_DATA_SKILL_TO_TARGET_BUFF_TAIL);
		if (Packet->Length != PacketLength) goto error;
		if (SkillSlot->Index != PacketData->SlotIndex) goto error;

		C2S_DATA_SKILL_TO_TARGET_BUFF_TARGET* PacketTargetData = (C2S_DATA_SKILL_TO_TARGET_BUFF_TARGET*)(&Packet->Data[0] + sizeof(C2S_DATA_SKILL_TO_TARGET_BUFF));
		C2S_DATA_SKILL_TO_TARGET_BUFF_TAIL* PacketTailData = (C2S_DATA_SKILL_TO_TARGET_BUFF_TAIL*)((UInt8*)PacketTargetData + sizeof(C2S_DATA_SKILL_TO_TARGET_BUFF_TARGET) * PacketData->TargetCount);

		Response->SkillLevel = SkillSlot->Level;
		Response->BuffType = RUNTIME_BUFF_TYPE_SKILL;
		Response->CurrentHP = Character->Attributes.Values[RUNTIME_ATTRIBUTE_HP_CURRENT];
		Response->CurrentMP = Character->Attributes.Values[RUNTIME_ATTRIBUTE_MP_CURRENT];
		Response->CurrentSP = Character->Attributes.Values[RUNTIME_ATTRIBUTE_SP_CURRENT];
		Response->TargetCount = PacketData->TargetCount;

		Notification->SkillLevel = SkillSlot->Level;
		Notification->Unknown1 = 0; // Only takes 0 or 1, moves the slot to second row (penet potion slot)
		Notification->BuffType = RUNTIME_BUFF_TYPE_SKILL;
		Notification->Unknown2 = 0;
		Notification->TargetCount = PacketData->TargetCount;
		Notification->ItemID = 0;
		Notification->EffectorItemID = 0;
		Notification->EffectorItemOptions = 0;
		Notification->SkillTranscendenceLevel = 0;
		Notification->SkillTranscendenceIndex = 0;

		// TODO: Validate Targets

		for (Int32 TargetIndex = 0; TargetIndex < PacketData->TargetCount; TargetIndex += 1) {
			RTEntityID TargetID = PacketTargetData[TargetIndex].TargetID;
			UInt8 TargetIDType = PacketTargetData[TargetIndex].TargetType;

			S2C_DATA_SKILL_TO_TARGET_BUFF_TARGET* ResponseTarget = PacketBufferAppendStruct(Connection->PacketBuffer, S2C_DATA_SKILL_TO_TARGET_BUFF_TARGET);
			ResponseTarget->TargetIndex = TargetID.Serial;
			ResponseTarget->TargetType = TargetIDType;

			S2C_DATA_NFY_SKILL_TO_TARGET_BUFF_TARGET* NotificationTarget = PacketBufferAppendStruct(Socket->PacketBuffer, S2C_DATA_NFY_SKILL_TO_TARGET_BUFF_TARGET);
			NotificationTarget->TargetIndex = TargetID.Serial;
			NotificationTarget->TargetType = TargetIDType;
			
			if (TargetIndex >= SkillData->MaxTarget) continue;

			if (TargetIDType == RUNTIME_ENTITY_TYPE_CHARACTER) {
				RTCharacterRef Target = RTWorldManagerGetCharacter(Runtime->WorldManager, TargetID);
				if (Target) {
					ResponseTarget->TargetIndex = Target->CharacterIndex;
					ResponseTarget->Result = RTCharacterApplyBuff(Runtime, Target, SkillSlot, SkillData);
					NotificationTarget->TargetIndex = ResponseTarget->TargetIndex;
					NotificationTarget->Result = ResponseTarget->Result;
				}
			}
			else if (TargetIDType == RUNTIME_ENTITY_TYPE_MOB) {
				RTWorldContextRef WorldContext = RTRuntimeGetWorldByCharacter(Runtime, Character);
				RTMobRef Target = RTWorldContextGetMob(WorldContext, TargetID);
				if (Target) {
					ResponseTarget->Result = RTMobApplyBuff(Runtime, Target, SkillSlot, SkillData);
					NotificationTarget->Result = ResponseTarget->Result;
				}
			}
			else {
				goto error;
			}
		}
	}
	else {
		goto error;
	}

	S2C_DATA_SKILL_TO_TARGET_BUFF_TAIL* ResponseTail = PacketBufferAppendStruct(Connection->PacketBuffer, S2C_DATA_SKILL_TO_TARGET_BUFF_TAIL);
	S2C_DATA_NFY_SKILL_TO_TARGET_BUFF_TAIL* NotificationTail = PacketBufferAppendStruct(Socket->PacketBuffer, S2C_DATA_NFY_SKILL_TO_TARGET_BUFF_TAIL);

	SocketSend(Socket, Connection, Response);

	BroadcastToWorld(
		Context,
		RTRuntimeGetWorldByCharacter(Runtime, Character),
		kEntityIDNull,
		Character->Movement.PositionCurrent.X,
		Character->Movement.PositionCurrent.Y,
		Notification
	);

	return;

error:
	SocketDisconnect(Socket, Connection);
}

CLIENT_PROCEDURE_BINDING(REMOVE_BUFF) {
	if (!Character) goto error;

	S2C_DATA_REMOVE_BUFF* Response = PacketBufferInit(Connection->PacketBuffer, S2C, REMOVE_BUFF);
	Response->SkillIndex = Packet->SkillIndex;

	if (!RTCharacterRemoveBuff(Runtime, Character, Packet->SkillIndex)) {
		Response->Result = 1;
	}

	SocketSend(Socket, Connection, Response);
	return;

error:
	SocketDisconnect(Socket, Connection);
}
