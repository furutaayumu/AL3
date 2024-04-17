#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"


GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete sprite_; 
	delete model_;
	delete debugCamera_;
}

void GameScene::Initialize() {
	//スプライト
	textureHandle_ = TextureManager::Load("GLHK20zbYAAu6pb.jpg");
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	//3dモデル
	model_ = Model::Create();
	//ライン描画
	PrimitiveDrawer::GetInstance()->SetViewProjection(&viewProjection_);
	worldTransform_.Initialize();
	viewProjection_.Initialize();

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	debugCamera_ = new DebugCamera(1280, 720);
}

void GameScene::Update() {
//移動
	Vector2 position = sprite_->GetPosition();
	position.x += 2.0f;
	position.y += 1.0f;
	sprite_->SetPosition(position);

	ImGui::Begin("debug1");
	ImGui::Text("kamatatarou %d.%d.%d", 2050, 12, 31);
	ImGui::InputFloat("InputFloat3", inputFloat3);
	ImGui::SliderFloat("SliderFloat3", inputFloat3, 0.0f, 1.0f);
	ImGui::End();
	debugCamera_->Update();
}

void GameScene::Draw() {

	PrimitiveDrawer::GetInstance()->DrawLine3d({0, 0, 0}, {0, 10, 0}, {1.0f, 0.0f, 0.0f, 1.0f});

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//model_->Draw(worldTransform_, viewProjection_, textureHandle_);
	model_->Draw(worldTransform_, debugCamera_->GetViewProjection(), textureHandle_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}
