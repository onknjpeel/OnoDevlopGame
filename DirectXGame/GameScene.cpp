#include "GameScene.h"

using namespace MathUtility;

void GameScene::Initialize() {
	dxc_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	camera_.Initialize();

	cursor.SetScreenSize({1280.0f, 720.0f});
	cursor.SetResource(cursorGH, {0.5f, 0.5f});

	enemyModel = Model::CreateFromOBJ("cube", 0);
	enemy_ = new Enemy();
	enemy_->Initialize(enemyModel);

	bulletNumber = maxBulletNum;

	for (int i = 0; i < maxBulletNum; i++) {
		bulletPos[i] = {20.0f + (i * 60.0f), 700.0f};
		bulletSprite[i] = Sprite::Create(bulletGH, bulletPos[i], {1.0f, 1.0f, 1.0f, 1.0f}, {0.5f, 0.5f}, 0, 0);
		isShoot[i] = true;
	}
}

void GameScene::Update() {
	camera_.UpdateMatrix();

	enemy_->Update();

	if (enemy_->GetPos().x - enemy_->GetSize().x <= cursor.GetPos().x && enemy_->GetPos().x + enemy_->GetSize().x >= cursor.GetPos().x) {
		if (enemy_->GetPos().y - enemy_->GetSize().y <= cursor.GetPos().y && enemy_->GetPos().y + enemy_->GetSize().y >= cursor.GetPos().y) {
			enemy_->SetTouched(1);
			if (cursor.TriggerLeft()) {
				isFinished_ = true;
			}
		} else {
			if (cursor.TriggerLeft()) {
				if (bulletNumber > 0) {
					bulletNumber--;
				}
			}
			enemy_->SetTouched(0);
		}
	} else {
		if (cursor.TriggerLeft()) {
			if (bulletNumber > 0) {
				bulletNumber--;
			}
		}
		enemy_->SetTouched(0);
	}

	if (cursor.TriggerRight()) {
		if (bulletNumber < maxBulletNum) {
			bulletNumber = maxBulletNum;
		}
	}
	cursor.Update();

	for (int i = 0; i < maxBulletNum; i++) {
		if (i + 1 > bulletNumber) {
			isShoot[i] = false;
		} else {
			isShoot[i] = true;
		}
	}
}

void GameScene::Draw() {
	// 描画処理//
	// 背景
	Sprite::PreDraw();

	Sprite::PostDraw();

	// 3Dモデル
	Model::PreDraw();
	enemy_->Draw(camera_);
	Model::PostDraw();

	// 前景
	Sprite::PreDraw();

	for (int i = 0; i < maxBulletNum; i++) {
		if (isShoot[i]) {
			bulletSprite[i]->Draw();
		}
	}

	cursor.Draw();

	Sprite::PostDraw();

	ImGuiManager* imgui_ = ImGuiManager::GetInstance();
	imgui_->Begin();
	ImGui::Begin("weaponNum");
	ImGui::InputInt("num", &bulletNumber);
	ImGui::End();
	imgui_->End();

	imgui_->Draw();

	cursor.IMGUI_POS();
	enemy_->IMGUI();
}