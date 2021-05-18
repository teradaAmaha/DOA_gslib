#include "Player.h"
#include "TextureID.h"  // �e�N�X�`��ID�̂��߂ɕK�v

// �R���X�g���N�^
Player::Player(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "PlayerTag";
    name_ = "Player";
    position_ = position;
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 64.0f, 40.0f };
    texture_ = TexturePlayer;
}

// �X�V
void Player::update(float delta_time) {
    GSvector2 direction{ 0.0f, 0.0f }; // �ړ�����
    if (gsGetKeyState(GKEY_LEFT)) {
        direction.x = -1.0f;
    }
    if (gsGetKeyState(GKEY_RIGHT)) {
        direction.x = 1.0f;
    }
    /* if (gsGetKeyState(GKEY_UP)) {
         direction.y = -1.0f;
     }
     if (gsGetKeyState(GKEY_DOWN)) {
         direction.y = 1.0f;
     }*/
    float speed = 8.0f; // �ړ��X�s�[�h
    // �ړ��ʂ̌v�Z
    velocity_ = direction.normalized() * speed;
    // ���W�̍X�V
    position_ += velocity_ * delta_time;
}

//// �Փ˃��A�N�V����
//void Player::react(Actor& other) {
//    // �G�̃^�O�����L�����N�^�ƏՓ˂������H
//    if (other.tag() == "EnemyTag") {
//        // ���S��Ԃɂ���
//        die();
//    }
//}