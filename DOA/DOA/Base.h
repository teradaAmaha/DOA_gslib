#ifndef BASE_H_
#define BASE_H_
#include "Actor.h"

class Base : public Actor
{
public:
	Base(IWorld* world, const GSvector2& position);

	virtual void update(float delta_time) override;

	virtual void react(Actor& other) override;

	void alive(); //ライフが０になれば死ぬ
private:
	int life = 20;
};

#endif

