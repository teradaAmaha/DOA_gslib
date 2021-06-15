#ifndef TEMPORARY_PLAYER_H_
#define TEMPORARY_PLAYER_H_


#include "Actor.h"

class TemporaryPlayer : public Actor
{
public:
    // �R���X�g���N�^
    TemporaryPlayer(IWorld* world, const GSvector3& position3D);
    // �X�V
    virtual void update(float delta_time) override;
    // �Փ˃��A�N�V����
    //virtual void react(Actor& other) override;
    const GSvector2& minX() const;
    const GSvector2& maxX() const;

private:
    int counter = 0;
    GSvector2 min_x_{ -20.0f,380.0f };
    GSvector2 max_x_{ 580.0f,380.0f };

};

#endif
