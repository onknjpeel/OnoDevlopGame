#pragma once
#include "Cursor.h"
#include "Hit.h"
#include "KamataEngine.h"
#include "Scene.h"

using namespace KamataEngine;

struct Box {
	Vector2 pos;
	Vector4 color;
};

class TitleScene : public Scene {
public:
	// 初期化
	void Initialize() override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// シーン終了フラグ
	bool IsFinished() { return isFinished_; }

	bool IsEscaped() { return isEscaped_; }

	SceneNum GetNextScene();

private:
	DirectXCommon* dxc_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	bool isFinished_ = false;
	bool isEscaped_ = false;

	uint32_t startBoxGH = 0u;
	Sprite* startBoxSprite = nullptr;
	const Vector2 startBoxPos = {};
	Vector4 startColor = {1.0f, 1.0f, 1.0f, 1.0f};

	Box startBox = {{}, {}};

	uint32_t endBoxGH = 0u;
	Sprite* endBoxSprite = nullptr;
	const Vector2 endBoxPos = {};
	Vector4 endColor = {1.0f, 1.0f, 1.0f, 1.0f};

	Box endBox = {{}, {}};

	Cursor cursor;
	uint32_t cursorGH = TextureManager::Load("./Resources/cursor.png");

	Hit* hit = nullptr;
	bool isHit = false;
	bool isHitE = false;
};