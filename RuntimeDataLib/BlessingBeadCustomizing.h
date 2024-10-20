RUNTIME_DATA_FILE_BEGIN(blessingbeadcustomizing.enc)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadCustomizingBase, "blessingbead_customizing.base_cost.bb_customizing")
	RUNTIME_DATA_PROPERTY(Int32, PerCost, "per_cost")
	RUNTIME_DATA_PROPERTY(Int32, Exp, "exp")
	RUNTIME_DATA_PROPERTY(Int32, SkillExp, "sklexp")
	RUNTIME_DATA_PROPERTY(Int32, BoxDrop, "boxDrop")
	RUNTIME_DATA_PROPERTY(Int32, BombAlz, "bombalz")
	RUNTIME_DATA_PROPERTY(Int32, PetExp, "petexp")
	RUNTIME_DATA_PROPERTY(Int32, Axp, "axp")
	RUNTIME_DATA_PROPERTY(Int32, Superior, "superior")
	RUNTIME_DATA_PROPERTY(Int32, Plus, "plus")
	RUNTIME_DATA_PROPERTY(Int32, Supreme, "supreme")
	RUNTIME_DATA_PROPERTY(Int32, Ultimate, "ultimate")
RUNTIME_DATA_TYPE_END(BlessingBeadCustomizingBase)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadDiscount, "blessingbead_customizing.base_discount.BlessingBeadbase_Discount.base_Discount")
	RUNTIME_DATA_PROPERTY(Int32, Fix, "Fix")
	RUNTIME_DATA_PROPERTY(Int32, Discount, "Discount")
RUNTIME_DATA_TYPE_END(BlessingBeadDiscount)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadLimit, "blessingbead_customizing.limit_value.BlessingBead_limit.Limit_value")
	RUNTIME_DATA_PROPERTY(Int32, TypeCode, "type_code")
	RUNTIME_DATA_PROPERTY(Int32, Exp, "exp")
	RUNTIME_DATA_PROPERTY(Int32, SkillExp, "sklexp")
	RUNTIME_DATA_PROPERTY(Int32, BoxDrop, "boxDrop")
	RUNTIME_DATA_PROPERTY(Int32, BombAlz, "bombalz")
	RUNTIME_DATA_PROPERTY(Int32, PetExp, "petexp")
	RUNTIME_DATA_PROPERTY(Int32, Axp, "axp")
	RUNTIME_DATA_PROPERTY(Int32, Superior, "superior")
	RUNTIME_DATA_PROPERTY(Int32, Plus, "plus")
	RUNTIME_DATA_PROPERTY(Int32, Supreme, "supreme")
	RUNTIME_DATA_PROPERTY(Int32, Ultimate, "ultimate")
RUNTIME_DATA_TYPE_END(BlessingBeadLimit)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadDurationCost, "blessingbead_customizing.duration_cost.bead_duration.duration_value")
	RUNTIME_DATA_PROPERTY(Int32, DurationIndex, "duration_idx")
	RUNTIME_DATA_PROPERTY(Int32, Exp, "exp")
	RUNTIME_DATA_PROPERTY(Int32, SkillExp, "sklexp")
	RUNTIME_DATA_PROPERTY(Int32, BoxDrop, "boxDrop")
	RUNTIME_DATA_PROPERTY(Int32, BombAlz, "bombalz")
	RUNTIME_DATA_PROPERTY(Int32, PetExp, "petexp")
	RUNTIME_DATA_PROPERTY(Int32, Axp, "axp")
	RUNTIME_DATA_PROPERTY(Int32, Superior, "superior")
	RUNTIME_DATA_PROPERTY(Int32, Plus, "plus")
	RUNTIME_DATA_PROPERTY(Int32, Supreme, "supreme")
	RUNTIME_DATA_PROPERTY(Int32, Ultimate, "ultimate")
RUNTIME_DATA_TYPE_END(BlessingBeadDurationCost)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadDurationDiscount, "blessingbead_customizing.duration_discount.bead_duration_discount.duration_value")
	RUNTIME_DATA_PROPERTY(Int32, DurationIndex, "duration_idx")
	RUNTIME_DATA_PROPERTY(Int32, Exp, "exp")
	RUNTIME_DATA_PROPERTY(Int32, SkillExp, "sklexp")
	RUNTIME_DATA_PROPERTY(Int32, BoxDrop, "boxDrop")
	RUNTIME_DATA_PROPERTY(Int32, BombAlz, "bombalz")
	RUNTIME_DATA_PROPERTY(Int32, PetExp, "petexp")
	RUNTIME_DATA_PROPERTY(Int32, Axp, "axp")
	RUNTIME_DATA_PROPERTY(Int32, Superior, "superior")
	RUNTIME_DATA_PROPERTY(Int32, Plus, "plus")
	RUNTIME_DATA_PROPERTY(Int32, Supreme, "supreme")
	RUNTIME_DATA_PROPERTY(Int32, Ultimate, "ultimate")
RUNTIME_DATA_TYPE_END(BlessingBeadDurationDiscount)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadUsedBead, "blessingbead_customizing.used_bead.Used_BlessingBead.customizing")
	RUNTIME_DATA_PROPERTY(Int32, BBCIndex, "bbc_idx")
	RUNTIME_DATA_PROPERTY(Int32, BeadIndex, "bead_index")
	RUNTIME_DATA_PROPERTY(Int32, BeadPer, "bead_per")
RUNTIME_DATA_TYPE_END(BlessingBeadUsedBead)

RUNTIME_DATA_TYPE_BEGIN(BlessingBeadTotalDiscount, "blessingbead_customizing.total_discount.BlessingBeadTotal_Discount.BlessingBeadCustomizing")
	RUNTIME_DATA_PROPERTY(Int32, DiscountIndex, "discountidx")
	RUNTIME_DATA_PROPERTY(Int32, TypeCount, "type_count")
	RUNTIME_DATA_PROPERTY(Int32, DiscountRate, "discount_rate")
RUNTIME_DATA_TYPE_END(BlessingBeadUsedBead)

RUNTIME_DATA_FILE_END