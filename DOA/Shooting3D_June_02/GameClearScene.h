#ifndef GAME_CLEAR_SCENE_H_
#define GAME_CLEAR_SCENE_H_


#include "IScene.h"

class GameClearScene :public IScene
{
public:

	virtual void start() override;

	virtual void update(float delta_time) override;

	virtual void draw() const override;

	virtual bool is_end() const override;

	virtual std::string next() const override;

	virtual void end() override;


private:
	bool is_end_{ false };
	
	int score_;
};

#endif // !GAME_CLEAR_SCENE_H_

