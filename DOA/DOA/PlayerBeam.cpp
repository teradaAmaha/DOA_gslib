#include "PlayerBeam.h"
#include "IWorld.h"
#include "TextureID.h"

// �R���X�g���N�^
PlayerBeam::PlayerBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity) {
    world_ = world;
    tag_ = "PlayerBulletTag"; // �v���[���̒e�p�̃^�O
    name_ = "PlayerBeam";
    position_ = position;
    velocity_ = velocity;
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 16.0f, 8.0f };
    texture_ = TexturePlayerBeam;
}

// �X�V
void PlayerBeam::update(float delta_time) {
    position_ += velocity_ * delta_time;
    //if (world_->field().is_outside(collider())) {   // �g���G���A�̊O�����H
    //    die(); // �g���G���A�̊O���ɏo���玀�S����
    //}
}

// �Փ˃��A�N�V����
void PlayerBeam::react(Actor& other) {
    if (other.tag() == "EnemyTag") {
        die();
    }
}

