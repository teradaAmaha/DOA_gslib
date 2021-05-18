#include "Enemy.h"
#include "TextureID.h"

// �R���X�g���N�^
Enemy::Enemy(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "EnemyTag";
    name_ = "Enemy";
    position_ = position;
    velocity_ = GSvector2{ 0.0f, 1.5f };
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 32.0f, 32.0f };
    texture_ = TextureEnemy;
}

// �X�V
void Enemy::update(float delta_time) {
    position_ += velocity_ * delta_time;
}

// �Փ˃��A�N�V����
void Enemy::react(Actor& other) {
    if (other.tag() == "BaseTag") {
        die();
    }
}

