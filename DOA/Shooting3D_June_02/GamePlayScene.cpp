#include "GamePlayScene.h"
#include <GSgame.h>
#include "Assets.h"
#include "ActorManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Light.h"
#include "Camera.h"
#include "Field.h"
#include "DamageAssets.h"
#include "Enemy.h"
#include "EnemyGenerator.h"
#include"Item.h"
#include <GSmusic.h>

World world_;

void GamePlayScene::start()
{
    // BGMの読み込み (GS_TRUEでループ再生）
    gsLoadMusic(Music_BackGround, "Assets/Sound/music_background.wav", GS_TRUE);
    // BGMのバインド
    gsBindMusic(Music_BackGround);
    // BGMの再生
    gsPlayMusic();
    // 効果音ファイルの読み込み
    gsLoadSE(Se_ExplosionPlayer, "Assets/Sound/explosion_player.wav", 1, GWAVE_DEFAULT);
    gsLoadSE(Se_ExplosionEnemy, "Assets/Sound/explosion_enemy.wav", 1, GWAVE_DEFAULT);
    gsLoadSE(Se_ExplosionAsteroid,
        "Assets/Sound/explosion_asteroid.wav", 1, GWAVE_DEFAULT);
    gsLoadSE(Se_WeaponPlayer, "Assets/Sound/weapon_player.wav", 5, GWAVE_DEFAULT);
    gsLoadSE(Se_WeaponEnemy, "Assets/Sound/weapon_enemy.wav", 5, GWAVE_DEFAULT);

    gsLoadMesh(Mesh_Player, "Assets/Model/vehicle_playerShip.msh");
    gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
    // 背景用画像の読み込み
    gsLoadTexture(Texture_BgTileNebulaGreen, "Assets/BG/tile_nebula_green_dff.png");
    //プレーヤー弾画像読み込み
    gsLoadTexture(Texture_EffectLazerOrange, "Assets/Effect/fx_lazer_orange_dff.png");
    // 敵弾画像を読み込み
    gsLoadTexture(Texture_EffectLazerCyan, "Assets/Effect/fx_lazer_cyan_dff.png");
    // 敵メッシュの読み込み
    gsLoadMesh(Mesh_Enemy, "Assets/Model/vehicle_enemyShip.msh");
    gsLoadTexture(TextureBase, "Assets/2DSprite/base.png");
    // アイテムの読み込み
        gsLoadMesh(Mesh_Item, "Assets/Model/06_UFO_.msh");
    // フィールドの追加
    world_.add_field(new Field{ Texture_BgTileNebulaGreen });
    // カメラの追加
    world_.add_camera(new Camera{ &world_ });
    // ライトの追加
    world_.add_light(new Light{ &world_ });
    // プレーヤの追加
    world_.add_actor(new Player{ &world_, GSvector3{ 0.0f, -60.0f, 0.0f } });
    //アイテム
    world_.add_actor(new Item{ &world_, GSvector3{ 0.0f, 100.0f, 0.0f }
         ,GSvector3{0.0f, -1.0f, 0.0f} });
    // 敵生成クラスの追加
    world_.add_actor(new EnemyGenerator{ &world_, "Stage01.csv" });

    world_.add_actor(new DamageAssets{ &world_, GSvector3{0.0f,-190.0f,0.0f} });
    //world_.add_actor(new DamageAssets{ &world_, GSvector3{-60.0f,-190.0f,0.0f} });
    //world_.add_actor(new DamageAssets{ &world_, GSvector3{60.0f,-190.0f,0.0f} });
}

void GamePlayScene::update(float delta_time)
{
    // ワールドクラスの更新
    world_.update(delta_time);

    
}

void GamePlayScene::draw() const
{
    // ワールドクラスの描画
    world_.draw();

    const static GSvector2 position_Base{ 1.0f, 700.0f };
    
    gsDrawSprite2D(TextureBase, &position_Base, NULL, NULL, NULL, NULL, 0.0f);

}



bool GamePlayScene::is_end() const
{
    // ゲームオーバーかまたはゲームクリアならシーン終了
    return world_.is_game_over() || world_.is_game_clear();
}

std::string GamePlayScene::next() const
{

    // ゲームクリアか？
    if (world_.is_game_clear()) {
        return "GameClearScene";       // ゲームクリアの場合はリザルトシーンに遷移
    }

    if (world_.is_game_over())
    {
        return "GameOverScene";
    }
    //return "TitleScene";
}

void GamePlayScene::end()
{
    // ワールドクラスの消去
    world_.clear();
    // メッシュの削除
    gsDeleteMesh(Mesh_Player);
    gsDeleteMesh(Mesh_Asteroid01);
    // テクスチャの削除
    gsDeleteTexture(Texture_BgTileNebulaGreen);

    gsDeleteTexture(TextureBase);
    // 効果音の削除
    gsDeleteSE(Se_ExplosionPlayer);
    gsDeleteSE(Se_ExplosionEnemy);
    gsDeleteSE(Se_ExplosionAsteroid);
    gsDeleteSE(Se_WeaponPlayer);
    gsDeleteSE(Se_WeaponEnemy);
    // BGMの削除
    gsDeleteMusic(Music_BackGround);

    //gsDeleteTexture(TextureBase);

}
