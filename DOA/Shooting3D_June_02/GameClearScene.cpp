#include "GameClearScene.h"
#include <iostream>
#include "World.h"
#include <gslib.h>
void GameClearScene::start()
{
    is_end_ = false;
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
