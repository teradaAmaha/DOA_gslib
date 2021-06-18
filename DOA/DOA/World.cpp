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
    
    actors_.draw();
    // スコアの描画
    score_.draw();
    timer_.draw();
    baselife.draw();
}

// ゲームオーバー
void World::game_over() {
    is_game_over_ = true;
     timer_.clear();
     baselife.clear();
}

// ゲームクリアー
void World::game_clear() {
    is_game_clear_ = true;
    timer_.clear();
   // Life.clear();
    baselife.clear();
}

// ゲームオーバーか？
bool World::is_game_over() const {
    return is_game_over_;
}

// ゲームクリアか？
bool World::is_game_clear() const {
    return is_game_clear_;
}



// 消去
void World::clear() {
    actors_.clear();
    // ゲームオーバーフラグの初期化
    is_game_over_ = false;
    // ゲームクリアフラグの初期化
    is_game_clear_ = false;
    // スコアの消去
    score_.clear();

}

// フィールドの取得
Field& World::field() {
    return field_;
}

//タイマーの減算
void World::sub_timer(int timer) {
    timer_.sub(timer);
}

void World::sub_hp(int hp) {
    baselife.sub(hp);
}

// アクターの追加（ワールド抽象インターフェースの実装）
void World::add_actor(Actor* actor) {
    actors_.add(actor);
}

// アクターの検索（ワールド抽象インターフェースの実装）
Actor* World::find_actor(const std::string& name) const {
    return actors_.find(name);
}
// スコアの加算
void World::add_score(int score) {
    score_.add(score);
}
