#include "GameOverScene.h"
#include <iostream>
#include "World.h"
#include <gslib.h>
#include "Assets.h"

void GameOverScene::start() {
	is_end_ = false;
	//gsLoadTexture(TextureNumber, "Assets/NUM.png");
	gsLoadTexture(Texture_BGo, "Assets/2DSprite/gmo.png");
	gsLoadTexture(Texture_Gao, "Assets/2DSprite/GameO.png");
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
	gsDrawSprite2D(Texture_BGo, NULL, NULL, NULL, NULL, NULL, 0.0f);
	gsDrawSprite2D(Texture_Gao, &GSvector2{280.0f,200.0f}, NULL, NULL, NULL, &GSvector2{ 0.3f,0.3f }, 0.0f);

}

bool GameOverScene::is_end() const {
	return is_end_;
}

std::string GameOverScene::next() const {
	return "TitleScene";
}

void GameOverScene::end()
{
	//gsDeleteTexture(TextureNumber);
}