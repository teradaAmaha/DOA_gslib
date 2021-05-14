#ifndef IWORLD_H_
#define IWORLD_H_

#include <string>

class IWorld {
public:
	//���z�f�X�g���N�^
	virutual ~IWorld() = default;
	//�A�N�^�[��ǉ�
	virtual void add_actor(Actor* actor) = 0;
	//�A�N�^�[�̌���
	virtual Actor* find_actor(const std::string& name) const = 0;

	//���̃N���X���ۃN���X��������̎��ĂȂ��B�S���|�C���^����
};

#endif 

