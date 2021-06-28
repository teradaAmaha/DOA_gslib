#include "TiltleScene.h"
#include "Assets.h"

//�J�n
void TitleScene::start() {
	//�摜�̓ǂݍ���
	gsLoadTexture(TextureTitleBG, "Assets/2DSprite/BG4.png");
	gsLoadTexture(TextureTitleLogo,"Assets/2DSprite/TITLE1.png");
	//�I���t���O������
	is_end_ = false;
}

//�X�V
void TitleScene::update(float delta_time) {
	//�G���^�[�L�[����������V�[���I��
	if (gsGetKeyTrigger(GKEY_RETURN)) {
		is_end_ = true;
	}
	
}

//�`��
void TitleScene::draw() const {
	//�w�i�̕`��
	gsDrawSprite2D(TextureTitleBG, 0, NULL, NULL, NULL, NULL, 0.0f);
	//�^�C�g�����S�̕`��ʒu
	const static GSvector2 position_logo{ 64.0f, 50.0f };
	//�^�C�g�����S�̕`��
	gsDrawSprite2D(TextureTitleLogo, &position_logo, NULL, NULL, NULL, NULL, 0.0f);
}

bool TitleScene::is_end() const {
	return is_end_; //�I���O���t��Ԃ�
}

//���̃V�[����Ԃ�
std::string TitleScene::next() const {
	return "GamePlayScene";//���̃V�[������Ԃ�
}

void TitleScene::end() {
	//�摜�̍폜
	gsDeleteTexture(TextureTitleBG);
	gsDeleteTexture(TextureTitleLogo);
}
