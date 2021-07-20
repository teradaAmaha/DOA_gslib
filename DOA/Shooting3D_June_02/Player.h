#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

// プレーヤ
class Player : public Actor {
public:
    // コンストラクタ
    Player(IWorld* world, const GSvector3& position);
    // 更新
    virtual void update(float delta_time) override;
    // 描画
    virtual void draw() const override;
    // 衝突処理
    virtual void react(Actor& other) override;

private:

    bool isItem = false;
    int timer_ = 0;
    float angle_1 = 0.01;
    float angle_2 = -0.01;

private:
    enum class State
    {
        nomal,
        get_item_,

    };

    void nomal_state_(float delta_time);//通常状態
    void get_item_state_(float delta_time);//アイテム入手時
    //初期状態
    State state_{ State::nomal };


};


#endif
