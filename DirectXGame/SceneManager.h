#pragma once
#include "Scene.h"
#include <memory>
class SceneManager {
public:
	void SceneInit();
	void SceneChange(std::unique_ptr<Scene> newScene);
	void Update();
	void Draw();
	bool Escape() { return escaped_; }

	std::unique_ptr<Scene> CreateScene(SceneNum type);

private:
	std::unique_ptr<Scene> currentScene_;
	bool escaped_ = false;
};

