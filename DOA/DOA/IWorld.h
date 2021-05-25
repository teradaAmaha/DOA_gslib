#ifndef IWORLD_H_
#define IWORLD_H_

#include <string>

class Actor; // �A�N�^�[�N���X�̑O���錾

// ���[���h���ۃC���^�[�t�F�[�X
class IWorld {
public:
    // ���z�f�X�g���N�^
    virtual ~IWorld() = default;
    // �A�N�^�[��ǉ�
    virtual void add_actor(Actor* actor) = 0;
    // �A�N�^�[�̌���
    virtual Actor* find_actor(const std::string& name) const = 0;
    // �Q�[���I�[�o�[
    virtual void game_over() = 0;
    // �Q�[���N���A
    virtual void game_clear() = 0;

};

#endif
