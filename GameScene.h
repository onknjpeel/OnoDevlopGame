#pragma once
#include "Cursor.h"
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

	int weaponNumber = 0;
};