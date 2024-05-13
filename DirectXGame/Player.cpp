#include "Player.h"
#include <cassert>

//初期化
void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection) { 
	viewProjection_ = viewProjection;
	assert(model);
	model_ = model;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize();
}

void Player::Update() { worldTransform_.TransferMatrix(); }

void Player::Draw() { model_->Draw(worldTransform_, *viewProjection_, textureHandle_); }
