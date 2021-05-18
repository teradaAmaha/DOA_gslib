#ifndef ENEMY_H_
#define ENEMY_H_

#include "Actor.h"

// 敵クラス
class Enemy : public Actor {
public:
    // コンストラクタ
    Enemy(IWorld* world, const GSvector2& position);
    // 更新
    virtual void update(float delta_time) override;
    // 衝突リアクション
    virtual void react(Actor& other) override;
};

#endif

