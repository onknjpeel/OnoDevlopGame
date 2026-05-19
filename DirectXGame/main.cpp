#include "GameScene.h"
#include "KamataEngine.h"
#include "TitleScene.h"
#include <Windows.h>
#include <d3dcompiler.h>

using namespace KamataEngine;

enum SceneNum {
	kUnknown,
	kTitle,
	kGame,
};

SceneNum scene = kUnknown;

GameScene* gameScene = nullptr;

TitleScene* titleScene = nullptr;

void UpdateScene();

void ChangeScene();

void DrawScene();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE3C_07_オノ_ケンジピエール");

	ShowCursor(0);

	// DirectXCommonのインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	titleScene = new TitleScene();

	titleScene->Initialize();

	// ゲームシーンのインスタンス生成
	gameScene = new GameScene();
	// ゲームシーンの初期化
	gameScene->Initialize();

	scene = kTitle;

	// メインループ
	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		UpdateScene();

		ChangeScene();

		// 描画開始
		dxCommon->PreDraw();

		DrawScene();

		// 描画終了
		dxCommon->PostDraw();

		if (scene == kTitle) {
			if (titleScene->IsEscaped()) {
				break;
			}
			if (Input::GetInstance()->TriggerKey(DIK_ESCAPE)) {
				break;
			}
		}
	}

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}

void UpdateScene() {
	switch (scene) {
	case SceneNum::kTitle:
		titleScene->Update();
		break;
	case SceneNum::kGame:
		gameScene->Update();
		break;
	}
}

void ChangeScene() {
	switch (scene) {
	case SceneNum::kTitle:
		if (titleScene->IsFinished()) {
			scene = SceneNum::kGame;
			delete titleScene;
			titleScene = nullptr;
			gameScene = new GameScene();
			gameScene->Initialize();
		}
		break;
	case SceneNum::kGame:
		if (gameScene->IsFinished()) {
			scene = SceneNum::kTitle;
			delete gameScene;
			gameScene = nullptr;
			titleScene = new TitleScene();
			titleScene->Initialize();
		}
		break;
	}
}

void DrawScene() {
	switch (scene) {
	case SceneNum::kTitle:
		titleScene->Draw();
		break;
	case SceneNum::kGame:
		gameScene->Draw();
		break;
	}
}