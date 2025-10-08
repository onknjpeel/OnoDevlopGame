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
}

void TitleScene::Update() {
	Vector2 BoxPos = startBoxSprite->GetPosition();

	if (cursor.GetPos().x >= BoxPos.x - 160.0f && cursor.GetPos().x <= BoxPos.x + 160.0f) {
		if (cursor.GetPos().y >= BoxPos.y - 40.0f && cursor.GetPos().y <= BoxPos.y + 40.0f) {
			if (cursor.TriggerLeft()) {
				isFinished_ = true;
			}
		}
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

	startBoxSprite->Draw();

	Sprite::PostDraw();

	cursor.IMGUI_POS();
}