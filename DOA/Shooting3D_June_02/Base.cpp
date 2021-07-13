#include "Base.h"
#include "Assets.h"


// �R���X�g���N�^
Base::Base(IWorld* world, const GSvector3& position) {
    world_ = world;
    name_ = "Base";
    tag_ = "BaseTag";
    transform_.position(position);
    collider_ = BoundingSphere{ 100.0f };
}

// �X�V
void Base::update(float delta_time) {
  
   
   
}

// �`��
void Base::draw() const {
    const static GSvector2 position_Base{ 1.0f, 1.0f };

    gsDrawSprite2D(TextureBase, &position_Base, NULL, NULL, NULL, NULL, 0.0f);
}

// �Փˏ���
void Base::react(Actor& other) {
    // �G�ƏՓ˂����ꍇ�͎��S
    if (other.tag() == "EnemyTag") {
        die();
    }
}