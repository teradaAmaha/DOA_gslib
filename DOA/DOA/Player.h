#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

// �v���[���[�N���X
class Player : public Actor {
public:
    // �R���X�g���N�^
    Player(IWorld* world, const GSvector2& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �Փ˃��A�N�V����
    //virtual void react(Actor& other) override;
};

#endif