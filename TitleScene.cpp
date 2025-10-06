#include "TitleScene.h"

using namespace MathUtility;

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {
	dxc_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
}

void TitleScene::Update() {
	if (cursor.TriggerLeft()) {
		isFinished_ = true;
	}
	cursor.Update();
}

void TitleScene::Draw() {
	// 背景
	Sprite::PreDraw();

	Sprite::PostDraw();

	// 3Dモデル
	Model::PreDraw();

	Model::PostDraw();

	// 前景
	Sprite::PreDraw();

	Sprite::PostDraw();

	cursor.IMGUI_POS();
}