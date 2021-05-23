#include "Player.h"
#include "IWorld.h"
#include "PlayerBeam.h"
#include "TextureID.h"  // テクスチャIDのために必要

// コンストラクタ
Player::Player(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "PlayerTag";
    name_ = "Player";
    position_ = position;
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 64.0f, 40.0f };
    texture_ = TexturePlayer;
}

// 更新
void Player::update(float delta_time) {
    GSvector2 direction{ 0.0f, 0.0f }; // 移動方向
    if (gsGetKeyState(GKEY_LEFT)) {
        direction.x = -1.0f;
    }
    if (gsGetKeyState(GKEY_RIGHT)) {
        direction.x = 1.0f;
    }
    /* if (gsGetKeyState(GKEY_UP)) {
         direction.y = -1.0f;
     }
     if (gsGetKeyState(GKEY_DOWN)) {
         direction.y = 1.0f;
     }*/
    float speed = 8.0f; // 移動スピード
    // 移動量の計算
    velocity_ = direction.normalized() * speed;
    // 座標の更新
    position_ += velocity_ * delta_time;

    // スペースキーを押したら弾を発射
    if (gsGetKeyTrigger(GKEY_SPACE)) {
        world_->add_actor(new PlayerBeam{ world_,
            position_ + GSvector2{ 50.0f, 25.0f }, GSvector2{ 8.0f, 0.0f } });
    }
}

//// 衝突リアクション
//void Player::react(Actor& other) {
//    // 敵のタグを持つキャラクタと衝突したか？
//    if (other.tag() == "EnemyTag") {
//        // 死亡状態にする
//        die();
//    }
//}