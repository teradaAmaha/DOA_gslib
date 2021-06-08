#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include"Item.h"
#include "TextureID.h"
#include "Base.h"
#include "EnemyGenerator.h"
#include"SceneManager.h"
#include"TitleScene.h"
#include "GamePlayScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"




// ゲームクラス
class MyGame : public gslib::Game {

    //シーンマネージャー
    SceneManager scene_manager_;
 
    // 開始
    void start() override {
        // タイトルシーンの追加
        scene_manager_.add("TitleScene", new TitleScene());
        // ゲームプレイシーンの追加
        scene_manager_.add("GamePlayScene", new GamePlayScene());
        //ゲームクリアーシーンの追加
        scene_manager_.add("GameClearScene", new GameClearScene());
        //ゲームオーバーシーンの追加
        scene_manager_.add("GameOverScene", new GameOverScene());
        // タイトルシーンから開始
        scene_manager_.change("TitleScene");
        //scene_manager_.change("GameClearScene");

        //画面大きさ（620, 460?）
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