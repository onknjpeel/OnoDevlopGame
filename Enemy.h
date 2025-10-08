#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Enemy {
public:
	~Enemy();

	void Initialize();

	void Update();

	void Draw();

private:
	DirectXCommon* dxc_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	Model* model_ = nullptr;

	bool isAlive_ = false;
};
