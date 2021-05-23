#ifndef ITEM_H_
#define ITEM_H_

#include"Actor.h"

//アイテムクラス
class Item:public Actor
{
public:
    // コンストラクタ
    Item(IWorld* world, const GSvector2& position);
    // 更新
    virtual void update(float delta_time) override;
    // 衝突リアクション
    virtual void react(Actor& other) override;

private:
    // 弾発射タイマ
    float timer_{ 0.0f };


};

#endif