#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

struct Vec2Int {
	int x;
	int y;
};

struct Cursor {
	Vector2 pos_;
	void Update() {
		Input* input_ = Input::GetInstance();
		pos_ = input_->GetInstance()->GetMousePosition();
	}
	bool TriggerLeft() {
		Input* input_ = Input::GetInstance();
		return input_->IsTriggerMouse(0);
	}
	bool TriggerRight() {
		Input* input_ = Input::GetInstance();
		return input_->IsTriggerMouse(1);
	}
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