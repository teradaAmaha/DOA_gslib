#ifndef BASE_H_
#define BASE_H_
#include "Actor.h"

//class IWorld;

class Base : public Actor
{
public:
	Base(IWorld* world, const GSvector2& position);

	virtual void update(float delta_time) override;

	virtual void draw() const override;

	virtual void react(Actor& other) override;

	void alive(); //���C�t���O�ɂȂ�Ύ���

	void clear(); //�폜�㏉�������邽�߂ɕK�v�B�������������Ȃ���΁Aworld�N���A���������o�֐��œK�p�����Ȃ��Ƃ��B
				  //life�͂����Ă�Actor���S�����Ă���Ă�B�����疳���B
	int get() const;
	//void damageArray();
private:
	int life = 100;
	int counter = 0;

	//float e1 = 3;
};

#endif

