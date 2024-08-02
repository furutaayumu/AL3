#include "Model.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"
#pragma once
class Player {
public:
	void Initialize(Model* model, uint32_t textureHandle,ViewProjection* viewProjection,const Vector3& potision);

	void Update();

	void Draw();

private:
	enum class LRDirection {
		kRight,
		kLeft,
	};

	LRDirection lrDirection_ = LRDirection::kRight;

	WorldTransform worldTransform_;
	ViewProjection* viewProjection_ = nullptr;

	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;

	Vector3 velocity_ = {};

	bool onGround_ = true;

	float turnFirstRotationY_ = 0.0f;
	float turnTimer_ = 0.0f;

	static inline const float kTimeTurn = 0.3f;

	static inline const float kAcceleration = 0.1f;
	static inline const float kAttenuation = 0.1f;
	static inline const float kLimitRunSpeed = 0.1f;

	static inline const float kGravityAcceleration = 0.05f;
	static inline const float kLimitFallSpeed = 0.5f;
	static inline const float kJumpAcceleration = 0.5f;
};
