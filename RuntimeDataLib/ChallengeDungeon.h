RUNTIME_DATA_FILE_BEGIN(ChallengeDungeon.enc)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonSchedule, "cabal.Schedule.Season_Time")
	RUNTIME_DATA_PROPERTY_ARRAY(Int32, SeasonTime, "Season_Time", 3, ':')
RUNTIME_DATA_TYPE_END(ChallengeDungeonSchedule)
RUNTIME_DATA_TYPE_INDEX_SINGLE(ChallengeDungeonSchedule)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonMaxStage, "cabal.Max_stage.Max_stage")
	RUNTIME_DATA_PROPERTY(Int32, MaxStage, "Max_stage")
RUNTIME_DATA_TYPE_END(ChallengeDungeonMaxStage)
RUNTIME_DATA_TYPE_INDEX_SINGLE(ChallengeDungeonMaxStage)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonStage, "cabal.Stage.Stage")
	RUNTIME_DATA_PROPERTY(Int32, Stage, "Stage")
	RUNTIME_DATA_PROPERTY(Int32, StageType, "Stage_type")
	RUNTIME_DATA_PROPERTY(Int32, MMapIndex, "MmapIdx")
	RUNTIME_DATA_PROPERTY_ARRAY(Char, MapName, "Map_name", MAX_PATH, '\0')
	RUNTIME_DATA_PROPERTY(Int32, MissionTime, "MissionTime")
RUNTIME_DATA_TYPE_END(ChallengeDungeonStage)
RUNTIME_DATA_TYPE_INDEX(ChallengeDungeonStage, Int32, Stage)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonScore, "cabal.Score.Score")
	RUNTIME_DATA_PROPERTY(Int32, AttackScore, "AttackScore")
	RUNTIME_DATA_PROPERTY(Int32, TimeScore, "TimeScore")
	RUNTIME_DATA_PROPERTY(Int32, ClearScoreNormal, "ClearScoreNormal")
	RUNTIME_DATA_PROPERTY(Int32, ClearScoreBoss, "ClearScoreBoss")
	RUNTIME_DATA_PROPERTY(Int32, ClearScoreSurvive, "ClearScoreSurvive")
RUNTIME_DATA_TYPE_END(ChallengeDungeonScore)
RUNTIME_DATA_TYPE_INDEX_SINGLE(ChallengeDungeonScore)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonClearBuff, "cabal.ClearBuff.ClearBuff")
	RUNTIME_DATA_PROPERTY(Int32, BuffIndex, "Buff_Index")
	RUNTIME_DATA_PROPERTY(Int32, BuffType, "Buff_Type")
	RUNTIME_DATA_PROPERTY(Int32, BuffTarget, "Buff_Taget")
	RUNTIME_DATA_PROPERTY(Int32, BuffGrade, "Buff_Grade")
	RUNTIME_DATA_PROPERTY(Int32, Order, "Order")
	RUNTIME_DATA_PROPERTY(Int32, ForceCode, "Forcecode")
	RUNTIME_DATA_PROPERTY(Int32, ForceValue, "Value")
	RUNTIME_DATA_PROPERTY(Int32, ForveValueType, "Value_type")
RUNTIME_DATA_TYPE_END(ChallengeDungeonClearBuff)
RUNTIME_DATA_TYPE_INDEX(ChallengeDungeonClearBuff, Int32, BuffIndex)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonRewardToken, "cabal.RewardToken.RewardToken")
	RUNTIME_DATA_PROPERTY(Int32, Score, "Score")
	RUNTIME_DATA_PROPERTY(UInt64, ItemIndex, "ItemIndex")
	RUNTIME_DATA_PROPERTY(UInt64, ItemOptions, "ItemOption")
RUNTIME_DATA_TYPE_END(ChallengeDungeonRewardToken)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonRewardBuff, "cabal.RewardBuff.RewardBuff")
	RUNTIME_DATA_PROPERTY(Int32, SkillIndex, "BuffSkill")
	RUNTIME_DATA_PROPERTY(UInt64, SkillLevel, "SkillLevel")
RUNTIME_DATA_TYPE_END(ChallengeDungeonRewardBuff)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonSeasonReward, "cabal.SeasonReward.SeasonReward")
	RUNTIME_DATA_PROPERTY(Int32, Ranking, "Ranking")
	RUNTIME_DATA_PROPERTY(Int32, TitleIndex, "TitleID")
	RUNTIME_DATA_PROPERTY(Int32, DurationIndex, "DurationIdx")
RUNTIME_DATA_TYPE_END(ChallengeDungeonSeasonReward)

RUNTIME_DATA_TYPE_BEGIN(ChallengeDungeonExceptionItem, "cabal.Exception_Item.Exception_Item")
	RUNTIME_DATA_PROPERTY(UInt64, ItemIndex, "ItemIdx")
RUNTIME_DATA_TYPE_END(ChallengeDungeonExceptionItem)

RUNTIME_DATA_FILE_END
