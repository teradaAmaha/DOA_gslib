#ifndef PLAYER_BULLET_H_
#define PLAYER_BULLET_H_

#include "Actor.h"

class PlayerBullet : public Actor {
public:
	//コンストラクタ
	PlayerBullet(IWorld* world, const GSvector3& position, const GSvector3& velocity);
	//更新
	virtual void update(float delta_time) override;
	//半透明オブジェクト
	virtual void draw_transparent() const override;
	//衝突リアクション
	virtual void react(Actor& other) override;
};

#endif
