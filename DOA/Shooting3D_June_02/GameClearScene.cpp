#include "GameClearScene.h"
#include <iostream>
#include "World.h"
#include <gslib.h>
#include "Assets.h"
void GameClearScene::start()
{
    is_end_ = false;
    gsLoadTexture(Texture_BGc, "Assets/2DSprite/gmc.png");
    gsLoadTexture(Texture_Gac, "Assets/2DSprite/GameC.png");
}

void GameClearScene::update(float delta_time)
{
    if (gsGetKeyTrigger(GKEY_RETURN))
    {
        is_end_ = true;
    }
}

void GameClearScene::draw() const
{
    gsDrawSprite2D(Texture_BGc, NULL, NULL, NULL, NULL, NULL, 0.0f);
    gsDrawSprite2D(Texture_Gac, &GSvector2{ 280.0f,200.0f }, NULL, NULL, NULL, &GSvector2{ 0.3f,0.3f }, 0.0f);
}

bool GameClearScene::is_end() const
{
    return is_end_;
}

std::string GameClearScene::next() const
{
    return "TitleScene";
}

void GameClearScene::end()
{
}
