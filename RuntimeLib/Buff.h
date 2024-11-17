#pragma once

#include "Base.h"
#include "Constants.h"

EXTERN_C_BEGIN

#pragma pack(push, 1)

enum {
    RUNTIME_BUFF_SLOT_TYPE_SKILL,
    RUNTIME_BUFF_SLOT_TYPE_POTION,
    RUNTIME_BUFF_SLOT_TYPE_GM_BUFF,
    RUNTIME_BUFF_SLOT_TYPE_UNKNOWN_1,
    RUNTIME_BUFF_SLOT_TYPE_UNKNOWN_2,
    RUNTIME_BUFF_SLOT_TYPE_FORCE_WING, // BuffSlotIndex 13
    RUNTIME_BUFF_SLOT_TYPE_FIRE_PLACE,
};

struct _RTBuffSlot {
    Int32 SkillIndex;
    Int32 SkillLevel;
    UInt32 Duration;
    UInt8 Unknown1[10];
    Int32 SkillTranscendenceLevel;
    Int32 SkillTranscendenceIndex;
    UInt8 Unknown2[66];
};

struct _RTBuffInfo {
    Int8 SkillBuffCount;
    Int8 PotionBuffCount;
    Int8 GmBuffCount;
    Int8 UnknownBuffCount1;
    Int8 UnknownBuffCount2;
    Int8 ForceWingBuffCount;
    Int8 FirePlaceBuffCount;
};

struct _RTCharacterBuffInfo {
    struct _RTBuffInfo Info;
    struct _RTBuffSlot Slots[RUNTIME_CHARACTER_MAX_BUFF_SLOT_COUNT];
};

#pragma pack(pop)

Void RTCharacterInitializeBuffs(
    RTRuntimeRef Runtime,
    RTCharacterRef Character
);

Void RTCharacterUpdateBuffs(
    RTRuntimeRef Runtime,
    RTCharacterRef Character,
    Bool ForceUpdate
);

RTBuffSlotRef RTCharacterGetBuffSlotBySkillIndex(
    RTRuntimeRef Runtime,
    RTCharacterRef Character,
    Int32 SkillIndex,
    Int32* ResultSlotIndex
);

UInt32 RTCharacterApplyBuff(
    RTRuntimeRef Runtime,
    RTCharacterRef Character,
    RTSkillSlotRef SkillSlot,
    RTCharacterSkillDataRef SkillData,
    Int32 BuffType
);

Void RTCharacterRemoveAllBuffs(
    RTRuntimeRef Runtime,
    RTCharacterRef Character
);

Bool RTCharacterRemoveBuff(
    RTRuntimeRef Runtime,
    RTCharacterRef Character,
    Int32 SkillIndex
);

Void RTMobUpdateBuffs(
    RTRuntimeRef Runtime,
    RTMobRef Mob
);

UInt32 RTMobApplyBuff(
    RTRuntimeRef Runtime,
    RTCharacterRef Character,
    RTMobRef Mob,
    RTSkillSlotRef SkillSlot,
    RTCharacterSkillDataRef SkillData
);

EXTERN_C_END