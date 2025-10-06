#include "GameScene.h"

using namespace MathUtility;

GameScene::~GameScene() {}

void GameScene::Initialize() {
	dxc_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	weaponNumber = 0;
}

void GameScene::Update() {
	if (cursor.TriggerLeft()) {
		isFinished_ = true;
	}
	if (cursor.TriggerRight()) {
		weaponNumber++;
		if (weaponNumber >= 4) {
			weaponNumber = 0;
		}
	}
	cursor.Update();
}

void GameScene::Draw() {
	// 描画処理//
	// 背景
	Sprite::PreDraw();

	Sprite::PostDraw();

	// 3Dモデル
	Model::PreDraw();

	Model::PostDraw();

	// 前景
	Sprite::PreDraw();

	Sprite::PostDraw();

	ImGuiManager* imgui_ = ImGuiManager::GetInstance();
	imgui_->Begin();
	ImGui::Begin("weaponNum");
	ImGui::InputInt("num", &weaponNumber);
	ImGui::End();
	imgui_->End();

	imgui_->Draw();

	cursor.IMGUI_POS();
}