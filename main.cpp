#include "DxLib.h"
#include "Player.h"
#include "Airport.h"
#include "Helicopter.h"
#include "WindowL.h"
#include "WindowR.h"
#include "Goal.h"
#include "FPS.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "�X�J�CDIE�r���O";

// �E�B���h�E����
const int WIN_WIDTH = 1200;

// �E�B���h�E�c��
const int WIN_HEIGHT = 1080;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	//����������؂�
	SetWaitVSyncFlag(0);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	//������
	Player* player_ = new Player;
	player_->Initialize();

	Airport* airport_ = new Airport;

	WindowL* windowL_ = new WindowL;

	WindowR* windowR_ = new WindowR;

	Helicopter* helicopter_ = new Helicopter;

	Goal* goal_ = new Goal;

	FPS* fps_ = new FPS;

	int scene = 0;

#pragma region ���\�[�X
	int backGraph = LoadGraph("Resources/back.png");
	int oneGraph = LoadGraph("Resources/countDown_1.png");
	int twoGraph = LoadGraph("Resources/countDown_2.png");
	int threeGraph = LoadGraph("Resources/countDown_3.png");
	int startGraph = LoadGraph("Resources/START.png");
	int overGraph = LoadGraph("Resources/gameOver.png");
	int clearGraph = LoadGraph("Resources/gameClear.png");
	int titlebackGraph = LoadGraph("Resources/titleBack_0.png");
	int selecttitlebackGraph = LoadGraph("Resources/titleBack_1.png");
	int resetGraph = LoadGraph("Resources/restart_0.png");
	int selectresetGraph = LoadGraph("Resources/restart_1.png");
	int titleGraph = LoadGraph("Resources/title_0.png");
	int opeGraph = LoadGraph("Resources/operation_description.png");
	int stage1Graph = LoadGraph("Resources/Stage1.png");
	int stage2Graph = LoadGraph("Resources/Stage2.png");
	int stage3Graph = LoadGraph("Resources/Stage3.png");
	PlaySoundFile("Resources/BGM.mp3", DX_PLAYTYPE_LOOP);
