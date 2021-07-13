#ifndef PLAYER_BULLET_H_
#define PLAYER_BULLET_H_

#include "Actor.h"

class PlayerBullet : public Actor {
public:
	//�R���X�g���N�^
	PlayerBullet(IWorld* world, const GSvector3& position, const GSvector3& velocity);
	//�X�V
	virtual void update(float delta_time) override;
	//�������I�u�W�F�N�g
	virtual void draw_transparent() const override;
	//�Փ˃��A�N�V����
	virtual void react(Actor& other) override;
};

#endif