#include <GSgame.h>
<<<<<<< HEAD
#include "SceneManager.h"
#include "TitleScene.h"
#include "GamePlayScene.h"

// �Q�[���N���X
class MyGame : public gslib::Game {
    // �V�[���}�l�[�W���[
    SceneManager scene_manager_;
    // �J�n
    void start() override {
        // �^�C�g���V�[���̒ǉ�
        scene_manager_.add("TitleScene", new TitleScene());
        // �Q�[���v���C�V�[���̒ǉ�
        scene_manager_.add("GamePlayScene", new GamePlayScene());
        // �^�C�g���V�[������J�n
        scene_manager_.change("TitleScene");
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
=======

class MyGame : public gslib::Game {

};

int main() {
	return MyGame().run();
}
>>>>>>> f59b5c3d60bddca32cde8e3e5ab799981391b42f
