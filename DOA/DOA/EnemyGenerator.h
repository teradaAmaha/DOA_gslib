#ifndef ENEMY_GENERATOR_H_
#define ENEMY_GENERATOR_H_

#include "Actor.h"

class EnemyGenerator :public Actor {
public:
	EnemyGenerator(IWorld* world);

	virtual void update(float delta_time);

	virtual void draw() const override;
private:
	float timer_1_{ 0.0f };
	float timer_2_{ 0.0f };
	float timer_3_{ 0.0f };
	float timer_4_{ 0.0f };
};

#endif
