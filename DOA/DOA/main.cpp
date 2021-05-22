#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureID.h"
#include "Base.h"

// �Q�[���N���X
class MyGame : public gslib::Game {
    // ���[���h�N���X
    World world_;
    // �J�n
    void start() override {
        // �e�N�X�`���̓ǂݍ���
        gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
        gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
        gsLoadTexture(TextureBase, "Assets/base.png");
        // �v���[���[��ǉ�
        world_.add_actor(new Player{ &world_, GSvector2{ 280.0f, 380.0f } });
        // �G��3�̒ǉ�
        world_.add_actor(new Enemy{ &world_, GSvector2{ 240.0f, 0.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 360.0f, 0.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 610.0f, 0.0f } });
        world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });

        //��ʑ傫���i620, 460?�j
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