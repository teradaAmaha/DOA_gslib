#include "SceneManager.h"
#include "SceneNull.h"

static SceneNull scene_null; //nullシーン(何もしないダミーシーン)

SceneManager::SceneManager() :current_scene_ { &scene_null }
{

}

SceneManager::~SceneManager()
{
	clear();
}

void SceneManager::update(float delta_time)
{
    // シーンの更新
    current_scene_->update(delta_time);
    // シーンが終了しているか？
    if (current_scene_->is_end()) {
        // シーンを変更する
        change(current_scene_->next());
    }
}

void SceneManager::draw() const
{
    // 現在のシーンを描画
    current_scene_->draw();
}

void SceneManager::end()
{
    // 現在のシーンを終了
    current_scene_->end();
    // nullシーンにしておく
    current_scene_ = &scene_null;
}


void SceneManager::add(const std::string& name, IScene* scene)
{
    scenes_[name] = scene;
}

void SceneManager::change(const std::string& name) {
    // 現在のシーンを終了
    end();
    // 現在のシーンを変更
    current_scene_ = scenes_[name];
    // 現在のシーンを開始
    current_scene_->start();
}

void SceneManager::clear()
{
    end();
    for (auto& pair : scenes_) {
        delete pair.second;
    }
    scenes_.clear();
}
