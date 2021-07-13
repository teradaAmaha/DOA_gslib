#include "Base.h"
#include "Assets.h"
#include "IWorld.h"
#include "Field.h"
#include "Actor.h"

// �R���X�g���N�^
Base::Base(IWorld* world, const GSvector3& position){
    world_ = world;
    transform_.position(position);
}

// �X�V
void Base::update(float delta_time) {
  
   
   
}

// �`��
void Base::draw() const {
    const static GSvector2 position_Base{ 1.0f, 400.0f };

    gsDrawSprite2D(TextureBase, &position_Base, NULL, NULL, NULL, NULL, 0.0f);
}

// �Փˏ���
void Base::under_over(Actor& other) const{
    // �G�ƏՓ˂����ꍇ�͎��S
    if (world_->field()->is_over(transform_.position())) {

    }
}