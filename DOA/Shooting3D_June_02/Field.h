#ifndef FIELD_H_
#define FIELD_H_

#include <gslib.h>

// �t�B�[���h�N���X
class Field {
public:
    // �R���X�g���N�^
    Field(GSuint bg);
    // �X�V
    void update(float delta_time);
    // �`��
    void draw() const;
    // �t�B�[���h�����H
    bool is_inside(const GSvector3& position) const;
    // �t�B�[���h�O���H
    bool is_outside(const GSvector3& position) const;
    //�t�B�[���h���o�Ă邩�H
    bool is_over(const GSvector3& position) const;

    // �R�s�[�֎~
    Field(const Field& other) = delete;
    Field& operator = (const Field& other) = delete;
private:
    // �w�i�摜
    GSuint  bg_{ 0 };
    // �X�N���[���ʒu
    float   scroll_{ 0.0f };
};

#endif
