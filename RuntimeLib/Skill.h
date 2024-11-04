#pragma once

#include "Base.h"
#include "Constants.h"

EXTERN_C_BEGIN

#pragma pack(push, 1)

enum {
	RUNTIME_SPECIAL_SKILL_SLOT_ASTRAL_SKILL			= 67,
	RUNTIME_SPECIAL_SKILL_SLOT_ASTRAL_BIKE			= 68,
	RUNTIME_SPECIAL_SKILL_SLOT_ASTRAL_BOARD			= 69,
	RUNTIME_SPECIAL_SKILL_SLOT_AURA_MODE_1			= 70,
	RUNTIME_SPECIAL_SKILL_SLOT_COMBO				= 71,
	RUNTIME_SPECIAL_SKILL_SLOT_BATTLE_MODE_1		= 72,
	RUNTIME_SPECIAL_SKILL_SLOT_BATTLE_MODE_2		= 73,
	RUNTIME_SPECIAL_SKILL_SLOT_BATTLE_MODE_3		= 74,

	RUNTIME_SPECIAL_SKILL_SLOT_COMBO_BOARD			= 102,
	RUNTIME_SPECIAL_SKILL_SLOT_COMBO_BIKE			= 103,

	RUNTIME_SPECIAL_SKILL_SLOT_AURA_MODE_2			= 111,
	RUNTIME_SPECIAL_SKILL_SLOT_AURA_MODE_3			= 112,
	RUNTIME_SPECIAL_SKILL_SLOT_AURA_MODE_4			= 113,
	RUNTIME_SPECIAL_SKILL_SLOT_AURA_MODE_5			= 114,

	RUNTIME_SPECIAL_SKILL_SLOT_FORCE_WING_1			= 115,
	RUNTIME_SPECIAL_SKILL_SLOT_FORCE_WING_2			= 116,
	RUNTIME_SPECIAL_SKILL_SLOT_FORCE_WING_3			= 117,
};

enum {
	RUNTIME_SKILL_TYPE_NONE,
	RUNTIME_SKILL_TYPE_SWORD,
	RUNTIME_SKILL_TYPE_MAGIC,
	RUNTIME_SKILL_TYPE_BATTLE_MODE,
	RUNTIME_SKILL_TYPE_PASSIVE,
	RUNTIME_SKILL_TYPE_COMBO,
	RUNTIME_SKILL_TYPE_CUSTOM,
	RUNTIME_SKILL_TYPE_ACTIVE,
	RUNTIME_SKILL_TYPE_BASIC,
	RUNTIME_SKILL_TYPE_TRAIN_BY_CURRENCY,
	RUNTIME_SKILL_TYPE_TRAIN_BY_POINT,
	RUNTIME_SKILL_TYPE_TRAIN_BY_QUEST,
	RUNTIME_SKILL_TYPE_TRAIN_BY_ALL,
};

enum {
	RUNTIME_SKILL_TARGET_NONE		= 0,
	RUNTIME_SKILL_TARGET_MOB		= 1 << 0,
	RUNTIME_SKILL_TARGET_CHARACTER	= 1 << 1,
	RUNTIME_SKILL_TARGET_SELF		= 1 << 2,
	RUNTIME_SKILL_TARGET_NATION		= 1 << 3,
	RUNTIME_SKILL_TARGET_PARTY		= 1 << 4,
};

enum {
	RUNTIME_SKILL_DAMAGE_TYPE_NONE,
	RUNTIME_SKILL_DAMAGE_TYPE_SWORD,
	RUNTIME_SKILL_DAMAGE_TYPE_MAGIC,
};

