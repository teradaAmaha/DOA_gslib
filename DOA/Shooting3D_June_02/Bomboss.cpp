#include "Bomboss.h"
#include "IWorld.h"
#include "Assets.h"
#include "Field.h"
#include "EnemyBullet.h"
#include "Asteroid.h"
#include "BomExplosion.h"

Bomboss::Bomboss(IWorld* world, const GSvector3& position)
{
    world_ = world;
    name_ = "MyEnemy";
    tag_ = "EnemyTag";
    velocity_ = GSvector3{ 0.0f, -1.0f, 0.0f };
    collider_ = BoundingSphere{ 35.0f };
    moving_timer_ = gsRandf(0.0f, 60.0f);
    shooting_timer_ = gsRandf(0.0f, 60.0f);
    transform_.position(position);
}

void Bomboss::update(float delta_time)
{
    //transform_.eulerAngles(90.0f, 0.0f, 0.0f);
    transform_.rotate(2.0f, 0.0f, 0.5f);
    velocity_.y = -0.3;
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);


    // 画面外であれば死亡
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
}

void Bomboss::draw() const
{
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    glScalef(7.0f, 7.0f, 7.0f);
    gsDrawMesh(Mesh_Asteroid01);
    glPopMatrix();
}

void Bomboss::react(Actor& other)
{
    if (other.tag() == "PlayerTag" || other.tag() == "PlayerBulletTag") {
        --life;
        // 爆発エフェクトを生成
        if (life <= 0)
        {
          
            world_->game_clear();

            die();
        }
    }
}
