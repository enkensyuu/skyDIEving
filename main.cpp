#include "DxLib.h"
#include "Player.h"
#include "Airport.h"
#include "Helicopter.h"
#include "WindowL.h"
#include "WindowR.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "スカイDIEビング";

// ウィンドウ横幅
const int WIN_WIDTH = 1200;

// ウィンドウ縦幅
const int WIN_HEIGHT = 1080;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	//初期化
	Player* player_ = new Player;
	player_->Initialize();

	Airport* airport_ = new Airport;

	WindowL* windowL_ = new WindowL;

	WindowR* windowR_ = new WindowR;

	Helicopter* helicopter_ = new Helicopter;

	int scene = 0;

	int Graph = LoadGraph("Resources/back.png");

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		switch (scene)
		{
		case 0:
			DrawFormatString(0, 0, GetColor(255, 0, 0), "scene=%d", scene);
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				scene = 1;
			}
			break;
		case 1:
			DrawFormatString(0, 0, GetColor(255, 0, 0), "scene=%d", scene);
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				player_->Initialize();
				airport_->Initialize(0, 900, 1200, 1300, -1000, -1000, -1000, -1000);
				windowL_->Initialize(-1000, 1200, -1000, -1000);
				helicopter_->Initialize(600, 1500, 1000, 1500, -1000, -1000, -1000, -1000);
				scene = 2;
			}
			break;
		case 2:
			player_->Move(keys);
			for (int i = 0; i < 4; i++)
			{
				player_->AirportOnCollision(airport_->transform_[i].x, airport_->transform_[i].rx, airport_->transform_[i].y, airport_->transform_[i].ry);
				player_->WindowLOnCollision(windowL_->transform_[i].y, windowL_->transform_[i].ry);
				player_->HelicopterOnCollision(helicopter_->transform_[i].x, helicopter_->transform_[i].rx, helicopter_->transform_[i].y, helicopter_->transform_[i].ry);
			}

			if (player_->isGetDeth())
			{
				scene = 6;
			}

			airport_->Update();
			windowL_->Update();
			helicopter_->Update();
			DrawGraph(0, 0, Graph, true);
			windowL_->Draw();
			player_->Draw();
			airport_->Draw();
			helicopter_->Draw();
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			DrawFormatString(0, 0, GetColor(255, 0, 0), "scene=%d", scene);
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				scene = 0;
			}
			break;
		}
		// 描画処理


		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	delete player_;
	delete windowL_;
	delete windowR_;
	delete airport_;
	delete helicopter_;

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
