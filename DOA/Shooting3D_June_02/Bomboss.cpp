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
    name_ = "Bomboss";
    tag_ = "EnemyTag";
    velocity_ = GSvector3{ 0.0f, -1.0f, 0.0f };
    collider_ = BoundingSphere{ 20.0f };
    moving_timer_ = gsRandf(0.0f, 60.0f);
    shooting_timer_ = gsRandf(0.0f, 60.0f);
    transform_.position(position);
}

void Bomboss::update(float delta_time)
{
    transform_.eulerAngles(90.0f, 0.0f, 0.0f);
    //transform_.translate(velocity_ * delta_time, GStransform::Space::World);

    moving_timer_ -= delta_time;

    if (moving_timer_ <= -150.0f && moving_timer_ > -400.0f)
    {
        velocity_.y = -0.0f;
        
    }
    else if (moving_timer_ <= -400.0f)
    {
        world_->add_actor(new BomExplosion{ world_, transform_.position() });
        die();
    }
    else
    {
        //transform_.eulerAngles(90.0f, 0.0f, 0.0f);
        //transform_.rotate(2.0f, 0.0f, 0.5f);
        velocity_.y = -0.5;
       // transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    }
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    // 画面外であれば死亡
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
    motion_timer_ += delta_time;

}

GLfloat red[] = { 0.8, 0.2, 0.2,1.0 };
void Bomboss::draw() const
{
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    gsBindSkeleton(Mesh_Enemy);
    gsBindAnimation(Mesh_Enemy, 1, motion_timer_);
   // glColor3d(1.0f, 0.0f, 0.0f);
    glScaled(40.0f,60.0f,40.0f);
    gsDrawMesh(Mesh_Enemy);
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
