#pragma once
#include "Cursor.h"
#include "Enemy.h"
#include "KamataEngine.h"

using namespace KamataEngine;

class GameScene {
public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// シーン終了フラグ
	bool IsFinished() { return isFinished_; }

private:
	DirectXCommon* dxc_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	bool isFinished_ = false;

	Cursor cursor;

	int bulletNumber = 0;
	const int maxBulletNum = 6;

	Camera camera_;

	Model* enemyModel = nullptr;
	Enemy* enemy_ = nullptr;

	uint32_t cursorGH = TextureManager::Load("./Resources/scope.png");

	uint32_t bulletGH = TextureManager::Load("./Resources/bullet.png");
	Sprite* bulletSprite[6];
	Vector2 bulletPos[6];
	bool isShoot[6];

	int life_ = 0;
};