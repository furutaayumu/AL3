#include "Tenkyu.h"
#include <cassert>

void Tenkyu::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection) { 
	assert(model);
	viewProjection_ = viewProjection;
	TextureHandle_ = textureHandle;
	model_ = model;
	worldTransform_.Initialize();
}

void Tenkyu::Updata() { worldTransform_.TransferMatrix(); }

void Tenkyu::Draw() { model_->Draw(worldTransform_, *viewProjection_); }