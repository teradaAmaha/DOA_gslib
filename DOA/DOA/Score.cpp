#include "Score.h"
#include "NumberTexture.h"
#include "TextureID.h"
#include <gslib.h>
#include <algorithm> // std::min�֐��̂��߂ɕK�v

// �R���X�g���N�^
Score::Score(int score) :
    score_{ score } {
}

// �X�R�A�̏�����
void Score::initialize(int score) {
    score_ = score;
}

// �X�R�A�̉��Z
void Score::add(int score) {
    // �X�R�A�̏���l��9999999�Ƃ���
    score_ = std::min(score_ + score, 9999999);
}

// �X�R�A�̕`��
void Score::draw() const {
    static const NumberTexture number{ TextureNumber, 16, 16 };

    number.draw(GSvector2{ 520, 0 }, score_, 7);

}

// �X�R�A�̎擾
int Score::get() const {
    return score_;
}


// �X�R�A�̃N���A
void Score::clear() {
    score_ = 0;
}

