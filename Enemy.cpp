#include "Enemy.h"

Enemy::~Enemy() {}

void Enemy::Initialize(Model* model) {
	model_ = model;
	worldTransform_.Initialize();
	objectColor_.Initialize();
	size_ = {20.0f, 20.0f};
}

void Enemy::Update() {
	if (isTouch_) {
		color = {1.0f, 0.0f, 0.0f, 1.0f};
	} else {
		color = {1.0f, 1.0f, 1.0f, 1.0f};
	}
	objectColor_.SetColor(color);
}

void Enemy::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }

Vector3 Enemy::GetPos() { return worldTransform_.translation_; }