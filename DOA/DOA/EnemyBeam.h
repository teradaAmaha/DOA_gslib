#ifndef ENEMY_BEAM_H_
#define ENEMY_BEAM_H_

#include "Actor.h"

// 敵弾クラス
class EnemyBeam : public Actor {
public:
    // コンストラクタ
    EnemyBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity);
    // 更新
    virtual void update(float delta_time) override;
    // 衝突リアクション
    virtual void react(Actor& other) override;
};

#endif


