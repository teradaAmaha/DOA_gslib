#ifndef PLAYER_BEAM_H_
#define PLAYER_BEAM_H_

#include "Actor.h"

// プレーヤー弾
class PlayerBeam1 : public Actor {
public:
    // コンストラクタ
    PlayerBeam1(IWorld* world, const GSvector2& position, const GSvector2& velocity);
    // 更新
    virtual void update(float delta_time) override;
    // 衝突リアクション
    virtual void react(Actor& other) override;
};

#endif
