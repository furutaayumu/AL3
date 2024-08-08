#include <ViewProjection.h>
#include "Player.h"
#include "MathUtilityForText.h"
#pragma once
class Player;

class CameraController {


public:
	struct Rect {
		float left = 0.0f;
		float right = 1.0f;
		float bottom = 0.0f;
		float top = 1.0f;
	};

	void Initialize();

	void Update();

	void setTarget(Player* target) { target_ = target; }

	const ViewProjection& GetViewProjection() const { return viewProjection_; }

	void Reset();

	void setMovableAre(Rect area) { movableArea_ = area; }

	private:
	Rect movableArea_ = {0, 100, 0, 100};

	ViewProjection viewProjection_;
	Player* target_ = nullptr;
	Vector3 targetOffset_ = {0, 0, -15.0f};

};
