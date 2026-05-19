#include "GameScene.h"
#include "Scene.h"
#include "SceneManager.h"
#include <Windows.h>
#include <d3dcompiler.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE3C_07_オノ_ケンジピエール");

	ShowCursor(0);

	// DirectXCommonのインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	SceneManager sceneManager;

	sceneManager.SceneInit();

	// メインループ
	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		sceneManager.Update();

		// 描画開始
		dxCommon->PreDraw();

		sceneManager.Draw();

		// 描画終了
		dxCommon->PostDraw();

		if (sceneManager.Escape()) {
			break;
		}
		if (Input::GetInstance()->TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}