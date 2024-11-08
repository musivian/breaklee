RUNTIME_DATA_FILE_BEGIN(ForceWing.enc)

RUNTIME_DATA_TYPE_BEGIN(ForceWingActivation, "ForceWing.ForceWing_ActiveLV.Wing_Min_Lv")
	RUNTIME_DATA_PROPERTY(Int32, MinLevel, "Min_lv")
RUNTIME_DATA_TYPE_END(ForceWingActivation)
RUNTIME_DATA_TYPE_INDEX_SINGLE(ForceWingActivation)

RUNTIME_DATA_TYPE_BEGIN(ForceWingGradeLimit, "ForceWing.ForceWing_Limit_Grade.Wing_Limit_Grade")
	RUNTIME_DATA_PROPERTY(Int32, MaxGrade, "Limit_Grade")
RUNTIME_DATA_TYPE_END(ForceWingGradeLimit)
RUNTIME_DATA_TYPE_INDEX_SINGLE(ForceWingGradeLimit)

RUNTIME_DATA_TYPE_BEGIN(ForceWingGradeInfo, "ForceWing.ForceWing_Grade.Wing_Info")
	RUNTIME_DATA_PROPERTY(Int32, Grade, "Grade")
	RUNTIME_DATA_PROPERTY(Int32, MinLevel, "Min_lv")
	RUNTIME_DATA_PROPERTY(Int32, MaxLevel, "Max_lv")
	RUNTIME_DATA_PROPERTY(UInt64, MaterialItemID, "Material_Item")
	RUNTIME_DATA_PROPERTY(UInt64, WingItemID, "Wing_Id")
RUNTIME_DATA_TYPE_END(ForceWingGradeInfo)
RUNTIME_DATA_TYPE_INDEX(ForceWingGradeInfo, Int32, Grade)

RUNTIME_DATA_TYPE_BEGIN(ForceWingGrade, "ForceWing.ForceWing_Grow.Wing_Grade")
	RUNTIME_DATA_PROPERTY(Int32, Grade, "grade")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingGradeLevel, "Wing_grow")
		RUNTIME_DATA_PROPERTY(Int32, Level, "Level")
		RUNTIME_DATA_PROPERTY(UInt64, Exp, "Exp")
		RUNTIME_DATA_PROPERTY(Int32, RequiredMaterialItemCount, "Item_need")
		RUNTIME_DATA_PROPERTY(UInt64, ExtraMaterialItemID, "Material_Item2")
		RUNTIME_DATA_PROPERTY(Int32, RequiredExtraMaterialItemCount, "Item2_need")
	RUNTIME_DATA_TYPE_END_CHILD(ForceWingGradeLevel)
RUNTIME_DATA_TYPE_END(ForceWingGrade)
RUNTIME_DATA_TYPE_INDEX(ForceWingGrade, Int32, Grade)
RUNTIME_DATA_TYPE_INDEX_CHILD(ForceWingGrade, ForceWingGradeLevel, Int32, Level)

#define RUNTIME_DATA_MAX_FORCE_WING_UPGRADE_MATERIAL_COUNT 2

RUNTIME_DATA_TYPE_BEGIN(ForceWingUpgrade, "ForceWing.ForceWing_Upgrade.Wing_Upgrade")
	RUNTIME_DATA_PROPERTY(Int32, Grade, "Grade")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingUpgradeMaterial, "Material")
		RUNTIME_DATA_PROPERTY(Int32, Order, "Order")
		RUNTIME_DATA_PROPERTY(UInt64, MaterialItemID, "Item")
		RUNTIME_DATA_PROPERTY(Int32, RequiredMaterialItemCount, "Count")
	RUNTIME_DATA_TYPE_END_CHILD(ForceWingUpgradeMaterial)
RUNTIME_DATA_TYPE_END(ForceWingUpgrade)
RUNTIME_DATA_TYPE_INDEX(ForceWingUpgrade, Int32, Grade)

RUNTIME_DATA_TYPE_BEGIN(ForceWingTrainingAbility, "ForceWing.Training_Ability.ability_slot")
	RUNTIME_DATA_PROPERTY(Int32, Slot, "Slot")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingTrainingAbilityDetail, "detail")
		RUNTIME_DATA_PROPERTY(Int32, TrainingIndex, "Training_ID")
		RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingTrainingAbilityDetailInfo, "Training_Info")
			RUNTIME_DATA_PROPERTY(Int32, TrainingLevel, "T_Lv")
			RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "T_ForceCode")
			RUNTIME_DATA_PROPERTY(Int32, ForceEffectValue, "T_FcValue")
			RUNTIME_DATA_PROPERTY(Int32, ForceEffectValueType, "Value_Type")
			RUNTIME_DATA_PROPERTY(Int32, RequiredTrainingPointCount, "T_Point")
		RUNTIME_DATA_TYPE_END_CHILD(ForceWingTrainingAbilityDetailInfo)
	RUNTIME_DATA_TYPE_END_CHILD(ForceWingTrainingAbilityDetail)
