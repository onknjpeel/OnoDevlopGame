#include "TitleScene.h"

using namespace MathUtility;

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

	endBoxGH = TextureManager::Load("./Resources/endBox.png");
	endBox = {
	    {640.0f, 520.0f},
        {1.0f, 1.0f, 1.0f, 1.0f}
    };
	endBoxSprite = Sprite::Create(endBoxGH, endBox.pos, endBox.color, {0.5f, 0.5f}, 0, 0);

	hit = new Hit();

	isHit = false;
	isHitE = false;

	cursor.SetResource(cursorGH, {0.0f, 0.0f});
}

void TitleScene::Update() {
	Vector2 BoxPos = startBoxSprite->GetPosition();
	Vector2 endBoxPos = endBoxSprite->GetPosition();

	if (!isHit && !isHitE) {
		if (cursor.TriggerLeft()) {
			hit->Initialize(cursor.GetPos());
		}
	}

	if (cursor.GetPos().x >= BoxPos.x - 160.0f && cursor.GetPos().x <= BoxPos.x + 160.0f) {
		if (cursor.GetPos().y >= BoxPos.y - 40.0f && cursor.GetPos().y <= BoxPos.y + 40.0f) {
			startColor = {1.0f, 0.0f, 0.0f, 1.0f};
			if (cursor.TriggerLeft()) {
				if (!isHitE) {
					isHit = true;
				}
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
				if (!isHit) {
					isHitE = true;
				}
			}
		} else {
			endColor = {1.0f, 1.0f, 1.0f, 1.0f};
		}
	} else {
		endColor = {1.0f, 1.0f, 1.0f, 1.0f};
	}

	if (isHit && !hit->IsHit()) {
		isFinished_ = true;
	}
	if (isHitE && !hit->IsHit()) {
		isEscaped_ = true;
	}

	hit->Update();

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

	hit->Draw();

	cursor.Draw();

	Sprite::PostDraw();

	cursor.IMGUI_POS();
}

SceneNum TitleScene::GetNextScene() {
	if (isFinished_) {
		return SceneNum::kGame;
	}
	if (isEscaped_) {
		return SceneNum::kEnd;
	}
	return SceneNum::kUnknown;
}