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

