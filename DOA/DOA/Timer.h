#ifndef TIMER_H_
#define TIMER_H_

class IWorld;

class Timer {
public:
	//�R���X�g���N�^
	Timer(int timer = 3000);
	//�^�C�}�[�̏�����
	void initialize(int timer = 3000);
	//�^�C�}�[�̌��Z
	void sub(int timer);
	//�^�C�}�[�̕`��
	void draw() const;
	//�^�C�}�[�̎擾
	int get() const;
	//�^�C�}�[�̃N���A
	void clear();
	//�^�C�}�[��0�ɂȂ��
	void zero(int timeUp);

private:
	//�^�C�}�[
	int timer_;
	IWorld* world_{ world_ };

};

#endif
