#ifndef ENEMY_H_
#define ENEMY_H_

#include "Actor.h"

// �G�N���X
class Enemy : public Actor {
public:
    // �R���X�g���N�^
    Enemy(IWorld* world, const GSvector2& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �Փ˃��A�N�V����
    virtual void react(Actor& other) override;
};

#endif

