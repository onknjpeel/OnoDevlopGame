#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Hit {
public:
	void Initialize(Vector2 position);

	void Update();

	void Draw();

	bool IsHit() { return isHit; }

private:
	Vector2 pos{};

	Sprite* sprite = nullptr;

	uint32_t hitGH = TextureManager::Load("./Resources/hit.png");

	int timer;

	bool isHit = false;
};
