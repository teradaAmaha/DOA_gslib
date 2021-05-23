#ifndef ENEMY_4_H_
#define ENEMY_4_H_

#include "Actor.h"

class Enemy4 : public Actor
{
public:
	Enemy4(IWorld* world, const GSvector2& position);

	virtual void update(float delta_time) override;

	virtual void react(Actor& other)override;

};

#endif

