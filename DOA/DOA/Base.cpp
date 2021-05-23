<<<<<<< HEAD
//#include "Base.h"
//
//Base::Base(IWorld* world, const GSvector2& position) {
//	world_ = world;
//	tag_ = "BaseTag";
//	name_ = "Base";
//	position_ = position;
//	collider_ = BoundingRectangle{ 0.0f,0.0f,680.0f,20.0f };
//}
//
//void Base::react(Actor& other)
//{
//	if (other.tag() == "EnemyTag") {
//		die();
//	}
//}
=======
#include "Base.h"
#include "TextureId.h"

Base::Base(IWorld* world, const GSvector2& position) {
	world_ = world;
	tag_ = "BaseTag";
	name_ = "Base";
	position_ = position;
	collider_ = BoundingRectangle{ 0.0f,0.0f,680.0f,20.0f };
	texture_ = TextureBase;
}

void Base::react(Actor& other)
{
	if (other.tag() == "EnemyTag") {
		die();
	}
}
>>>>>>> 67ee0600efc2f2ef1b30d4a566cde17fc622dd4d
