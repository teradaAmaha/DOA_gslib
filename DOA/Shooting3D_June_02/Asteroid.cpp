#include "Asteroid.h"
#include "Assets.h"
#include "IWorld.h"
#include "Field.h"

// コンストラクタ
Asteroid::Asteroid(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
    world_ = world;
    name_ = "Asteroid";
    tag_ = "EnemyTag";
    transform_.position(position);
    velocity_ = velocity;
    collider_ = BoundingSphere{ 15.0f };
}

// 更新
void Asteroid::update(float delta_time) {
    // 回転させる
    //transform_.rotate(2.0f, 0.0f, 0.5f);
    // 移動する（ワールド座標系を基準に移動）
    transform_.eulerAngles(90.0f, 0.0f, 0.0f);
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);

    if (world_->field()->is_outside(transform_.position())) {
       //world_->sub_hp(2);
        die();
     
    }
    motion_timer_ += delta_time;
}

// 描画
void Asteroid::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    gsBindSkeleton(Mesh_Enemy);
    gsBindAnimation(Mesh_Enemy, 1, motion_timer_);
    glScaled(20.0f, 20.0f, 20.0f);
    gsDrawMesh(Mesh_Enemy);
    glPopMatrix();
}

// 衝突処理
void Asteroid::react(Actor& other) {
    if (other.tag() == "PlayerBulletTag") {
        gsPlaySE(Se_dieZombie);
        die();
        //world_->add_score(100);
        gsPlaySE(Se_dieZombie);
    }
    if (other.tag() == "DamageTag")
    {
        die();
        //world_->add_score(100);
    }
}