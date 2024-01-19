# include <Siv3D.hpp> // Siv3D v0.6.13

#include "MainGameState.h"
#include "TaskManager.h"
#include "PhysicsSystem.h"

void Main()
{
	using namespace Task;

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 各種システムの立ち上げ
	PhysicsSystem::Create();

	MainGameState gameState;
	gameState.Enter();

	while (System::Update())
	{
		// システム更新処理
		gameState.Update();
	}

	gameState.Exit();

	// 各種システムをクローズ
	PhysicsSystem::Release();
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
