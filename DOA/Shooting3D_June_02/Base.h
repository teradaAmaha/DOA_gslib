#ifndef BASE_H_
#define BASE_H_

#include "Actor.h"

class IWorld;
// プレーヤ
class Base{
public:
    // コンストラクタ
    Base(IWorld* world, const GSvector3& position);
    // 更新
    void update(float delta_time);
    // 描画
    void draw() const ;
    // 衝突処理
    void under_over(Actor& other) const;
protected:
    IWorld* world_{ nullptr };

    GStransform transform_;
};


#endif

