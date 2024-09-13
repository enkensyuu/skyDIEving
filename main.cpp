#include "DxLib.h"
#include "Player.h"
#include "Airport.h"
#include "Helicopter.h"
#include "WindowL.h"
#include "WindowR.h"
#include "Goal.h"

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

	int scene = 0;

	int Graph = LoadGraph("Resources/back.png");
	int graphX = 0;
	int graphY = 0;
	int graphY2 = 1080;

	//-----�Q�[���I�[�o�[�̉摜-----//
	int gameOverGraph = LoadGraph("Resources/gameOver.png");

	//-----�Q�[���N���A�̉摜-----//
	int gameClearGraph = LoadGraph("Resources/gameClear.png");

	//-----�^�C�g���̉摜-----//
	int titleGraph = LoadGraph("Resources/title_0.png");
	SetDrawScreen(DX_SCREEN_BACK);

	//-----��������̉摜-----//
	int controllGraph = LoadGraph("Resources/controll.png");

	//-----�t�F�[�h�C���A�A�E�g�ϐ�-----//
	int colorChange = 0;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		switch (scene) {
			case 0:
				DrawFormatString(0, 0, GetColor(255, 0, 0), "scene=%d", scene);
				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
					scene = 1;
				}
				break;
			case 1:
				DrawFormatString(0, 0, GetColor(255, 0, 0), "scene=%d", scene);
				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
					player_->Initialize();
					airport_->Initialize(0, 900, 1200, 1300, -1000, -1000, -1000, -1000);
					windowL_->Initialize(-1000, 1200, -1000, -1000);
					helicopter_->Initialize(600, 1500, 1000, 1500, -1000, -1000, -1000, -1000);
					goal_->Initialize(2500);
					scene = 2;
				}
				break;
			case 2:
				graphY -= 3;
				graphY2 -= 3;

				if (graphY <= -1080) {
					graphY = 1080;
				}
				if (graphY2 <= -1080) {
					graphY2 = 1080;
				}
				player_->Move(keys);
				for (int i = 0; i < 4; i++) {
					player_->AirportOnCollision(airport_->transform_[i].x, airport_->transform_[i].rx, airport_->transform_[i].y, airport_->transform_[i].ry);
					player_->WindowLOnCollision(windowL_->transform_[i].y, windowL_->transform_[i].ry);
					player_->HelicopterOnCollision(helicopter_->transform_[i].x, helicopter_->transform_[i].rx, helicopter_->transform_[i].y, helicopter_->transform_[i].ry);
				}

				player_->GoalOnCollision(goal_->transform_.y, goal_->transform_.ry);

				if (player_->isGetGoal()) {
					scene = 5;
				}

				if (player_->isGetDeth()) {
					scene = 6;
				}

				airport_->Update();
				windowL_->Update();
				helicopter_->Update();
				goal_->Update();
				DrawGraph(graphX, graphY, Graph, true);
				DrawGraph(graphX, graphY2, Graph, true);
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
				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
					scene = 0;
				}
				break;
			case 6:
				DrawFormatString(0, 0, GetColor(255, 0, 0), "scene=%d", scene);
				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
					scene = 0;
				}
				break;
		}


		//-------�`�揈��-------//
		switch (scene) {
			//�^�C�g��
			case 0:

				//�t�F�[�h�C������
				for (colorChange = 0; colorChange <= 255; colorChange++) {
					SetDrawBright(colorChange, colorChange, colorChange);
					DrawGraph(0, 0, titleGraph, true);
					ScreenFlip();
				}

				//�t�F�[�h�A�E�g����
				for (colorChange = 0; colorChange <= 255; colorChange++) {
					SetDrawBright(255 - colorChange, 255 - colorChange, 255 - colorChange);
					DrawGraph(0, 0, titleGraph, FALSE);
					ScreenFlip();
				}
				scene = 1;

				break;
				//�������
			case 1:
				for (colorChange = 0; colorChange < 255; colorChange++) {
					SetDrawBright(colorChange, colorChange, colorChange);
					DrawGraph(0, 0, controllGraph, FALSE);
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				DrawGraph(0, 0, gameClearGraph, FALSE);
				break;
			case 6:
				DrawGraph(0, 0, gameOverGraph, FALSE);
				break;
		}


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
