#ifndef WORLD_H_
#define WORLD_H_

#include "IWorld.h"
#include "ActorManager.h"
#include"Field.h"
#include "Score.h"
#include "Timer.h"
#include "BaseLife.h"
#include "Base.h"

// ���[���h�N���X
class World : public IWorld {
public:
    // �R���X�g���N�^
    World() = default;
    // �X�V
    void update(float delta_time);
    // �`��
    void draw() const;
    // ����
    void clear();
    // �A�N�^�[�̒ǉ��i���[���h���ۃC���^�[�t�F�[�X�̎����j
    virtual void add_actor(Actor* actor) override;
    // �A�N�^�[�̌����i���[���h���ۃC���^�[�t�F�[�X�̎����j
    virtual Actor* find_actor(const std::string& name) const override;
    //�t�B�[���h�̎擾
    virtual Field& field()override;
    // �X�R�A�̉��Z
    virtual void add_score(int score) override;
    //�^�C���̌��Z
    virtual void  sub_timer(int timer) override;
    //hp�̌��Z
    virtual void sub_hp(int hp) override;

    // �Q�[���I�[�o�[
    virtual void game_over() override;
    // �Q�[���N���A
    virtual void game_clear() override;

    // �Q�[���I�[�o�[���H
    bool is_game_over() const;
    // �Q�[���N���A���H
    bool is_game_clear() const;

    Timer& get_timer() {
        return timer_;
    };

  /*  Base* get_base(){
        return &life;
    };*/

    // �R�s�[�֎~
    World(const World& other) = delete;
    World& operator = (const World& other) = delete;
private:
    // �A�N�^�[�}�l�[�W���[
    ActorManager actors_;
    //�t�B�[���h
    Field field_;
    // �X�R�A
    Score		score_;
    //�^�C�}�[
    Timer timer_;

    //Base Life;

    BaseLife baselife;

    // �Q�[���I�[�o�[���H
    bool            is_game_over_{ false };
    // �Q�[���N���A���H
    bool            is_game_clear_{ false };

};

#endif



