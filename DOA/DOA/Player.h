#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

// プレーヤークラス
class Player : public Actor {
public:
    // コンストラクタ
    Player(IWorld* world, const GSvector2& position);
    // 更新
    virtual void update(float delta_time) override;
    // 衝突リアクション
    //virtual void react(Actor& other) override;
    const GSvector2& minX() const;
    const GSvector2& maxX() const;
    
private:
    int counter = 0;
    GSvector2 min_x_{ -20.0f,380.0f };
    GSvector2 max_x_{ 1200.0f,380.0f };
    
};

#endif