#ifndef ITEM_H_
#define ITEM_H_

#include "Actor.h"

// プレーヤ
class Item : public Actor {
public:
    // コンストラクタ
    Item(IWorld* world, const GSvector3& position, const GSvector3& velocity);
    // 更新
    virtual void update(float delta_time) override;
    // 描画
    virtual void draw() const override;
    // 衝突処理
    virtual void react(Actor& other) override;
};


#endif
