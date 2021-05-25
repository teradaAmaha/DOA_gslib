#include "Enemy2.h"
#include "TextureId.h"

Enemy2::Enemy2(IWorld* world, const GSvector2& position) {
	world = world;
	tag_ = "Enemy2Tag";
	name_ = "Enemy";
	position_ = position;
	velocity_ = GSvector2{ 0.0f,3.0f }; //‘¬“x•ûŒü
	collider_ = BoundingRectangle{ 0.0f,0.0f,32.0f,32.0f };//‹éŒ`‚Ì“–‚½‚è”»’è‚Ì‘å‚«‚³
	texture_ = TextureEnemy2;

}
void Enemy2::update(float delta_time) {
	position_ += velocity_ * delta_time;
}

void Enemy2::react(Actor& other) {

	if (other.tag() == "BaseTag") {
		die();
	}

	if (other.tag() == "PlayerBulletTag") {

		die();

	}
}