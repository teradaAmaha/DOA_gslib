#include "Base.h"
#include "TextureId.h"
#include <iostream>

Base::Base(IWorld* world, const GSvector2& position) {
	world_ = world;
	tag_ = "BaseTag";
	name_ = "Base";
	position_ = position;
	collider_ = BoundingRectangle{ 0.0f,0.0f,680.0f,20.0f };
	texture_ = TextureBase;
}
void Base::update(float delta_time)
{
	
}

void Base::alive() {//ライフが０になれば死ぬ
	--life;//仮ライフ
	
	if (life <= 0)
	{
		die();
	}
}

void Base::react(Actor& other)
{
	if (other.tag() == "EnemyTag") {
		//各ダメージ量はここで(life)
		alive();
	}
	if (other.tag() == "Enemy2Tag") {

		alive();
	}
	if (other.tag() == "Enemy2Tag") {
		alive();
	}
	if (other.tag() == "Enemy2Tag") {
		alive();
	}
	
}

