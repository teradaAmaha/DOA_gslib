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