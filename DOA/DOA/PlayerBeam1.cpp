#include "PlayerBeam1.h"
#include "IWorld.h"
#include "TextureID.h"

// コンストラクタ
PlayerBeam1::PlayerBeam1(IWorld* world, const GSvector2& position, const GSvector2& velocity) {
    world_ = world;
    tag_ = "PlayerBulletTag"; // プレーヤの弾用のタグ
    name_ = "PlayerBeam";
    position_ = position;
    velocity_ = GSvector2{ 0.0f,3.0f };
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 16.0f, 8.0f };
    /*texture_ = TexturePlayerBeam;*/
    angle_ = { 90.0f };
}

// 更新
void PlayerBeam1::update(float delta_time) {
    position_ -= velocity_ * delta_time;
    //if (world_->field().is_outside(collider())) {   // 拡張エリアの外側か？
    //    die(); // 拡張エリアの外側に出たら死亡する
    //}
}

// 衝突リアクション
void PlayerBeam1::react(Actor& other) {
    if (other.tag() == "EnemyTag") {
        die();
    }
}

