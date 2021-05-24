#include "EnemyBeam.h"
#include "IWorld.h"
#include "TextureID.h"

// コンストラクタ
EnemyBeam::EnemyBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity) {
    world_ = world;
    tag_ = "EnemyBulletTag"; // 敵の弾用のタグ
    name_ = "EnemyBeam";
    position_ = position;
    velocity_ = velocity;
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 16.0f, 16.0f };
    texture_ = TextureEnemyBeam;
}

// 更新
void EnemyBeam::update(float delta_time) {
    position_ += velocity_ * delta_time;
    //if (world_->field().is_outside(collider())) {   // 拡張エリアの外側か？
    //    die(); // 拡張エリアの外側に出たら死亡する
    //}
}

// 衝突リアクション
void EnemyBeam::react(Actor& other) {
    if (other.tag() == "PlayerTag") {
        die();
    }
}

