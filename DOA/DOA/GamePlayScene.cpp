#include "GamePlayScene.h"
#include "Player.h"
#include "Base.h"
#include "EnemyGenerator.h"
#include"ItemGenerator.h"
#include "TextureID.h"


// ���[���h�N���X
World world_;
// �J�n
void GamePlayScene::start() {




    // �e�N�X�`���̓ǂݍ���
    gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
    gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
    gsLoadTexture(TexturePlayerBeam, "Assets/BEAM.png");
    gsLoadTexture(TextureEnemyBeam, "Assets/EBEAM.png");
    gsLoadTexture(TextureNumber, "Assets/NUM.png");



    gsLoadTexture(TextureBase, "Assets/base.png");
    gsLoadTexture(TextureBG1, "Assets/BG1.png");
    gsLoadTexture(TextureBG2, "Assets/BG2.png");
    gsLoadTexture(TextureBG3, "Assets/BG3.png");
    //gsLoadTexture(TextureBomb, "Assets/BOMB.png");
    gsLoadTexture(TextureNumber, "Assets/NUM.png");
    gsLoadTexture(TextureCoron, "Assets/coron.png");
    gsLoadTexture(TextureBase, "Assets/base.png");
    gsLoadTexture(TextureEnemy2, "Assets/ENEMY2.png");
    gsLoadTexture(TextureEnemy3, "Assets/ENEMY3.png");
    gsLoadTexture(TextureEnemy4, "Assets/ENEMY4.png");
    gsLoadTexture(TextureBoss, "Assets/BOSS.png");
    
    world_.add_actor(new Player{ &world_, GSvector2{ 0.0f, 200.0f } });
    world_.add_actor(new EnemyGenerator{ &world_ });
    //world_.add_actor(new Item{ &world_,GSvector2{100.0f,100.0f} });
    world_.add_actor(new Base{ &world_,GSvector2{-40.0f,440.0f} });
    is_end_ = false;
    //die = false;
    gsLoadTexture(TextureItem, "Assets/ITEM.png");


}

// �X�V
void GamePlayScene::update(float delta_time) {
    world_.update(delta_time);
    if (world_.get_timer().get() == 0)
    {
        world_.game_clear();
        is_end_ = true;
        
    }
  

}
// �`��
void GamePlayScene::draw() const {
    GSvector2 BG1_position{ 0.0f,0.0f };
    gsDrawSprite2D(TextureBG2, &BG1_position, NULL, NULL, NULL, NULL, 0.0f);
    world_.draw();
}

// �I�����Ă��邩�H
bool GamePlayScene::is_end() const {
    // �Q�[���I�[�o�[���܂��̓Q�[���N���A�Ȃ�V�[���I��
   return world_.is_game_over() || world_.is_game_clear();

}
// ���̃V�[����Ԃ�
std::string GamePlayScene::next() const {

    // �Q�[���N���A���H
    if (world_.is_game_clear()) {
        return "GameClearScene";       // �Q�[���N���A�̏ꍇ�̓��U���g�V�[���ɑJ��
    }

    if (world_.is_game_over())
    {
        return "GameOverScene";
    }
   
    //�^�C�g���V�[���ɖ߂�
   // return "TitleScene";
   
}

// �I��
void GamePlayScene::end() {
    // ���[���h������
    world_.clear();
    // �e�X�N�`���̍폜
    gsDeleteTexture(TexturePlayer);
    gsDeleteTexture(TextureEnemy);
    gsDeleteTexture(TexturePlayerBeam);
    gsDeleteTexture(TextureEnemyBeam);
    gsDeleteTexture(TextureBase);
    gsDeleteTexture(TextureItem);
    gsDeleteTexture(TextureBG1);
    gsDeleteTexture(TextureBG2);
    gsDeleteTexture(TextureBG3);
    //gsDeleteTexture(TextureBomb);
    gsDeleteTexture(TextureNumber);
    gsDeleteTexture(TextureBase);
    gsDeleteTexture(TextureEnemy2);
    gsDeleteTexture(TextureEnemy3);
    gsDeleteTexture(TextureEnemy4);
}
