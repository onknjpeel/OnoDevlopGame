#include "KamataEngine.h"
#include <cassert>
#include "MyMath.h"

void KamataEngine::WorldTransform::UpdateMatrix() {
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);

	if (parent_) {
		matWorld_ *= parent_->matWorld_;
	}

	TransferMatrix();
}