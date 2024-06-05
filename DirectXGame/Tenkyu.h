#pragma once
#include <Model.h>
#include <worldtransform.h>
class Tenkyu {
public:
	void Initialize(Model* model,uint32_t textureHandle,ViewProjection* viewProjection);
	void Updata();
	void Draw();

private:
	ViewProjection* viewProjection_ = nullptr;
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t TextureHandle_ = 0u;
};
