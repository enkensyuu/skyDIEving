#include "DxLib.h"
#include "Player.h"
#include "Airport.h"
#include "Helicopter.h"
#include "WindowL.h"
#include "WindowR.h"

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
	Airport* airport = new Airport;
	Helicopter* helicopter = new Helicopter;

	//������
	airport->Initialize(0,1000);
	Player* player_ = new Player;
	player_->Initialize();
	helicopter->Initialize();

	Airport* airport_ = new Airport;
	airport_->Initialize(0, 1000);

	WindowL* windowL_ = new WindowL;
	windowL_->Initialize(1000);

	WindowR* windowR_ = new WindowR;
	windowR_->Initialize(500);

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

		// �X�V����
		airport->Update();
		helicopter->Update();

		airport_->Update();
		player_->Move(keys);
		windowL_->Update();
		windowR_->Update();
		player_->WindowLOnCollision(windowL_->transform_.y, windowL_->transform_.ry);
		player_->WindowROnCollision(windowR_->transform_.y, windowR_->transform_.ry);
		// �`�揈��
		airport->Draw();
		windowL_->Draw();
		windowR_->Draw();
		player_->Draw();
		airport_->Draw();
		
		helicopter->Draw();

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

	delete airport;
	delete helicopter;

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
