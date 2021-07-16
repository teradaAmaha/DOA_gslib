#ifndef  DAMAGE_ASSET_H_
#define  DAMAGE_ASSET_H_

#include "Actor.h"

// 隕石クラス
class DamageAssets : public Actor {
public:
    // コンストラクタ
    DamageAssets(IWorld* world, const GSvector3& position);
    // 更新
    virtual void update(float delta_time) override;
    // 描画
    virtual void draw() const override;
    // 衝突処理
    virtual void react(Actor& other) override;

private:

    int life = 6;
};

#endif // ! DAMAGE_ASSET_H_

