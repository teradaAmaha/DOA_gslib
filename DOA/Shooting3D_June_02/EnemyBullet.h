#ifndef ENEMY_BULLET_H_
#define ENEMY_BULLET_H_

#include "Actor.h"

// 敵弾クラス
class EnemyBullet : public Actor {
public:
    // コンストラクタ
    EnemyBullet(IWorld* world, const GSvector3& position, const GSvector3& velocity);
    // 更新
    virtual void update(float delta_time) override;
    // 半透明オブジェクトの描画
    virtual void draw_transparent() const override;
    // 衝突リアクション
    virtual void react(Actor& other) override;
};

#endif