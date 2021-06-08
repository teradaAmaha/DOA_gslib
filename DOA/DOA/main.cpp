#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include"ItemGenerator.h"
#include "TextureID.h"
#include "Base.h"
#include "EnemyGenerator.h"
#include"SceneManager.h"
#include"TitleScene.h"
#include "GamePlayScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"




// �Q�[���N���X
class MyGame : public gslib::Game {

    //�V�[���}�l�[�W���[
    SceneManager scene_manager_;
 
    // �J�n
    void start() override {

        // �^�C�g���V�[���̒ǉ�
        scene_manager_.add("TitleScene", new TitleScene());
        // �Q�[���v���C�V�[���̒ǉ�
        scene_manager_.add("GamePlayScene", new GamePlayScene());
        //�Q�[���N���A�[�V�[���̒ǉ�
        scene_manager_.add("GameClearScene", new GameClearScene());
        //�Q�[���I�[�o�[�V�[���̒ǉ�
        scene_manager_.add("GameOverScene", new GameOverScene());
        // �^�C�g���V�[������J�n
        scene_manager_.change("TitleScene");
        //scene_manager_.change("GameClearScene");

        //// �^�C�g���V�[���̒ǉ�
        //scene_manager_.add("TitleScene", new TitleScene());
        //// �Q�[���v���C�V�[���̒ǉ�
        //scene_manager_.add("GamePlayScene", new GamePlayScene());
        //// �^�C�g���V�[������J�n
        //scene_manager_.change("TitleScene");


        // �e�N�X�`���̓ǂݍ���
        gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
        gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
        gsLoadTexture(TexturePlayerBeam, "Assets/BEAM.png");
        gsLoadTexture(TextureEnemyBeam, "Assets/EBEAM.png");
        gsLoadTexture(TextureNumber, "Assets/NUM.png");
        gsLoadTexture(TextureCoron, "Assets/coron.png");


        gsLoadTexture(TextureBase, "Assets/base.png");
        gsLoadTexture(TextureEnemy2, "Assets/ENEMY2.png");
        gsLoadTexture(TextureEnemy3, "Assets/ENEMY3.png");
        gsLoadTexture(TextureEnemy4, "Assets/ENEMY4.png");
        gsLoadTexture(TextureBoss, "Assets/BOSS.png");
        gsLoadTexture(TextureItem, "Assets/ITEM.png");

        // �v���[���[��ǉ�
        world_.add_actor(new Player{ &world_, GSvector2{ 280.0f, 380.0f } });
        // �G��3�̒ǉ�

        world_.add_actor(new EnemyGenerator{ &world_ });
        world_.add_actor(new ItemGenerator{ &world_ });
        world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });
        




        //��ʑ傫���i620, 460?�j
    }
    // �X�V
    void update(float delta_time) override {
        // �V�[���̍X�V
        scene_manager_.update(delta_time);

  
    }
    // �`��
    void draw() override {
        // �V�[���̕`��
        scene_manager_.draw();

     
    }
    // �I��
    void end() override {
        // �V�[���̏I��
       scene_manager_.end();

       
    }
};

// ���C���֐�
int main() {
    return MyGame().run();
}