#include "Character.h"
#include "CharacterAPI.h"
#include "Runtime.h"
#include "NotificationProtocol.h"
#include "NotificationManager.h"

Int32 lua_RTCharacterSetBattleRank(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer BattleRank = luaL_checkinteger(State, 2);
    RTCharacterSetBattleRank(Runtime, Character, (Int32)BattleRank);
    return 0;
}

Int32 lua_RTCharacterSetAllQuestFlags(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    RTCharacterSetAllQuestFlags(Runtime, Character);
    return 0;
}

Int32 lua_RTCharacterAddExp(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    Int64 Exp = luaL_checkinteger(State, 2);
    RTCharacterAddExp(Runtime, Character, Exp);
    return 0;
}

Int32 lua_RTCharacterAddSkillExp(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    Int64 Exp = luaL_checkinteger(State, 2);
    RTCharacterAddSkillExp(Runtime, Character, Exp);
    return 0;
}

Int32 lua_RTCharacterAddWingExp(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    Int64 Exp = luaL_checkinteger(State, 2);
    RTCharacterAddWingExp(Runtime, Character, Exp);
    return 0;
}

Int32 lua_RTCharacterAddHonorPoint(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    Int64 HonorPoint = luaL_checkinteger(State, 2);
    RTCharacterAddHonorPoint(Runtime, Character, HonorPoint);
    return 0;
}

Int32 lua_RTCharacterAddAbilityExp(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    Int64 Exp = luaL_checkinteger(State, 2);
    RTCharacterAddAbilityExp(Runtime, Character, Exp);
    return 0;
}

Int32 lua_RTCharacterAddRage(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Rage = luaL_checkinteger(State, 2);
    RTCharacterAddRage(Runtime, Character, (Int32)Rage);
    return 0;
}

Int32 lua_RTCharacterConsumeRage(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Rage = luaL_checkinteger(State, 2);
    RTCharacterConsumeRage(Runtime, Character, (Int32)Rage);
    return 0;
}

Int32 lua_RTCharacterSetHP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Hp = luaL_checkinteger(State, 2);
    RTCharacterSetHP(Runtime, Character, Hp, false);
    return 0;
}

Int32 lua_RTCharacterAddHP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Hp = luaL_checkinteger(State, 2);
    RTCharacterAddHP(Runtime, Character, Hp, false);
    return 0;
}

Int32 lua_RTCharacterSetMP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Mp = luaL_checkinteger(State, 2);
    RTCharacterSetMP(Runtime, Character, (Int32)Mp, false);
    return 0;
}

Int32 lua_RTCharacterAddMP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Mp = luaL_checkinteger(State, 2);
    RTCharacterAddMP(Runtime, Character, (Int32)Mp, false);
    return 0;
}

Int32 lua_RTCharacterSetSP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Sp = luaL_checkinteger(State, 2);
    RTCharacterSetSP(Runtime, Character, (Int32)Sp);
    return 0;
}

Int32 lua_RTCharacterAddSP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Sp = luaL_checkinteger(State, 2);
    RTCharacterAddSP(Runtime, Character, (Int32)Sp);
    return 0;
}

Int32 lua_RTCharacterSetBP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Bp = luaL_checkinteger(State, 2);
    RTCharacterSetBP(Runtime, Character, (Int32)Bp);
    return 0;
}

Int32 lua_RTCharacterAddBP(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Bp = luaL_checkinteger(State, 2);
    RTCharacterAddBP(Runtime, Character, (Int32)Bp);
    return 0;
}

Int32 lua_RTCharacterApplyDamage(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer Damage = luaL_checkinteger(State, 2);
    RTCharacterApplyDamage(Runtime, Character, kEntityIDNull, (Int32)Damage);
    return 0;
}

Int32 lua_RTCharacterDisconnectWorld(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    NOTIFICATION_DATA_ERROR_CODE* Notification = RTNotificationInit(ERROR_CODE);
    Notification->ErrorCode = 38;
    RTNotificationDispatchToCharacter(Notification, Character);

    return 0;
}

