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


// �Q�[���N���X
class MyGame : public gslib::Game {
public:
    MyGame() : gslib::Game{ 1280, 720, true } {
    }
    // ���[���h�N���X
    SceneManager scene_manager_;

    // �J�n
    void start() override {

        // �^�C�g���V�[���̒ǉ�
        scene_manager_.add("TitleScene", new TitleScene());
        // �Q�[���v���C�V�[���̒ǉ�
        scene_manager_.add("GamePlayScene", new GamePlayScene());

        scene_manager_.add("GameOverScene", new GameOverScene());

        // �^�C�g���V�[������J�n
        scene_manager_.change("TitleScene");
    }
    // �X�V
    void update(float delta_time) override {
        // ���[���h�N���X�̍X�V
        scene_manager_.update(delta_time);
    }
    // �`��
    void draw() override {
        // ���[���h�N���X�̕`��
        scene_manager_.draw();
    }
    // �I��
    void end() override {
        scene_manager_.end();
    }
};

// ���C���֐�
int main() {
    return MyGame().run();
}