#pragma endregion

	int graphX = 0;
	int graphY = 0;
	int graphY2 = 1080;
	bool select = true;
	int nowScene;
	int stopTimer = 360;
	bool isStop = true;
	int stageFlag;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		 //�t���[�����[�g����
		fps_->Update();

		// �X�V����
		switch (scene)
		{
		case 0:
			DrawGraph(0, 0, titleGraph, true);
			//�t���[�����[�g�\��
			fps_->Draw();
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				scene = 1;
			}
			break;
		case 1:
			DrawGraph(0, 0, opeGraph, true);
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				player_->Initialize();
				airport_->Initialize(0, 900, 1200, 1300, -1000, -1000, -1000, -1000);
				windowL_->Initialize(-1000, 1200, -1000, -1000);
				helicopter_->Initialize(600, 1500, 1000, 1500, -1000, -1000, -1000, -1000);
				goal_->Initialize(2500);
				stopTimer = 360;
				isStop = true;
				select = true;

				scene = 2;
			}
			break;
		case 2:
			stopTimer--;
			if (stopTimer < 0)
			{
				isStop = false;
			}
			if (!isStop)
			{
				graphY -= 3;
				graphY2 -= 3;

				if (graphY <= -1080)
				{
					graphY = 1080;
				}
				if (graphY2 <= -1080)
				{
					graphY2 = 1080;
				}
				player_->Move(keys);
				for (int i = 0; i < 4; i++)
				{
					player_->AirportOnCollision(airport_->transform_[i].x, airport_->transform_[i].rx, airport_->transform_[i].y, airport_->transform_[i].ry);
					player_->WindowLOnCollision(windowL_->transform_[i].y, windowL_->transform_[i].ry);
					player_->HelicopterOnCollision(helicopter_->transform_[i].x, helicopter_->transform_[i].rx, helicopter_->transform_[i].y, helicopter_->transform_[i].ry);
				}

				player_->GoalOnCollision(goal_->transform_.y, goal_->transform_.ry);

				if (player_->isGetGoal())
				{
					stageFlag = 1;
					scene = 5;
				}

				if (player_->isGetDeth())
				{
					nowScene = scene;
					select = true;
					scene = 6;
				}

				airport_->Update();
				windowL_->Update();
				helicopter_->Update();
				goal_->Update();
			}

			DrawGraph(graphX, graphY, backGraph, true);
			DrawGraph(graphX, graphY2, backGraph, true);
			windowL_->Draw();
			player_->Draw();
			airport_->Draw();
			helicopter_->Draw();

			if (stopTimer < 360 && stopTimer>240)
			{
				DrawGraph(280, 255, stage1Graph, true);
			}

			else if (stopTimer < 240 && stopTimer>180)
			{
				DrawGraph(536, 255, threeGraph, true);
			}
			else if (stopTimer < 180 && stopTimer>120)
			{
				DrawGraph(536, 255, twoGraph, true);
			}
			else if (stopTimer < 120 && stopTimer>60)
			{
				DrawGraph(536, 255, oneGraph, true);
			}
			else if (stopTimer < 60 && stopTimer>0)
			{
				DrawGraph(280, 255, startGraph, true);
			}
			fps_->Draw();

			break;
		case 3:
			stopTimer--;
			if (stopTimer < 0)
			{
				isStop = false;
			}
			if (!isStop)
			{
				graphY -= 3;
				graphY2 -= 3;

				if (graphY <= -1080)
				{
					graphY = 1080;
				}
				if (graphY2 <= -1080)
				{
					graphY2 = 1080;
				}
				player_->Move(keys);
				for (int i = 0; i < 4; i++)
				{
					player_->AirportOnCollision(airport_->transform_[i].x, airport_->transform_[i].rx, airport_->transform_[i].y, airport_->transform_[i].ry);
					player_->WindowLOnCollision(windowL_->transform_[i].y, windowL_->transform_[i].ry);
					player_->HelicopterOnCollision(helicopter_->transform_[i].x, helicopter_->transform_[i].rx, helicopter_->transform_[i].y, helicopter_->transform_[i].ry);
				}

				player_->GoalOnCollision(goal_->transform_.y, goal_->transform_.ry);

				if (player_->isGetGoal())
				{
					stageFlag = 2;
					scene = 5;
				}

				if (player_->isGetDeth())
				{
					nowScene = scene;
					select = true;
					scene = 6;
				}

				airport_->Update();
				windowL_->Update();
				helicopter_->Update();
				goal_->Update();
			}

			DrawGraph(graphX, graphY, backGraph, true);
			DrawGraph(graphX, graphY2, backGraph, true);
			windowL_->Draw();
			player_->Draw();
			airport_->Draw();
			helicopter_->Draw();

			if (stopTimer < 360 && stopTimer>240)
			{
				DrawGraph(280, 255, stage2Graph, true);
			}

			else if (stopTimer < 240 && stopTimer>180)
			{
				DrawGraph(536, 255, threeGraph, true);
			}
			else if (stopTimer < 180 && stopTimer>120)
			{
				DrawGraph(536, 255, twoGraph, true);
			}
			else if (stopTimer < 120 && stopTimer>60)
			{
				DrawGraph(536, 255, oneGraph, true);
			}
			else if (stopTimer < 60 && stopTimer>0)
			{
				DrawGraph(280, 255, startGraph, true);
			}
			break;

		case 4:
			stopTimer--;
			if (stopTimer < 0)
			{
				isStop = false;
			}
			if (!isStop)
			{
				graphY -= 3;
				graphY2 -= 3;

				if (graphY <= -1080)
				{
					graphY = 1080;
				}
				if (graphY2 <= -1080)
				{
					graphY2 = 1080;
				}
				player_->Move(keys);
				for (int i = 0; i < 4; i++)
				{
					player_->AirportOnCollision(airport_->transform_[i].x, airport_->transform_[i].rx, airport_->transform_[i].y, airport_->transform_[i].ry);
					player_->WindowLOnCollision(windowL_->transform_[i].y, windowL_->transform_[i].ry);
					player_->WindowROnCollision(windowR_->transform_[i].y, windowR_->transform_[i].ry);
					player_->HelicopterOnCollision(helicopter_->transform_[i].x, helicopter_->transform_[i].rx, helicopter_->transform_[i].y, helicopter_->transform_[i].ry);
				}

				player_->GoalOnCollision(goal_->transform_.y, goal_->transform_.ry);

				if (player_->isGetGoal())
				{
					stageFlag = 3;
					scene = 5;
				}

				if (player_->isGetDeth())
				{
					nowScene = scene;
					select = true;
					scene = 6;
				}

				airport_->Update();
				windowL_->Update();
				windowR_->Update();
				helicopter_->Update();
				goal_->Update();
			}

			DrawGraph(graphX, graphY, backGraph, true);
			DrawGraph(graphX, graphY2, backGraph, true);
			windowL_->Draw();
			windowR_->Draw();
			player_->Draw();
			airport_->Draw();
			helicopter_->Draw();

			if (stopTimer < 360 && stopTimer>240)
			{
				DrawGraph(280, 255, stage3Graph, true);
			}

			else if (stopTimer < 240 && stopTimer>180)
			{
				DrawGraph(536, 255, threeGraph, true);
			}
			else if (stopTimer < 180 && stopTimer>120)
			{
				DrawGraph(536, 255, twoGraph, true);
			}
			else if (stopTimer < 120 && stopTimer>60)
			{
				DrawGraph(536, 255, oneGraph, true);
			}
			else if (stopTimer < 60 && stopTimer>0)
			{
				DrawGraph(280, 255, startGraph, true);
			}
			break;
		case 5:
			DrawGraph(0, 0, clearGraph, true);
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && stageFlag == 1)
			{
				player_->Initialize();
				airport_->Initialize(0, 800, 1200, 900, 0, 1800, 1200, 1900);
				windowL_->Initialize(1300, 1500, -1000, -1000);
				helicopter_->Initialize(0, 1500, 600, 1500, 1200, 1500, -1000, -1000);
				goal_->Initialize(2500);
				stopTimer = 360;
				isStop = true;
				select = true;
				scene = 3;
			}
			else if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && stageFlag == 2)
			{
				player_->Initialize();
				airport_->Initialize(1750, 900, -200, 1500, 0, 2200, 900, 2800);
				windowL_->Initialize(800, 1200, 1600, 2000);
				windowR_->Initialize(1000, 1400, 1800, 2200);
				helicopter_->Initialize(100, 1000, 1060, 1500, 500, 1700, 700, 2200);
				goal_->Initialize(3650);
				stopTimer = 360;
				isStop = true;
				select = true;
				scene = 4;
			}
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && stageFlag == 3)
			{
				scene = 0;
			}
			break;
		case 6:
			DrawGraph(0, 0, overGraph, true);
			if (keys[KEY_INPUT_LEFT] == 1 || keys[KEY_INPUT_A] == 1 && !select)
			{
				select = true;
			}
			else if (keys[KEY_INPUT_RIGHT] == 1 || keys[KEY_INPUT_D] == 1 && select)
			{
				select = false;;
			}

			if (select)
			{
				DrawGraph(172, 600, selecttitlebackGraph, true);
				DrawGraph(745, 600, resetGraph, true);
			}

			else
			{
				DrawGraph(172, 600, titlebackGraph, true);
				DrawGraph(745, 600, selectresetGraph, true);
			}

			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				if (select)
				{
					scene = 0;
				}
				else
				{
					if (nowScene == 2)
					{
						player_->Initialize();
						airport_->Initialize(0, 900, 1200, 1300, -1000, -1000, -1000, -1000);
						windowL_->Initialize(-1000, 1200, -1000, -1000);
						helicopter_->Initialize(600, 1500, 1000, 1500, -1000, -1000, -1000, -1000);
						goal_->Initialize(2500);
						stopTimer = 360;
						select = true;
						isStop = true;
					}
					else if (nowScene == 3)
					{
						player_->Initialize();
						airport_->Initialize(0, 800, 1200, 900, 0, 1800, 1200, 1900);
						windowL_->Initialize(1300, 1500, -1000, -1000);
						helicopter_->Initialize(0, 1500, 600, 1500, 1200, 1500, -1000, -1000);
						goal_->Initialize(2500);
						stopTimer = 360;
						select = true;
						isStop = true;
					}
					else if (nowScene == 4)
					{
						player_->Initialize();
						airport_->Initialize(1750, 900, -200, 1500, 0, 2200, 900, 2800);
						windowL_->Initialize(800, 1200, 1600, 2000);
						windowR_->Initialize(1000, 1400, 1800, 2200);
						helicopter_->Initialize(100, 1000, 1060, 1500, 500, 1700, 700, 2200);
						goal_->Initialize(3650);
						stopTimer = 360;
						isStop = true;
						select = true;
					}
					scene = nowScene;
				}
			}
			break;
		}
		// �`�揈��


		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	delete player_;
	delete windowL_;
	delete windowR_;
	delete airport_;
	delete helicopter_;

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}