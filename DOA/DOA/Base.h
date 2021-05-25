#ifndef BASE_H_
#define BASE_H_
#include "Actor.h"

class Base : public Actor
{
public:
	Base(IWorld* world, const GSvector2& position);

	virtual void update(float delta_time) override;

	virtual void draw() const override;

	virtual void react(Actor& other) override;

	void alive(); //ƒ‰ƒCƒt‚ª‚O‚É‚È‚ê‚ÎŽ€‚Ê
private:
	int life = 20;
	int counter = 0;
};

#endif