RUNTIME_DATA_TYPE_END(ForceWingTrainingAbility)
RUNTIME_DATA_TYPE_INDEX(ForceWingTrainingAbility, Int32, Slot)
RUNTIME_DATA_TYPE_INDEX_CHILD(ForceWingTrainingAbility, ForceWingTrainingAbilityDetail, Int32, TrainingIndex)
RUNTIME_DATA_TYPE_INDEX_CHILD(ForceWingTrainingAbilityDetail, ForceWingTrainingAbilityDetailInfo, Int32, TrainingLevel)

RUNTIME_DATA_TYPE_BEGIN(ForceWingTrainingGrade, "ForceWing.Training_Grade.slot_info")
	RUNTIME_DATA_PROPERTY(Int32, Slot, "Slot")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingTrainingGradeInfo, "Info")
		RUNTIME_DATA_PROPERTY(Int32, TrainingIndex, "T_Id")
		RUNTIME_DATA_PROPERTY(Int32, RequiredGrade, "Grade")
		RUNTIME_DATA_PROPERTY(Int32, RequiredLevel, "Level")
	RUNTIME_DATA_TYPE_END_CHILD(ForceWingTrainingGradeInfo)
RUNTIME_DATA_TYPE_END(ForceWingTrainingGrade)
RUNTIME_DATA_TYPE_INDEX(ForceWingTrainingGrade, Int32, Slot)
RUNTIME_DATA_TYPE_INDEX_CHILD(ForceWingTrainingGrade, ForceWingTrainingGradeInfo, Int32, TrainingIndex)

RUNTIME_DATA_TYPE_BEGIN(ForceWingSkill, "ForceWing.ForceWing_Skill.Slot_Info")
	RUNTIME_DATA_PROPERTY(Int32, SlotIndex, "Slot")
	RUNTIME_DATA_PROPERTY(Int32, MaterialItemID, "Meterial_Id")
	RUNTIME_DATA_PROPERTY(Int32, MaterialItemCount, "ItemCount")
	RUNTIME_DATA_PROPERTY(Int32, ForceCodeGroup1, "W_ForceCode1")
	RUNTIME_DATA_PROPERTY(Int32, ForceCodeGroup2, "W_ForceCode2")
	RUNTIME_DATA_PROPERTY(Int32, Grade, "Grade")
	RUNTIME_DATA_PROPERTY(Int32, Type, "W_Type")
RUNTIME_DATA_TYPE_END(ForceWingSkill)
RUNTIME_DATA_TYPE_INDEX(ForceWingSkill, Int32, Grade)
RUNTIME_DATA_TYPE_INDEX_SUFFIXED(ForceWingSkill, BySlotIndex, Int32, SlotIndex)

RUNTIME_DATA_TYPE_BEGIN(ForceWingSkillGroup, "ForceWing.ForceWing_FC.FC_Info")
	RUNTIME_DATA_PROPERTY(Int32, Group, "Group")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingSkillGroupDetail, "detail")
		RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "FC_ID")
		RUNTIME_DATA_PROPERTY(Int32, ValueType, "Value_Type")
		RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceWingSkillGroupDetailOption, "FC")
			RUNTIME_DATA_PROPERTY(Int32, Grade, "W_Grade")
			RUNTIME_DATA_PROPERTY(Int32, ForceEffectGrade, "W_Order")
			RUNTIME_DATA_PROPERTY(Int32, Value, "Value")
			RUNTIME_DATA_PROPERTY(Int32, Rate, "W_Rate")
		RUNTIME_DATA_TYPE_END_CHILD(ForceWingSkillGroupDetailOption)
	RUNTIME_DATA_TYPE_END_CHILD(ForceWingSkillGroupDetail)
RUNTIME_DATA_TYPE_END(ForceWingSkillGroup)
RUNTIME_DATA_TYPE_INDEX(ForceWingSkillGroup, Int32, Group)

RUNTIME_DATA_FILE_END