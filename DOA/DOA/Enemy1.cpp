#include "Enemy1.h"
#include "TextureID.h"

// �R���X�g���N�^
Enemy1::Enemy1(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "EnemyTag";
    name_ = "Enemy";
    position_ = position;
    velocity_ = GSvector2{ 0.0f, 1.5f };
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 32.0f, 32.0f };
    texture_ = TextureEnemy;

}

// �X�V
void Enemy1::update(float delta_time) {
    position_ += velocity_ * delta_time;
}

void Enemy1::draw() {

}

// �Փ˃��A�N�V����
void Enemy1::react(Actor& other) {

    if (other.tag() == "BaseTag") {

        die();

    }

    if (other.tag() == "PlayerBulletTag") {

        die();

    }


}

