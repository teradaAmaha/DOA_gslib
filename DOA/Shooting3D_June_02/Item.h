#ifndef ITEM_H_
#define ITEM_H_

#include "Actor.h"

// �v���[��
class Item : public Actor {
public:
    // �R���X�g���N�^
    Item(IWorld* world, const GSvector3& position, const GSvector3& velocity);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;
};


#endif
