#ifndef ENEMY_1_H_
#define ENEMY_1_H_

#include "Actor.h"

// 敵クラス
class Enemy1 : public Actor {
public:
    // コンストラクタ
    Enemy1(IWorld* world, const GSvector2& position);
    // 更新
    virtual void update(float delta_time) override;

    virtual void draw();
    // 衝突リアクション
    virtual void react(Actor& other) override;

private:
    // 弾発射タイマ
    float timer_{ 0.0f };
    int counter = 0;

};

#endif

