#include <GSgame.h>
#include "Assets.h"
#include "ActorManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Light.h"
#include "Camera.h"
#include "Field.h"
#include "World.h"
#include"SceneManager.h"
#include"TitleScene.h"
#include "GamePlayScene.h"
#include "Enemy.h"
#include "GameOverScene.h"


// ゲームクラス
class MyGame : public gslib::Game {
public:
    MyGame() : gslib::Game{ 1280, 720, true } {
    }
    // ワールドクラス
    SceneManager scene_manager_;

    // 開始
    void start() override {

        // タイトルシーンの追加
        scene_manager_.add("TitleScene", new TitleScene());
        // ゲームプレイシーンの追加
        scene_manager_.add("GamePlayScene", new GamePlayScene());

        scene_manager_.add("GameOverScene", new GameOverScene());

        // タイトルシーンから開始
        scene_manager_.change("TitleScene");
    }
    // 更新
    void update(float delta_time) override {
        // ワールドクラスの更新
        scene_manager_.update(delta_time);
    }
    // 描画
    void draw() override {
        // ワールドクラスの描画
        scene_manager_.draw();
    }
    // 終了
    void end() override {
        scene_manager_.end();
    }
};

// メイン関数
int main() {
    return MyGame().run();
}

