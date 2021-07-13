#include "Base.h"
#include "Assets.h"


// コンストラクタ
Base::Base(IWorld* world, const GSvector3& position) {
    world_ = world;
    name_ = "Base";
    tag_ = "BaseTag";
    transform_.position(position);
    collider_ = BoundingSphere{ 100.0f };
}

// 更新
void Base::update(float delta_time) {
  
   
   
}

// 描画
void Base::draw() const {
    const static GSvector2 position_Base{ 1.0f, 1.0f };

    gsDrawSprite2D(TextureBase, &position_Base, NULL, NULL, NULL, NULL, 0.0f);
}

// 衝突処理
void Base::react(Actor& other) {
    // 敵と衝突した場合は死亡
    if (other.tag() == "EnemyTag") {
        die();
    }
}