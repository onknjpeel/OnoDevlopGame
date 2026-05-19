#include "SceneManager.h"
#include "BlankSceneOfTheEnd.h"
#include "GameScene.h"
#include "TitleScene.h"

void SceneManager::SceneInit() { SceneChange(std::make_unique<TitleScene>()); }

void SceneManager::SceneChange(std::unique_ptr<Scene> newScene) {
	currentScene_ = std::move(newScene);
	currentScene_->Initialize();
}

void SceneManager::Update() {
	currentScene_->Update();
	SceneNum nextScene = currentScene_->GetNextScene();
	if (nextScene != SceneNum::kUnknown) {
		SceneChange(CreateScene(nextScene));
	}
}

void SceneManager::Draw() { currentScene_->Draw(); }

std::unique_ptr<Scene> SceneManager::CreateScene(SceneNum type) {
	switch (type) {
	case SceneNum::kTitle:
		return std::make_unique<TitleScene>();
	case SceneNum::kGame:
		return std::make_unique<GameScene>();
	case SceneNum::kEnd:
		escaped_ = true;
		return std::make_unique<BlankSceneOfTheEnd>();
	}
	return nullptr;
}
