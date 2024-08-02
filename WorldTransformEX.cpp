#include "WorldTransform.h"
#include"MathUtilityForText.h"

void WorldTransform::UpdataMatrix() {
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	TransferMatrix();
}

