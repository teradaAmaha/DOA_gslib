#ifndef ENEMY_H_
#define ENEMY_H_

#include "Actor.h"
#include "GamePlayScene.h"
// 敵
class Enemy : public Actor {
public:
    GamePlayScene g;
    // コンストラクタ
    Enemy(IWorld* world, const GSvector3& position);
    // 更新
    virtual void update(float delta_time) override;
    // 描画
    virtual void draw() const override;
    // 衝突処理
    virtual void react(Actor& other) override;
    
    virtual void over() const override;
private:
    // 移動用タイマ
    float moving_timer_{ 0.0f };
    // ショット用タイマ
    float shooting_timer_{ 0.0f };
};

#endif
