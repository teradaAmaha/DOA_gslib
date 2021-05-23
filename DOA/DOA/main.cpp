#include <GSgame.h>
#include "World.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
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

        gsLoadTexture(TextureItem, "Assets/ITEM.png");


        gsLoadTexture(TexturePlayerBeam, "Assets/BEAM.png");
        gsLoadTexture(TextureEnemyBeam, "Assets/EBEAM.png");

        gsLoadTexture(TextureBase, "Assets/base.png");
        gsLoadTexture(TextureEnemy2, "Assets/ENEMY2.png");
        gsLoadTexture(TextureEnemy3, "Assets/ENEMY3.png");
        gsLoadTexture(TextureEnemy4, "Assets/ENEMY4.png");
        gsLoadTexture(TextureBoss, "Assets/BOSS.png");

        // �v���[���[��ǉ�
        world_.add_actor(new Player{ &world_, GSvector2{ 280.0f, 380.0f } });
        // �G��3�̒ǉ�


       world_.add_actor(new Enemy{ &world_, GSvector2{ 240.0f, 0.0f } });

        world_.add_actor(new Enemy{ &world_, GSvector2{ 240.0f, 0.0f } });

        world_.add_actor(new Enemy{ &world_, GSvector2{ 360.0f, 0.0f } });
        world_.add_actor(new Enemy{ &world_, GSvector2{ 610.0f, 0.0f } });
    /*    world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });*/

        world_.add_actor(new Enemy1{ &world_, GSvector2{ 240.0f, 0.0f } });
        world_.add_actor(new Enemy2{ &world_, GSvector2{ 360.0f, 0.0f } });
        world_.add_actor(new Enemy3{ &world_, GSvector2{ 610.0f, 0.0f } });

     //   world_.add_actor(new Base{ &world_, GSvector2{-40.0f,440.0f} });

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

        gsDeleteTexture(TextureItem);

        gsDeleteTexture(TextureBase);
        gsDeleteTexture(TextureEnemy2);
        gsDeleteTexture(TextureEnemy3);
        gsDeleteTexture(TextureEnemy4);

    }
};

// ���C���֐�
int main() {
    return MyGame().run();
}