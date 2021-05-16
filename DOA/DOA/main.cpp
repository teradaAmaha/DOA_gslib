#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureID.h"

// ゲームクラス
class MyGame : public gslib::Game {
    // ワールドクラス
    World world_;
    // 開始
    void start() override {
        // テクスチャの読み込み
        gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
        gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
        // プレーヤーを追加
        world_.add_actor(new Player{ &world_, GSvector2{ 0.0f, 240.0f } });
        // 敵を3体追加
        world_.add_actor(new Enemy{ &world_, GSvector2{ 640.0f, 120.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 640.0f, 240.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 640.0f, 360.0f } });
    }
    // 更新
    void update(float delta_time) override {
        // 更新
        world_.update(delta_time);
    }
    // 描画
    void draw() override {
        // 描画
        world_.draw();
    }
    // 終了
    void end() override {
        // 消去
        world_.clear();
        // テクスチャの削除
        gsDeleteTexture(TexturePlayer);
        gsDeleteTexture(TextureEnemy);
    }
};

// メイン関数
int main() {
    return MyGame().run();
}

