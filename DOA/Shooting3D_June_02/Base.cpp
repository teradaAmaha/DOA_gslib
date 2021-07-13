#include "Base.h"
#include "Assets.h"
#include "IWorld.h"
#include "Field.h"
#include "Actor.h"

// コンストラクタ
Base::Base(IWorld* world, const GSvector3& position){
    world_ = world;
    transform_.position(position);
}

// 更新
void Base::update(float delta_time) {
  
   
   
}

// 描画
void Base::draw() const {
    const static GSvector2 position_Base{ 1.0f, 400.0f };

    gsDrawSprite2D(TextureBase, &position_Base, NULL, NULL, NULL, NULL, 0.0f);
}

// 衝突処理
void Base::under_over(Actor& other) const{
    // 敵と衝突した場合は死亡
    if (world_->field()->is_over(transform_.position())) {

    }
}