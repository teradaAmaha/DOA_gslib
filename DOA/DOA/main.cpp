#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureID.h"

// �Q�[���N���X
class MyGame : public gslib::Game {
    // ���[���h�N���X
    World world_;
    // �J�n
    void start() override {
    }
    // �X�V
    void update(float delta_time) override {
        // �X�V
        world_.update(delta_time);
    }
    // �`��
    void draw() override {
        // �`��
        world_.draw();
    }
    // �I��
    void end() override {
        // ����
        world_.clear();
        // �e�N�X�`���̍폜
        gsDeleteTexture(TexturePlayer);
        gsDeleteTexture(TextureEnemy);
    }
};

// ���C���֐�
int main() {
    return MyGame().run();
}

