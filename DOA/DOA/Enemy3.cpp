#include "Enemy3.h"
#include "IWorld.h"
#include "TextureId.h"

Enemy3::Enemy3(IWorld* world, const GSvector2& position)
{
	world_ = world;
	tag_ = "Enemy3Tag";
	name_ = "Enemy";
	position_ = position;
	velocity_ = GSvector2{ 0.0f,1.5f };
	collider_ = BoundingRectangle{ 0.0f,0.0f,64.0f,64.0f };
	texture_ = TextureEnemy3;
	
}

void Enemy3::update(float delta_time) {
	position_ += velocity_ * delta_time;
}

void Enemy3::react(Actor& other) {
	if (other.tag() == "BaseTag") {

		die();

	}
	if (other.tag() == "PlayerBulletTag") {

		die();
		world_->add_score(100);
	}
}