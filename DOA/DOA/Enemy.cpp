#include "Enemy.h"
#include "TextureID.h"

// コンストラクタ
Enemy::Enemy(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "EnemyTag";
    name_ = "Enemy";
    position_ = position;
    velocity_ = GSvector2{ 0.0f, 1.5f };
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 32.0f, 32.0f };
    texture_ = TextureEnemy;
}

// 更新
void Enemy::update(float delta_time) {
    position_ += velocity_ * delta_time;
}

// 衝突リアクション
void Enemy::react(Actor& other) {
    if (other.tag() == "BaseTag") {
        die();
    }
}

