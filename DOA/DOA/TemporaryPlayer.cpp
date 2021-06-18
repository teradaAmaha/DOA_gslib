#include "TemporaryPlayer.h"
#include "IWorld.h"
#include "PlayerBeam.h"
#include "TextureID.h"  // テクスチャIDのために必要
#include <algorithm>

// コンストラクタ
TemporaryPlayer::TemporaryPlayer(IWorld* world, const GSvector3& position3D) {
    world_ = world;
    tag_ = "PlayerTag";
    name_ = "Player";
    position3D_ = position3D;
    //collider_ = BoundingRectangle{ 0.0f, 0.0f, 64.0f, 40.0f };
    texture_ = TextureFBX;
}

const GSvector2& TemporaryPlayer::minX() const {

    return min_x_;
}

const GSvector2& TemporaryPlayer::maxX() const {

    return max_x_;
}

// 更新
void TemporaryPlayer::update(float delta_time) {
    world_->sub_timer(2.5);
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


    position_ = position_.clamp(minX(), maxX());


    // スペースキーを押したら弾を発射 生成してる
    if (gsGetKeyState(GKEY_SPACE)) {
        if (counter % 8 == 0) {
            world_->add_actor(new PlayerBeam{ world_,
                position_ + GSvector2{ 35.0f, -1.0f }, GSvector2{ 8.0f, 0.0f } });//playerBeamのコンストラクタ呼んでる
        }
    }

    counter++;
}
