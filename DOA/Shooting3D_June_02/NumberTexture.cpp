#include "NumberTexture.h"
#include <sstream>
#include <iomanip>

// �R���X�g���N�^
NumberTexture::NumberTexture(GSuint texture, int width, int height) :
    texture_{ texture }, width_{ width }, height_{ height } {
}

// �`�� (�E�l��)
void NumberTexture::draw(const GSvector2& position, int num, int digit, char fill) const {
    std::stringstream ss;
    ss << std::setw(digit) << std::setfill(fill) << num;
    draw(position, ss.str());
}

// �`�� (���l��)
void NumberTexture::draw(const GSvector2& position, int num) const {
    draw(position, std::to_string(num));
}

// �`��
void NumberTexture::draw(const GSvector2& position, const std::string& num) const {
    // ������1�������`�悷��
    for (int i = 0; i < (int)num.size(); ++i) {
        if (num[i] == ' ') continue; // �󔒕����̓X�L�b�v
        // char�^��int�^�ɕϊ�
        int n = num[i] - '0';
        // �����ɑΉ�����摜��؂�o�����߂̋�`���v�Z����(���l�t�H���g�摜���̈ʒu�j
        GSrect rect(n * width_, 0.0f, (n * width_) + width_, height_);
        // ������`�悷����W���v�Z
        GSvector2 pos{ position.x + i * width_, position.y };
        // �������P���`��
        gsDrawSprite2D(texture_, &pos, &rect, NULL, NULL, NULL, 0);
    }
}

