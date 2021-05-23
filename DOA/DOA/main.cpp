#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "TextureID.h"
#include "Base.h"

// ゲームクラス
class MyGame : public gslib::Game {
    // ワールドクラス
    World world_;
    // 開始
    void start() override {
        // テクスチャの読み込み
        gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
        gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");

        gsLoadTexture(TextureItem, "Assets/ITEM.png");


        gsLoadTexture(TexturePlayerBeam, "Assets/BEAM.png");
        gsLoadTexture(TextureEnemyBeam, "Assets/EBEAM.png");

        gsLoadTexture(TextureBase, "Assets/base.png");
        gsLoadTexture(TextureEnemy2, "Assets/ENEMY2.png");
        gsLoadTexture(TextureEnemy3, "Assets/ENEMY3.png");
        gsLoadTexture(TextureEnemy4, "Assets/ENEMY4.png");
        gsLoadTexture(TextureBoss, "Assets/BOSS.png");

        // プレーヤーを追加
        world_.add_actor(new Player{ &world_, GSvector2{ 280.0f, 380.0f } });
        // 敵を3体追加


       world_.add_actor(new Enemy{ &world_, GSvector2{ 240.0f, 0.0f } });

        world_.add_actor(new Enemy{ &world_, GSvector2{ 240.0f, 0.0f } });

        world_.add_actor(new Enemy{ &world_, GSvector2{ 360.0f, 0.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 610.0f, 0.0f } });
    /*    world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });*/

        world_.add_actor(new Enemy1{ &world_, GSvector2{ 240.0f, 0.0f } });
        world_.add_actor(new Enemy2{ &world_, GSvector2{ 360.0f, 0.0f } });
        world_.add_actor(new Enemy3{ &world_, GSvector2{ 610.0f, 0.0f } });

     //   world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });

        world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });


        //画面大きさ（620, 460?）
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

        gsDeleteTexture(TextureItem);

        gsDeleteTexture(TextureBase);
        gsDeleteTexture(TextureEnemy2);
        gsDeleteTexture(TextureEnemy3);
        gsDeleteTexture(TextureEnemy4);

    }
};

// メイン関数
int main() {
    return MyGame().run();
}