# include <Siv3D.hpp> // Siv3D v0.6.13

#include "MainGameState.h"
#include "TaskManager.h"

void Main()
{
	using namespace Task;

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 画像ファイルからテクスチャを作成する | Create a texture from an image file
	//const Texture texture{ U"example/windmill.png" };

	// 絵文字からテクスチャを作成する | Create a texture from an emoji
	//const Texture emoji{ U"🦖"_emoji };

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	//const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// テキストに含まれる絵文字のためのフォントを作成し、font に追加する | Create a font for emojis in text and add it to font as a fallback
	//const Font emojiFont{ 48, Typeface::ColorEmoji };
	//font.addFallback(emojiFont);

	TaskManager::Create();

	MainGameState gameState;
	gameState.Enter();

	while (System::Update())
	{
		// 長方形を描く | Draw a rectangle
		Rect{ 540, 20, 80, 80 }.draw();

		gameState.Update();
	}

	gameState.Exit();

	TaskManager::Release();
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
