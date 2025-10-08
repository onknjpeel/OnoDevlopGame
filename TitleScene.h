#pragma once
#include "Cursor.h"
#include "KamataEngine.h"

using namespace KamataEngine;

struct Box {
	Vector2 pos;
	Vector4 color;
};

class TitleScene {
public:
	~TitleScene();

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

	uint32_t startBoxGH = 0u;
	Sprite* startBoxSprite = nullptr;
	Box startBox = {{}, {}};

	Cursor cursor;
};