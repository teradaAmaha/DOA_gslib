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
        // �e�N�X�`���̓ǂݍ���
        gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
        gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
        // �v���[���[��ǉ�
        world_.add_actor(new Player{ &world_, GSvector2{ 0.0f, 240.0f } });
        // �G��3�̒ǉ�
        world_.add_actor(new Enemy{ &world_, GSvector2{ 640.0f, 120.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 640.0f, 240.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 640.0f, 360.0f } });
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

