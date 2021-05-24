#include "Enemy4.h"
#include "TextureID.h"

// コンストラクタ
Enemy4::Enemy4(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "Enemy4Tag";
    name_ = "Enemy";
    position_ = position;
    velocity_ = GSvector2{ 0.0f, 1.5f };
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 32.0f, 32.0f };
    texture_ = TextureEnemy4;

}

// 更新
void Enemy4::update(float delta_time) {
    position_ += velocity_ * delta_time;
}

// 衝突リアクション
void Enemy4::react(Actor& other) {

    if (other.tag() == "BaseTag") {

        die();

    }
    if (other.tag() == "PlayerBulletTag") {

        die();

    }
}