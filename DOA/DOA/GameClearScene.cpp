#include "GameClearScene.h"
#include <iostream>
#include "World.h"
#include "NumberTexture.h"
#include "TextureID.h"
#include <gslib.h>
#include "Score.h"

void GameClearScene::start() {
	is_end_ = false;
	gsLoadTexture(TextureNumber, "Assets/NUM.png");
}

void GameClearScene::update(float delta_time) 
{
	if (gsGetKeyTrigger(GKEY_RETURN))
	{
		is_end_ = true;
	}
}


void GameClearScene::draw() const {
	static const NumberTexture number{ TextureNumber, 16, 16 };
	number.draw(GSvector2{ 520, 0 }, score_, 7);
	//gsDrawSprite2D(TextureEnemy, NULL, NULL, NULL, NULL, NULL, 0.0f);
}

bool GameClearScene::is_end() const {
	return is_end_;
}

std::string GameClearScene::next() const{
	return "TitleScene";
}

void GameClearScene::end()
{
	gsDeleteTexture(TextureNumber);
}
//
//void GameClearScene::draw_background(GSuint id, float scroll) const {
//	GSrect rect{ scroll, 0.0f, scroll + 640.0f, 480.0f };
//	gsDrawSprite2D(id, NULL, &rect, NULL, NULL, NULL, 0.0f);
//}