#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Enemy {
public:
	~Enemy();

	void Initialize(Model* model);

	void Update();

	void Draw(Camera& camera);

	void SetTouched(bool flag) { isTouch_ = flag; }

	Vector3 GetPos();

	Vector2 GetSize() { return size_; }

	void IMGUI();

private:
	DirectXCommon* dxc_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	Vector3 pos_;

	ObjectColor objectColor_;
	Vector4 color;

	const Vector2 size_ = {20.0f, 20.0f};

	bool isAlive_ = false;
	bool isTouch_ = false;
};
