#include "TitleScene.h"

using namespace MathUtility;

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {
	dxc_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	startBoxGH = TextureManager::Load("./Resources/startBox.png");
	startBox = {
	    {640.0f, 360.0f},
        {1.0f, 1.0f, 1.0f, 1.0f}
    };
	startBoxSprite = Sprite::Create(startBoxGH, startBox.pos, startBox.color, {0.5f, 0.5f}, 0, 0);

	endBoxGH = TextureManager::Load("./Resources/startBox.png");
	endBox = {
	    {640.0f, 520.0f},
        {1.0f, 1.0f, 1.0f, 1.0f}
    };
	endBoxSprite = Sprite::Create(endBoxGH, endBox.pos, endBox.color, {0.5f, 0.5f}, 0, 0);

	cursor.SetResource(cursorGH, {0.0f, 0.0f});
}

void TitleScene::Update() {
	Vector2 BoxPos = startBoxSprite->GetPosition();
	Vector2 endBoxPos = endBoxSprite->GetPosition();

	if (cursor.GetPos().x >= BoxPos.x - 160.0f && cursor.GetPos().x <= BoxPos.x + 160.0f) {
		if (cursor.GetPos().y >= BoxPos.y - 40.0f && cursor.GetPos().y <= BoxPos.y + 40.0f) {
			startColor = {1.0f, 0.0f, 0.0f, 1.0f};
			if (cursor.TriggerLeft()) {
				isFinished_ = true;
			}
		} else {
			startColor = {1.0f, 1.0f, 1.0f, 1.0f};
		}
	} else {
		startColor = {1.0f, 1.0f, 1.0f, 1.0f};
	}

	if (cursor.GetPos().x >= endBoxPos.x - 160.0f && cursor.GetPos().x <= endBoxPos.x + 160.0f) {
		if (cursor.GetPos().y >= endBoxPos.y - 40.0f && cursor.GetPos().y <= endBoxPos.y + 40.0f) {
			endColor = {1.0f, 0.0f, 0.0f, 1.0f};
			if (cursor.TriggerLeft()) {
				isEscaped_ = true;
			}
		} else {
			endColor = {1.0f, 1.0f, 1.0f, 1.0f};
		}
	} else {
		endColor = {1.0f, 1.0f, 1.0f, 1.0f};
	}

	startBoxSprite->SetColor(startColor);
	endBoxSprite->SetColor(endColor);

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

	startBoxSprite->Draw();

	endBoxSprite->Draw();

	cursor.Draw();

	Sprite::PostDraw();

	cursor.IMGUI_POS();
}