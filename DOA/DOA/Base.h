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

	void alive(); //ライフが０になれば死ぬ

	void clear(); //削除後初期化するために必要。初期化したくなければ、worldクリア条件メンバ関数で適用させないとか。
				  //lifeはかってにActorが担当してくれてる。だから無視。
	int get() const;
	//void damageArray();
private:
	int life = 100;
	int counter = 0;

	//float e1 = 3;
};

#endif

