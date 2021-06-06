#include"ItemGenerator.h"
#include"IWorld.h"
#include"Item.h"


ItemGenerator::ItemGenerator(IWorld* world) {
	world_ = world;
	tag_ = "ItemGenerator";
	timer_ = 0.0f;	
	enable_collider_ = false;//無敵状態
	
}

void ItemGenerator::update(float delta_time) {
	if (timer_ < 0.0f) {
		//出現座標
		GSvector2 position{
			
		};
		//アイテムの生成

		world_->add_actor(new Item{ world_, position });
		timer_ = gsRandf(30.0f,120.0f);
	}

	//生成速度
	timer_ -= delta_time;
}
//描画何も表示させない
void ItemGenerator::draw() const {}