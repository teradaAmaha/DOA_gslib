#include "GameOverScene.h"
#include <iostream>
#include "World.h"
#include "NumberTexture.h"
#include "TextureID.h"
#include <gslib.h>
#include "Score.h"

void GameOverScene::start() {
	is_end_ = false;
	gsLoadTexture(TextureNumber, "Assets/NUM.png");
}

void GameOverScene::update(float delta_time)
{
	if (gsGetKeyTrigger(GKEY_RETURN))
	{
		is_end_ = true;
	}
}


void GameOverScene::draw() const {
	//static const NumberTexture number{ TextureNumber, 16, 16 };
	//number.draw(GSvector2{ 520, 0 }, score_, 7);
	//gsDrawSprite2D(TextureEnemy, NULL, NULL, NULL, NULL, NULL, 0.0f);
}

bool GameOverScene::is_end() const {
	return is_end_;
}

std::string GameOverScene::next() const {
	return "TitleScene";
}

void GameOverScene::end()
{
	gsDeleteTexture(TextureNumber);
}