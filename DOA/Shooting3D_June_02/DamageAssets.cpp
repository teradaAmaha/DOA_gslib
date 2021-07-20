#include "DamageAssets.h"
#include "Assets.h"
#include "IWorld.h"
#include "Field.h"

DamageAssets::DamageAssets(IWorld* world, const GSvector3& position)
{
    world_ = world;
    name_ = "DamageAssets";
    tag_ = "DamageTag";
    transform_.position(position);
    //velocity_ = velocity;
    collider_ = BoundingSphere{ 100.0f };
}

void DamageAssets::update(float delta_time)
{
}

void DamageAssets::draw() const
{
   
}

void DamageAssets::react(Actor& other)
{
    if (other.tag() == "EnemyTag") {
         --life;
        if (life <= 0)
        {
            world_->game_over();
        }
    }
    
}
