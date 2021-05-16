#include "World.h"

// 更新
void World::update(float delta_time) {
    actors_.update(delta_time);	// 更新
    actors_.collide();		// 衝突判定
    actors_.remove();		// 死亡しているアクターの削除
}

// 描画
void World::draw() const {
    actors_.draw();
}

// 消去
void World::clear() {
    actors_.clear();
}

// アクターの追加（ワールド抽象インターフェースの実装）
void World::add_actor(Actor* actor) {
    actors_.add(actor);
}

// アクターの検索（ワールド抽象インターフェースの実装）
Actor* World::find_actor(const std::string& name) const {
    return actors_.find(name);
}