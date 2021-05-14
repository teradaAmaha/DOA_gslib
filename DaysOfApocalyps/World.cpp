#include "World.h"

// 更新
void World::update(float delta_time) {
    field_.update(delta_time);    // フィールドの更新
    actors_.update(delta_time);	// 更新
    actors_.collide();		// 衝突判定
    actors_.remove();		// 死亡しているアクターの削除
}

// 描画
void World::draw() const {
    field_.draw();
    actors_.draw();
    // スコアの描画
    score_.draw();

}


// 消去
void World::clear() {
    // アクターの消去
    actors_.clear();
    // スコアの消去
    score_.clear();
    // ゲームオーバーフラグの初期化
    is_game_over_ = false;
    // ゲームクリアフラグの初期化
    is_game_clear_ = false;
}

// アクターの追加（ワールド抽象インターフェースの実装）
void World::add_actor(Actor* actor) {
    actors_.add(actor);
}

// アクターの検索（ワールド抽象インターフェースの実装）
Actor* World::find_actor(const std::string& name) const {
    return actors_.find(name);
}
// フィールドの取得
Field& World::field() {
    return field_;
}

// スコアの加算
void World::add_score(int score) {
    score_.add(score);
}

// ゲームオーバー
void World::game_over() {
    is_game_over_ = true;
}

// ゲームクリアー
void World::game_clear() {
    is_game_clear_ = true;
}

// ゲームオーバーか？
bool World::is_game_over() const {
    return is_game_over_;
}

// ゲームクリアか？
bool World::is_game_clear() const {
    return is_game_clear_;
}