enum {
	RUNTIME_SKILL_GROUP_PASSIVE = 0,
	RUNTIME_SKILL_GROUP_ATTACK = 1,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_MOVEMENT = 5,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_BUFF = 24,
	RUNTIME_SKILL_GROUP_DEBUFF = 25,
	RUNTIME_SKILL_GROUP_HEAL = 26,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_ASTRAL = 31,
	RUNTIME_SKILL_GROUP_BATTLE_MODE = 32,
	RUNTIME_SKILL_GROUP_WING = 33,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_VEHICLE = 38,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_COMBO = 40,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_UNKNOWN_42 = 42,
	RUNTIME_SKILL_GROUP_TOTEM = 43,
	RUNTIME_SKILL_GROUP_AGGRO = 44,
	RUNTIME_SKILL_GROUP_FIREPLACE = 45,
	/* RESERVED NOT IN USE */
	RUNTIME_SKILL_GROUP_COUNT = 50
};

enum {
	RUNTIME_SKILL_INTENSITY_ASTRAL_WEAPON = 2,
	RUNTIME_SKILL_INTENSITY_ASTRAL_VEHICLE = 3,
	RUNTIME_SKILL_INTENSITY_ASTRAL_AURA = 4,
};

enum {
	RUNTIME_SKILL_RESULT_CRITICAL = 1,
	RUNTIME_SKILL_RESULT_NORMAL,
	RUNTIME_SKILL_RESULT_MISS,
	RUNTIME_SKILL_RESULT_MOB_IS_DEAD,
	RUNTIME_SKILL_RESULT_BUFF_SUCCESS,
	RUNTIME_SKILL_RESULT_BUFF_EXISTS = 0x10,
	RUNTIME_SKILL_RESULT_BUFF_EXISTS_CRITICAL = RUNTIME_SKILL_RESULT_BUFF_EXISTS | RUNTIME_SKILL_RESULT_CRITICAL,
	RUNTIME_SKILL_RESULT_BUFF_EXISTS_NORMAL = RUNTIME_SKILL_RESULT_BUFF_EXISTS | RUNTIME_SKILL_RESULT_NORMAL,
	RUNTIME_SKILL_RESULT_BUFF_EXISTS_MISS = RUNTIME_SKILL_RESULT_BUFF_EXISTS | RUNTIME_SKILL_RESULT_MISS,
	RUNTIME_SKILL_RESULT_ENCHANT,
	RUNTIME_SKILL_RESULT_STUN_FAILURE,
	RUNTIME_SKILL_RESULT_FULL_FAILURE,
	RUNTIME_SKILL_RESULT_DIFFERENT_WORLD,
	RUNTIME_SKILL_RESULT_TARGET_ERROR,
	RUNTIME_SKILL_RESULT_DAMAGE_ABSORBED,
};

enum {
	RUNTIME_SKILL_RANGE_TYPE_RECT,
	RUNTIME_SKILL_RANGE_TYPE_LINE,
};

enum {
	RUNTIME_BUFF_TYPE_SKILL = 0,

	RUNTIME_BUFF_TYPE_GM_BLESSING = 3,

	RUNTIME_BUFF_TYPE_FORCE_WING_ARRIVAL_SKILL = 13,
};

struct _RTSkillLevelData {
	Int32 Index;
	Int32 SkillID;
	Int32 SkillRank;
	Int32 SkillRankPoint;
	Int32 StartLevel;
	Int32 EndLevel;
	Int32 SkillPoint;
	Int32 TrainPrice;
	Int32 UntrainPrice;
	Int32 StyleMastery;
	Int32 BattleStyles[RUNTIME_DATA_CHARACTER_BATTLE_STYLE_INDEX_MAX];
};

struct _RTSkillValueData {
	Int32 ForceEffectIndex;
	Int32 ForceEffectValue[3];
	Int32 Power[2];
	Int32 Duration[2];
	Int32 Type;
	Int32 ValueType;
	Int32 CheckReadiness;
};

struct _RTCharacterSkillValue {
	Int32 SwordSkillAmp;
	Int32 MagicSkillAmp;
	Int32 Attack;
	Int32 MagicAttack;
	Int32 AttackRate;
	Int32 Penetration;
	Int32 CriticalDamage;
	Int32 Mp;
};
typedef struct _RTCharacterSkillValue RTCharacterSkillValue;

