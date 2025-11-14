#include "Enemy.h"

Enemy::~Enemy() {}

void Enemy::Initialize(Model* model) {
	model_ = model;
	worldTransform_.Initialize();
	pos_ = worldTransform_.translation_;
	objectColor_.Initialize();
	size_ = {20.0f, 20.0f};
}

void Enemy::Update() {
	Input* input = Input::GetInstance();
	if (input->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= 0.1f;
	} else if (input->PushKey(DIK_D)) {
		worldTransform_.translation_.x += 0.1f;
	}

	if (isTouch_) {
		color = {1.0f, 0.0f, 0.0f, 1.0f};
	} else {
		color = {1.0f, 1.0f, 1.0f, 1.0f};
	}
	objectColor_.SetColor(color);
	pos_ = worldTransform_.translation_;
	worldTransform_.UpdateMatrix();
}

void Enemy::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }

Vector3 Enemy::GetPos() { return worldTransform_.translation_; }

void Enemy::IMGUI() {
	ImGuiManager* imgui_ = ImGuiManager::GetInstance();
	imgui_->Begin();
	ImGui::Begin("enemy");
	ImGui::InputFloat3("pos", &worldTransform_.translation_.x);
	ImGui::End();
	imgui_->End();

	imgui_->Draw();
}
