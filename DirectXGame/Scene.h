#pragma once
enum class SceneNum {
	kUnknown,
	kTitle,
	kGame,
	kEnd,
};

class Scene {
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual SceneNum GetNextScene() { return SceneNum::kUnknown; }

	virtual ~Scene() = default;

private:
};
