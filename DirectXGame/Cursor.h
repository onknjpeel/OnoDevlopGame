#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

struct Vec2Int {
	int x;
	int y;
};

struct Cursor {
private:
	Vector2 pos_;
	Vector2 screenSize_;
	Input* input_ = Input::GetInstance();
	Sprite* sprite = nullptr;
	Vector2 spritePos;

public:
	void SetScreenSize(Vector2 screenSize) { screenSize_ = screenSize; }
	Vector2 GetPos() { return pos_; }
	void SetResource(uint32_t GH, Vector2 anchor) { sprite = Sprite::Create(GH, pos_, {1.0f, 1.0f, 1.0f, 1.0f}, anchor, 0, 0); }
	void Update() {
		pos_ = {input_->GetInstance()->GetMousePosition().x - (screenSize_.x / 2.0f), input_->GetInstance()->GetMousePosition().y - (screenSize_.y / 2.0f)};
		spritePos = {pos_.x + (screenSize_.x / 2.0f), pos_.y + (screenSize_.y / 2.0f)};
		sprite->SetPosition(spritePos);
	}
	bool TriggerLeft() { return input_->IsTriggerMouse(0); }
	bool TriggerRight() { return input_->IsTriggerMouse(1); }
	void Draw() { sprite->Draw(); }
#ifdef _DEBUG
	void IMGUI_POS() {
		ImGuiManager* imgui_ = ImGuiManager::GetInstance();
		imgui_->Begin();
		ImGui::Begin("cursor");
		ImGui::InputFloat2("pos", &pos_.x);
		ImGui::End();
		imgui_->End();

		imgui_->Draw();
	}
#endif // _DEBUG
};