Int32 lua_RTCharacterSpawnObject(lua_State* State) {
    lua_getfield(State, 1, "_Runtime");
    RTRuntimeRef Runtime = (RTRuntimeRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_getfield(State, 1, "_Object");
    RTCharacterRef Character = (RTCharacterRef)lua_touserdata(State, -1);
    lua_pop(State, 1);

    lua_Integer EntityIndex = luaL_checkinteger(State, 2);
    lua_Integer ObjectType = luaL_checkinteger(State, 3);
    lua_Integer EntitySourceIndex = luaL_checkinteger(State, 4);
    lua_Integer PositionX = luaL_checkinteger(State, 5);
    lua_Integer PositionY = luaL_checkinteger(State, 6);
    lua_Integer Hp = luaL_checkinteger(State, 7);
    lua_Integer Nation = luaL_checkinteger(State, 8);
    lua_Integer Status = luaL_checkinteger(State, 9);
    lua_Integer NpcIndex = luaL_checkinteger(State, 10);

    NOTIFICATION_DATA_OBJECTS_SPAWN* Notification = RTNotificationInit(OBJECTS_SPAWN);
    Notification->Count = 1;

    NOTIFICATION_DATA_OBJECTS_SPAWN_INDEX* NotificationObject = RTNotificationAppendStruct(Notification, NOTIFICATION_DATA_OBJECTS_SPAWN_INDEX);
    NotificationObject->Entity.EntityIndex = EntityIndex;
    NotificationObject->Entity.WorldIndex = Character->Movement.WorldContext->WorldData->WorldIndex;
    NotificationObject->Entity.EntityType = RUNTIME_ENTITY_TYPE_OBJECT;
    NotificationObject->ObjectType = ObjectType;
    NotificationObject->EntitySourceIndex = EntitySourceIndex;
    NotificationObject->PositionX = PositionX;
    NotificationObject->PositionY = PositionY;
    NotificationObject->CurrentHP = Hp;
    NotificationObject->MaxHP = Hp;
    NotificationObject->Nation = Nation;
    NotificationObject->Status = Status;
    NotificationObject->CharacterIndex = (UInt32)Character->CharacterIndex;
    NotificationObject->NpcIndex = NpcIndex;
    RTNotificationDispatchToNearby(Notification, Character->Movement.WorldChunk);

    return 0;
}

Void RTScriptBindCharacterAPI(
	RTScriptRef Script
) {
    RTScriptCreateClass(
        Script,
        "Character",
        "SetBattleRank", lua_RTCharacterSetBattleRank,
        "SetAllQuestFlags", lua_RTCharacterSetAllQuestFlags,
        "AddExp", lua_RTCharacterAddExp,
        "AddSkillExp", lua_RTCharacterAddSkillExp,
        "AddWingExp", lua_RTCharacterAddWingExp,
        "AddHonorPoint", lua_RTCharacterAddHonorPoint,
        "AddAbilityExp", lua_RTCharacterAddAbilityExp,
        "AddRage", lua_RTCharacterAddRage,
        "ConsumeRage", lua_RTCharacterConsumeRage,
        "SetHP", lua_RTCharacterSetHP,
        "AddHP", lua_RTCharacterAddHP,
        "SetMP", lua_RTCharacterSetMP,
        "AddMP", lua_RTCharacterAddMP,
        "SetSP", lua_RTCharacterSetSP,
        "AddSP", lua_RTCharacterAddSP,
        "SetBP", lua_RTCharacterSetBP,
        "AddBP", lua_RTCharacterAddBP,
        "ApplyDamage", lua_RTCharacterApplyDamage,
        "DisconnectWorld", lua_RTCharacterDisconnectWorld,
        "SpawnObject", lua_RTCharacterSpawnObject,
        NULL
    );
}