struct _RTCharacterSkillData {
	Int32 SkillID;
	Int32 SkillType;
	Int32 SkillGroup;
	Int32 Duration[2];
	Int32 Multi;
	Int32 Intensity;
	Int32 Element;
	Int32 Target;
	Int32 MaxTarget;
	Int32 Reach;
	Int32 MReach;
	Int32 Range;
	Int32 RangeType;
	Int32 GripCalc;
	Int32 AniCode;
	Int32 FxCodeOn;
	Int32 FxCodeKeep;
	Int32 FrameTerm;
	Int32 BlendLimit;
	Int32 HitFrame;
	Int32 FiringFrame;
	Int32 AniFrame;
	Int32 VisualType;
	Int32 ConditionTwoHand;
	Int32 ConditionDual;
	Int32 ConditionOneHand;
	Int32 ConditionBracer;
	Int32 ConditionOneChakram;
	Int32 ConditionTwoChakram;
	Int32 ConditionExclusive;
	Int32 ConditionUseCase;
	Int32 SkillExp1;
	Int32 SkillExp2;
	Int32 SAmp[2];
	Int32 Atk[3];
	Int32 SHit[2];
	Int32 SPenet[2];
	Int32 CritDmg[2];
	Int32 DamageType;
	Int32 CooltimeID;
	Int32 RageValue;
	Int32 Mp[2];
	Int32 Sp;
	Int32 SkillValueCount;
	Int32 SkillLevelCount;
	struct _RTSkillValueData SkillValues[RUNTIME_MEMORY_MAX_SKILL_VALUE_DATA_COUNT];
	struct _RTSkillLevelData SkillLevels[RUNTIME_MEMORY_MAX_SKILL_LEVEL_DATA_COUNT];
};

#pragma pack(pop)

Int32 RTCharacterSkillDataGetSkillType(
	RTCharacterSkillDataRef Skill,
	Bool IsPassiveSword,
	Bool IsPassiveMagic
);

Int32 RTCharacterSkillDataGetSkillExp(
	RTCharacterSkillDataRef Skill,
	Int32 SkillResult
);

Int32 RTCalculateDistance(
	Int32 X1,
	Int32 Y1,
	Int32 X2,
	Int32 Y2
);

Bool RTCheckSkillTargetDistance(
	RTCharacterSkillDataRef Skill,
	Float32 Radius,
	Int32 Scale,
	Int32 SourceX,
	Int32 SourceY,
	Int32 TargetX,
	Int32 TargetY
);

Int32 RTCalculateSkillSlopeValue(
	Int32 CoefficientA,
	Int32 CoefficientB,
	Int32 Level
);

RTCharacterSkillValue RTCalculateSkillValue(
	RTCharacterSkillDataRef SkillData,
	Int32 Level,
	Int32 Rage
);

UInt32 RTCalculateSkillDuration(
	RTCharacterSkillDataRef SkillData,
	Int32 SkillLevel,
	Int32 BattleRank
);

Int32 RTCharacterApplyForceEffectBuff(
    RTRuntimeRef Runtime,
	RTCharacterRef Character,
	Int32 ForceEffectIndex,
	Int32 ForceEffectValue,
	Int32 Duration,
	Int32 Cooldown
);

Int32 RTCharacterGetBattleModeSkillIndex(
	RTRuntimeRef Runtime,
	RTCharacterRef Character,
	Int32 BattleModeIndex
);

Int32 RTCharacterGetAuraModeSkillIndex(
	RTRuntimeRef Runtime,
	RTCharacterRef Character,
	Int32 AuraModeIndex
);

Int32 RTCharacterGetAuraModeIndexForSkillIndex(
	RTRuntimeRef Runtime,
	RTCharacterRef Character,
	Int32 SkillIndex
);

EXTERN_C_END
