#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include "IScene.h"
#include <gslib.h>

class TitleScene :public IScene {
public:
	//�J�n
	virtual void start() override;
	//�X�V
	virtual void update(float delta_time) override;
	//�`��
	virtual void draw() const override;
	//�I�����Ă��邩
	virtual bool is_end() const override;
	//���̃V�[����Ԃ�
	virtual std::string next() const override;
	//�I��
	virtual void end() override;
private:
	//�I���t���O
	bool is_end_{ false };
	//�X�N���[���l
	float scroll_{ 0.0f };
};

#endif
