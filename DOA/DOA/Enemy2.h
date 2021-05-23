#ifndef ENEMY_2_H_
#define ENEMY_2_H_

#include "Actor.h"

class Enemy2 : public Actor
{
public:
	Enemy2(IWorld* world, const GSvector2& position);

	virtual void update(float delta_time) override;

	virtual void react(Actor& other)override;
};

#endif

