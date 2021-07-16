#ifndef BOMBOSS_H_
#define BOMBOSS_H_

#include "Actor.h"

// 敵
class Bomboss : public Actor {
public:
    // コンストラクタ
    Bomboss(IWorld* world, const GSvector3& position);
    // 更新
    virtual void update(float delta_time) override;
    // 描画
    virtual void draw() const override;
    // 衝突処理
    virtual void react(Actor& other) override;

private:
    // 移動用タイマ
    float moving_timer_{ 0.0f };
    // ショット用タイマ
    float shooting_timer_{ 0.0f };

    int asteroid{ 0 };

    float life{ 10.0f };

    float timer{ 0.0f };

    float xR{ 90.0f };
};

#endif
