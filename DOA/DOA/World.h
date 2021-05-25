#ifndef WORLD_H_
#define WORLD_H_

#include "IWorld.h"
#include "ActorManager.h"
#include "Field.h"


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
    // �t�B�[���h���擾
    virtual Field& field() override;
    // �R�s�[�֎~
    World(const World& other) = delete;
    World& operator = (const World& other) = delete;
private:
    // �A�N�^�[�}�l�[�W���[
    ActorManager actors_;
    // �t�B�[���h
    Field field_;
};

#endif



