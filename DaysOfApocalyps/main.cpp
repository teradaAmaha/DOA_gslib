#include <GSgame.h>
<<<<<<< HEAD
#include "SceneManager.h"
#include "TitleScene.h"
#include "GamePlayScene.h"

// ゲームクラス
class MyGame : public gslib::Game {
    // シーンマネージャー
    SceneManager scene_manager_;
    // 開始
    void start() override {
        // タイトルシーンの追加
        scene_manager_.add("TitleScene", new TitleScene());
        // ゲームプレイシーンの追加
        scene_manager_.add("GamePlayScene", new GamePlayScene());
        // タイトルシーンから開始
        scene_manager_.change("TitleScene");
    }
    // 更新
    void update(float delta_time) override {
        // シーンの更新
        scene_manager_.update(delta_time);
    }
    // 描画
    void draw() override {
        // シーンの描画
        scene_manager_.draw();
    }
    // 終了
    void end() override {
        // シーンの終了
        scene_manager_.end();
    }
};

// メイン関数
int main() {
    return MyGame().run();
}
=======

class MyGame : public gslib::Game {

};

int main() {
	return MyGame().run();
}
>>>>>>> f59b5c3d60bddca32cde8e3e5ab799981391b42f
