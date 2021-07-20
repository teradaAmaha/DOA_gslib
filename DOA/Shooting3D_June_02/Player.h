#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

// �v���[��
class Player : public Actor {
public:
    // �R���X�g���N�^
    Player(IWorld* world, const GSvector3& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;

private:

    bool isItem = false;
    int timer_ = 0;
    float angle_1 = 0.01;
    float angle_2 = -0.01;

private:
    enum class State
    {
        nomal,
        get_item_,

    };

    void nomal_state_(float delta_time);//�ʏ���
    void get_item_state_(float delta_time);//�A�C�e�����莞
    //�������
    State state_{ State::nomal };


};


#endif
