#include "Enemy1.h"
#include "IWorld.h"
#include "EnemyBeam.h"
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

    timer_ += delta_time;
    // 120�t���[���o�߂������H
    if (timer_ > 120.0f) {
        // �v���[������������
        Actor* player = world_->find_actor("Player");
        if (player != nullptr) {
            // �v���[���[�Ɍ������x�N�g�����v�Z����
            GSvector2 velocity = (player->position() - position_).normalized() * 4.0f;
            // �G�̒e�N���X�𐶐����āA���[���h�ɒǉ�����
            world_->add_actor(new EnemyBeam{ world_, position_, velocity });
        }
        timer_ = 0.0f;
    }
    //// �g���G���A�O�Ȃ玀�S
    //if (world_->field().is_outside(collider())) {
    //    die();
    //}

}

void Enemy1::draw() {

}

// �Փ˃��A�N�V����
void Enemy1::react(Actor& other) {

    if (other.tag() == "BaseTag") {

        die();

    }


}

