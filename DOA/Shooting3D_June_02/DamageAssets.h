#ifndef  DAMAGE_ASSET_H_
#define  DAMAGE_ASSET_H_

#include "Actor.h"

// 覐΃N���X
class DamageAssets : public Actor {
public:
    // �R���X�g���N�^
    DamageAssets(IWorld* world, const GSvector3& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;

private:

    int life = 6;
};

#endif // ! DAMAGE_ASSET_H_

