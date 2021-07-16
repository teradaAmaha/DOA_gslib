#ifndef BOMBOSS_H_
#define BOMBOSS_H_

#include "Actor.h"

// �G
class Bomboss : public Actor {
public:
    // �R���X�g���N�^
    Bomboss(IWorld* world, const GSvector3& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;

private:
    // �ړ��p�^�C�}
    float moving_timer_{ 0.0f };
    // �V���b�g�p�^�C�}
    float shooting_timer_{ 0.0f };

    int asteroid{ 0 };

    float life{ 10.0f };

    float timer{ 0.0f };

    float xR{ 90.0f };
};

#endif
