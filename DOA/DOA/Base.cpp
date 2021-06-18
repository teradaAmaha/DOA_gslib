#include "Base.h"
#include "TextureId.h"

#include "World.h"
#include <vector>

Base::Base(IWorld* world, const GSvector2& position) {
	world_ = world;
	tag_ = "BaseTag";
	name_ = "Base";
	position_ = position;
	collider_ = BoundingRectangle{ 0.0f,0.0f,1280.0f,20.0f };
	texture_ = TextureBase;
}
void Base::update(float delta_time)
{
	counter++;
}

void Base::draw() const {
	if (counter > 0 || counter % 2 == 0) {
		gsDrawSprite2D(TextureBase, &position_, NULL, NULL, NULL, NULL, angle_);
	}
}

void Base::alive() {//ライフが０になれば死ぬ
	--life;//仮ライフ
	world_->sub_hp(1);
	counter = -60;
	if (life <= 0)
	{
		die();
		world_->game_over();

	}
}

int Base::get() const
{
	return life;
}

//void Base::damageArray()
//{
//	std::vector<int> d;
//	d[0] = 
//
//	for (std::vector<int>::iterator i = d.begin(); i != d.end(); ++i)
//	{
//		
//	}
//}

void Base::react(Actor& other)
{
	if (other.tag() == "EnemyTag") {
		//各ダメージ量はここで(life)
		alive();
	}
	if (other.tag() == "Enemy2Tag") {
		
		alive();
	}
	if (other.tag() == "Enemy3Tag") {

		alive();
	}
	if (other.tag() == "Enemy4Tag") {
		alive();
	}
	if (other.tag() == "EnemyBulletTag") {
		alive();
	}
}

