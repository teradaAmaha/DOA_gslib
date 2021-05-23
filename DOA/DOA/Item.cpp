#include"Item.h"
#include"TextureId.h"

//コンストラクタ
Item::Item(IWorld* world, const GSvector2& position)
{
	world = world;
	tag_ = "ItemTag";
	name_ = "";
	position_ = position;
	velocity_ = GSvector2{-0.0f ,0.5f };
	collider_ = BoundingRectangle{ 0.0f,0.0f,32.0f,32.0f };
	texture_ = TextureItem;
}
// 更新
void Item::update(float delta_time) {
    position_ += velocity_ * delta_time;

    
}

// 衝突リアクション
void Item::react(Actor& other) {
    if (other.tag() == "PlayerTag" || other.tag() == "PlayerBulletTag") {
        die();
        
    }
}