#include "PlayerBeam.h"
#include "IWorld.h"
#include "Field.h"
#include "TextureID.h"

// コンストラクタ
PlayerBeam::PlayerBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity) {
    world_ = world;
    tag_ = "PlayerBulletTag"; // プレーヤの弾用のタグ
    name_ = "PlayerBeam";
    position_ = position;
    velocity_ = GSvector2{0.0f,3.0f};
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 16.0f, 8.0f };
    texture_ = TexturePlayerBeam;
    angle_ = { 90.0f };
}

// 更新
void PlayerBeam::update(float delta_time) {
    position_ -= velocity_ * delta_time * 1.5;
    //if (world_->field().is_outside(collider())) {   // 拡張エリアの外側か？
    //    die(); // 拡張エリアの外側に出たら死亡する
    //}

    position_ -= velocity_ * delta_time;
    if (world_->field().is_outside(collider())) {   // 拡張エリアの外側か？
        die(); // 拡張エリアの外側に出たら死亡する
    }

}

// 衝突リアクション
void PlayerBeam::react(Actor& other) {
    if (other.tag() == "Enemy1Tag") {
        die();
    }
    if (other.tag() == "Enemy2Tag") {
        die();
    }
    if (other.tag() == "Enemy3Tag") {
        die();
    }
    if (other.tag() == "Enemy4Tag") {
        die();
    }
}

