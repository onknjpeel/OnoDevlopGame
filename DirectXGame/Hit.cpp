#include "Hit.h"

void Hit::Initialize(Vector2 position) {
	pos = position;
	isHit = true;
	timer = 60;
	sprite = Sprite::Create(hitGH, pos, {1.0f, 1.0f, 1.0f, 1.0f}, {0.5f, 0.5f}, 0, 0);
}

void Hit::Update() {
	timer--;
	if (timer <= 0) {
		isHit = false;
	}
}

void Hit::Draw() {
	if (isHit) {
		sprite->Draw();
	}
}