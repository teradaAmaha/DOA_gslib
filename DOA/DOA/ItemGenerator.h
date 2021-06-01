
#ifndef ITEM_GEGERATOR_H
#define ITEM_GEGERATOR_H

#include "Actor.h"

class ItemGenerator :public Actor {
public:
	ItemGenerator(IWorld* world);

	virtual void update(float delta_time);

	virtual void draw() const override;
private:
	float timer_{ 0.0f };
	
};

#endif//ITEM_GEGERATOR_H