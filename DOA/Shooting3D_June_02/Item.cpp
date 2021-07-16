#include "Item.h"
#include "Assets.h"
#include "IWorld.h"





// �R���X�g���N�^
Item::Item(IWorld* world, const GSvector3& position,const GSvector3& velocity) {
    world_ = world;
    name_ = "Item";
    tag_ = "ItemTag";
    transform_.position(position);
    velocity_ = velocity;
    collider_ = BoundingSphere{ 25.0f };
}

// �X�V
void Item::update(float delta_time) {
    // �A�C�e���������v���X�����������悤�ɉ�]������
    transform_.eulerAngles(-180.0f, 180.0f, 0.0f);
    // �ړ�����i���[���h���W�n����Ɉړ��j
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    
    //GSvector3 position = transform_.position();
   

}

// �`��
void Item::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    //glScalef(7.5f, 7.5f, 7.5f);
    gsDrawMesh(Mesh_Item);
    glPopMatrix();
}

// �Փˏ���
void Item::react(Actor& other) {
    // �G�ƏՓ˂����ꍇ�͎��S
    if (other.tag() == "PlayerTag") {
        die();
    }
}