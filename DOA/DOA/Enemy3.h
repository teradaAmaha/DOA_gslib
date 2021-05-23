#ifndef ENEMY_3_H_
#define ENEMY_3_H_

#include "Actor.h"

class Enemy3 : public Actor
{
public:
	Enemy3(IWorld* world, const GSvector2& position_);

	virtual void update(float delata_time) override;

	virtual void react(Actor& other) override;
};

#endif
