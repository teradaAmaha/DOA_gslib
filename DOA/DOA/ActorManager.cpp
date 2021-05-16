#include "ActorManager.h"
#include "Actor.h"

// デストラクタ
ActorManager::~ActorManager() {
    clear();
}

// アクターの追加
void ActorManager::add(Actor* actor) {
    actors_.push_back(actor);
}

// アクターの更新
void ActorManager::update(float delta_time) {
    for (auto actor : actors_) {
        actor->update(delta_time);
    }
}

// アクターの描画
void ActorManager::draw() const {
    for (auto actor : actors_) {
        actor->draw();
    }
}

// アクターのGUI描画
void ActorManager::draw_gui() const {
    for (auto actor : actors_) {
        actor->draw_gui();
    }
}

// アクターの衝突判定
void ActorManager::collide() {
    for (auto i = actors_.begin(); i != actors_.end(); ++i) {
        for (auto j = std::next(i); j != actors_.end(); ++j) {
            (*i)->collide(**j);
        }
    }
}

// 死亡しているアクターの削除
void ActorManager::remove() {
    for (auto i = actors_.begin(); i != actors_.end(); ) {
        // 死亡しているか？
        if ((*i)->is_dead()) {
            delete* i;             // アクターを削除
            i = actors_.erase(i);  // リストから取り除く
        }
        else {
            ++i;
        }
    }
}

// アクターの検索
Actor* ActorManager::find(const std::string& name) const {
    for (auto actor : actors_) {
        // 名前が一致しているか？
        if (actor->name() == name) {
            return actor;  // 名前が一致したアクターを返す
        }
    }
    return nullptr; // 見つからない場合は、nullポインタを返す
}

// 消去
void ActorManager::clear() {
    for (auto actor : actors_) {
        delete actor;  // アクターを削除
    }
    actors_.clear();   // リストを空にする
}