#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include <vector>
#include "DebugCamera.h"
#include "Tenkyu.h"
#include "MapChipField.h"
#include "CameraController.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	void GenerateBlocks();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summar

//テクスチャ
	uint32_t textureHandle_ = 0;
	
	Model* model_ = nullptr;
	Model* block_ = nullptr; 
	ViewProjection viewProjection_;

	Player* player_ = nullptr;

	Tenkyu* tenkyu_ = nullptr;
	Model* modelSkydome_ = nullptr;
	
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	//デバックカメラ
	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;

	CameraController* cameraController_ = nullptr;

	//マップチップ
	MapChipField* mapChipField_;
	

};
