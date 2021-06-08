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

	void alive(); //���C�t���O�ɂȂ�Ύ���

	int get() const;
	//void damageArray();
private:
	int life = 100;
	int counter = 0;

	//float e1 = 3;
};

#endif

