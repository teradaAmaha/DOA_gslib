#include"ItemGenerator.h"
#include"IWorld.h"
#include"Item.h"

class Enemy1;
ItemGenerator::ItemGenerator(IWorld* world) {
	world_ = world;
	tag_ = "ItemGenerator";
	timer_ = 0.0f;	
	enable_collider_ = false;//���G���
	
}

void ItemGenerator::update(float delta_time) {
	if (timer_ < 0.0f) {
		
		//�A�C�e���̐���

		//world_->add_actor(new Item{ world_, Enemy1 position });
		//timer_ = gsRandf(30.0f,120.0f);
	}

	//�������x
	timer_ -= delta_time;
}
//�`�扽���\�������Ȃ�
void ItemGenerator::draw() const {}