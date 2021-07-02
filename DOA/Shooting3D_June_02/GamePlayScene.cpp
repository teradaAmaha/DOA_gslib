#include "GamePlayScene.h"
#include <GSgame.h>
#include "Assets.h"
#include "ActorManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Light.h"
#include "Camera.h"
#include "Field.h"
#include "World.h"


World world_;
void GamePlayScene::start()
{
    gsLoadMesh(Mesh_Player, "Assets/Model/vehicle_playerShip.msh");
    gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
    // �w�i�p�摜�̓ǂݍ���
    gsLoadTexture(Texture_BgTileNebulaGreen, "Assets/BG/tile_nebula_green_dff.png");

    // �t�B�[���h�̒ǉ�
    world_.add_field(new Field{ Texture_BgTileNebulaGreen });
    // �J�����̒ǉ�
    world_.add_camera(new Camera{ &world_ });
    // ���C�g�̒ǉ�
    world_.add_light(new Light{ &world_ });
    // �v���[���̒ǉ�
    world_.add_actor(new Player{ &world_, GSvector3{ 0.0f, 0.0f, 0.0f } });
    // 覐΂��R�ǉ�
    world_.add_actor(new Asteroid{ &world_,
         GSvector3{ 0.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
    world_.add_actor(new Asteroid{ &world_,
         GSvector3{  30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
    world_.add_actor(new Asteroid{ &world_,
         GSvector3{ -30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
    gsLoadTexture(TextureBase, "Assets/2DSprite/base.png");

}

void GamePlayScene::update(float delta_time)
{
    // ���[���h�N���X�̍X�V
    world_.update(delta_time);
}

void GamePlayScene::draw() const
{
    // ���[���h�N���X�̕`��
    world_.draw();

    const static GSvector2 position_Base{ 1.0f, 400.0f };
    //�^�C�g�����S�̕`��
    gsDrawSprite2D(TextureBase, &position_Base, NULL, NULL, NULL, NULL, 0.0f);
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
}
