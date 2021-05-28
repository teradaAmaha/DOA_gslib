#ifndef IWORLD_H_
#define IWORLD_H_

#include <string>

class Actor; // �A�N�^�[�N���X�̑O���錾
class Field;

// ���[���h���ۃC���^�[�t�F�[�X
class IWorld {
public:
    // ���z�f�X�g���N�^
    virtual ~IWorld() = default;
    // �A�N�^�[��ǉ�
    virtual void add_actor(Actor* actor) = 0;
    // �A�N�^�[�̌���
    virtual Actor* find_actor(const std::string& name) const = 0;
    // �t�B�[���h�̎擾
    virtual Field& field() = 0;
    // �X�R�A�̉��Z
    virtual void add_score(int score) = 0;

};

#endif
