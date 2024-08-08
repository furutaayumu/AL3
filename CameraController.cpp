#define NOMINMAX
#define NOMINMIN
#include "CameraController.h"
#include "Player.h"
#include <algorithm>

void CameraController::Initialize() { viewProjection_.Initialize();
	
	
}

void CameraController::Update() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetOffset_;

	viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, movableArea_.left);
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, movableArea_.right);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.x, movableArea_.bottom);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.x, movableArea_.top);

	viewProjection_.UpdateMatrix();
}

void CameraController::Reset() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetOffset_;
}
