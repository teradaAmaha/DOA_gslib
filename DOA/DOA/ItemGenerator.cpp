#include"ItemGenerator.h"
#include"IWorld.h"
#include"Item.h"


ItemGenerator::ItemGenerator(IWorld* world) {
	world_ = world;
	tag_ = "Generator";
	name_ = "ItemGenerator";
	timer_ = 0.0f;	
	enable_collider_ = false;
	
}

void ItemGenerator::update(float delta_time) {
	if (timer_ < 0.0f) {
		//出現座標
		GSvector2 position{
			gsRandf(0.0f,620.0f - 32.0f),
			0.0f
		};
		//アイテムの生成
		world_ ->add_actor(new Item{ world_, position });
		timer_ = delta_time;
	}

	

}
//描画何も表示させない
void ItemGenerator::draw() const {}