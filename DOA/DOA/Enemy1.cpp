#include "Enemy1.h"
#include "IWorld.h"
#include "EnemyBeam.h"
#include "TextureID.h"

// コンストラクタ
Enemy1::Enemy1(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "EnemyTag";
    name_ = "Enemy";
    position_ = position;
    velocity_ = GSvector2{ 0.0f, 1.5f };
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 32.0f, 32.0f };
    texture_ = TextureEnemy;

}

// 更新
void Enemy1::update(float delta_time) {
    position_ += velocity_ * delta_time;

    timer_ += delta_time;
    // 120フレーム経過したか？
    if (timer_ > 60.0f) {
        if (counter % 10 == 0) {
            world_->add_actor(new EnemyBeam{ world_,
                position_ + GSvector2{ 10.0f, 25.0f }, GSvector2{ 8.0f, 0.0f } });
            timer_ = 0.0f;
        }
    }

    counter++;
    //// 拡張エリア外なら死亡
    //if (world_->field().is_outside(collider())) {
    //    die();
    //}

}

void Enemy1::draw() {

}

// 衝突リアクション
void Enemy1::react(Actor& other) {

    if (other.tag() == "BaseTag") {

        die();

    }

    if (other.tag() == "PlayerBulletTag") {

        die();

    }


}

