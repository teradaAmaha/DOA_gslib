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
#include "Bomboss.h"
#include <GSmusic.h>

World world_;

void GamePlayScene::start()
{
    // BGM�̓ǂݍ��� (GS_TRUE�Ń��[�v�Đ��j
    //gsLoadMusic(Music_BackGround, "Assets/Sound/music_background.wav", GS_TRUE);
    // BGM�̃o�C���h
    gsBindMusic(Music_BackGround);
    // BGM�̍Đ�
   // gsPlayMusic();
    // ���ʉ��t�@�C���̓ǂݍ���
    gsLoadSE(Se_ExplosionPlayer, "Assets/Sound/explosion_player.wav", 1, GWAVE_DEFAULT);
    gsLoadSE(Se_ExplosionEnemy, "Assets/Sound/explosion_enemy.wav", 1, GWAVE_DEFAULT);
    gsLoadSE(Se_ExplosionAsteroid, "Assets/Sound/explosion_asteroid.wav", 1, GWAVE_DEFAULT);
    gsLoadSE(Se_WeaponPlayer, "Assets/Sound/nc25721.wav", 5, GWAVE_DEFAULT);
    gsLoadSE(Se_WeaponPlayer1, "Assets/Sound/nc30638.wav", 5, GWAVE_DEFAULT);
    gsLoadSE(Se_WeaponEnemy, "Assets/Sound/weapon_enemy.wav", 5, GWAVE_DEFAULT);
    gsLoadSE(Se_WeaponChange, "Assets/Sound/nc40282.wav", 5, GWAVE_DEFAULT);
    gsLoadSE(Se_dieZombie, "Assets/Sound/gutya.wav", 5, GWAVE_DEFAULT);

    gsLoadMesh(Mesh_Player, "Assets/Model/gun.msh");
    gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
    // �w�i�p�摜�̓ǂݍ���
    gsLoadTexture(Texture_BgTileNebulaGreen, "Assets/BG/tile_nebula_green_dff.png");
    //�v���[���[�e�摜�ǂݍ��� 
    gsLoadTexture(Texture_EffectLazerOrange, "Assets/Effect/fx_lazer_orange_dff.png");
    gsLoadTexture(Texture_BG, "Assets/2DSprite/PlayBg.png");
    // �G�e�摜��ǂݍ���
    gsLoadTexture(Texture_EffectLazerCyan, "Assets/Effect/fx_lazer_cyan_dff.png");

    // �G���b�V���̓ǂݍ���
    gsLoadMesh(Mesh_Enemy, "Assets/Model/ghoul.msh");
    gsLoadSkeleton(Mesh_Enemy, "Assets/Model/ghoul.skl");
    gsLoadAnimation(Mesh_Enemy, "Assets/Model/ghoul.anm");

    // �A�C�e���̓ǂݍ���
    gsLoadMesh(Mesh_Item, "Assets/Model/item.msh");



    // �t�B�[���h�̒ǉ�
    world_.add_field(new Field{ Texture_BgTileNebulaGreen });
    // �J�����̒ǉ�
    world_.add_camera(new Camera{ &world_ });
    // ���C�g�̒ǉ�
    world_.add_light(new Light{ &world_ });
    // �v���[���̒ǉ�
    world_.add_actor(new Player{ &world_, GSvector3{ 0.0f, -50.0f, 0.0f } });
    //�A�C�e��
    world_.add_actor(new Item{ &world_ ,GSvector3{10.0f,0.0f,0.0f} });
    // �G�����N���X�̒ǉ�
    world_.add_actor(new EnemyGenerator{ &world_, "Stage01.csv" });

    world_.add_actor(new DamageAssets{ &world_, GSvector3{0.0f,-190.0f,0.0f} });

}

void GamePlayScene::update(float delta_time)
{
    // ���[���h�N���X�̍X�V
    world_.update(delta_time);

    
}

void GamePlayScene::draw() const
{
    gsDrawSprite2D(Texture_BG, 0, NULL, NULL, NULL, NULL, 0.0f);
    // ���[���h�N���X�̕`��
    world_.draw();
   
}



bool GamePlayScene::is_end() const
{
    // �Q�[���I�[�o�[���܂��̓Q�[���N���A�Ȃ�V�[���I��
    return world_.is_game_over() || world_.is_game_clear();
}

std::string GamePlayScene::next() const
{

    // �Q�[���N���A���H
    if (world_.is_game_clear()) {
        return "GameClearScene";       // �Q�[���N���A�̏ꍇ�̓��U���g�V�[���ɑJ��
    }

    if (world_.is_game_over())
    {
        return "GameOverScene";
    }
    //return "TitleScene";
}

void GamePlayScene::end()
{
    // ���[���h�N���X�̏���
    world_.clear();
    // ���b�V���̍폜
    gsDeleteMesh(Mesh_Player);
    gsDeleteMesh(Mesh_Asteroid01);
    // �e�N�X�`���̍폜
    gsDeleteTexture(Texture_BgTileNebulaGreen);

    gsDeleteTexture(TextureBase);
    // ���ʉ��̍폜
    gsDeleteSE(Se_ExplosionPlayer);
    gsDeleteSE(Se_ExplosionEnemy);
    gsDeleteSE(Se_ExplosionAsteroid);
    gsDeleteSE(Se_WeaponPlayer);
    gsDeleteSE(Se_WeaponEnemy);
    // BGM�̍폜
    gsDeleteMusic(Music_BackGround);

    //gsDeleteTexture(TextureBase);

}
