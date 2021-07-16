#include "BomExplosion.h"
#include "Assets.h"
#include "IWorld.h"
#include "Field.h"
#include "Asteroid.h"

BomExplosion::BomExplosion(IWorld* world, const GSvector3& position)
{
	world_ = world;
	name_ = "MyAsteroid";
	tag_ = "EnemyTag";
	transform_.position(position);
}

void BomExplosion::update(float delta_time)
{
	for (float pitch = 0.0f; pitch < 360.0f; pitch += 20.0f) {
		
			GSvector3 velocity = GSvector3::createFromPitchYaw(pitch, 90.0f);
			world_->add_actor(new Asteroid{ world_, transform_.position(), velocity });
		
	}
	die();
}
