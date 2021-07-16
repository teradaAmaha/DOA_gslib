#ifndef BASE_H_
#define BASE_H_

#include "Actor.h"

class IWorld;
// �v���[��
class Base{
public:
    // �R���X�g���N�^
    Base(IWorld* world, const GSvector3& position);
    // �X�V
    void update(float delta_time);
    // �`��
    void draw() const ;
    // �Փˏ���
    void under_over(Actor& other) const;
protected:
    IWorld* world_{ nullptr };

    GStransform transform_;
};


#endif

