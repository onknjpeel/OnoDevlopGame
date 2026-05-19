#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Particle {
private:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

public:
	Model* model_ = nullptr;
	Vector3 pos_;

};
