#ifndef BASE_H_
#define BASE_H_

#include "Actor.h"

// �v���[��
class Base : public Actor {
public:
    // �R���X�g���N�^
    Base(IWorld* world, const GSvector3& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;
};


#endif

