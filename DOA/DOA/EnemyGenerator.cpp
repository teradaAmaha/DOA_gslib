#include "EnemyGenerator.h"
#include "IWorld.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"

EnemyGenerator::EnemyGenerator(IWorld* world) {
	world_ = world;
	tag_ = "Generator";
	timer_1_ = 0.0f;
	timer_2_ = 0.0f;
	timer_3_ = 0.0f;
	timer_4_ = 0.0f;
	enable_collider_ = false;//ñ≥ìGèÛë‘Ç…Ç∑ÇÈ
}

void EnemyGenerator::update(float delta_time) {
	if (timer_1_ < 0.0f) {
		//èoåªç¿ïW
		GSvector2 position{
			gsRandf(0.0f,1280.0f - 32.0f),
			0.0f
		};
		//ìGÇÃê∂ê¨
		world_->add_actor(new Enemy1{ world_, position });
		timer_1_ = gsRandf(30.0f, 120.0f);
	}

	if (timer_2_ < 0.0f) {
		//èoåªç¿ïW
		GSvector2 position{
			gsRandf(0.0f,1280.0f - 32.0f),
			0.0f
		};
		//ìGÇÃê∂ê¨
		world_->add_actor(new Enemy2{ world_, position });
		timer_2_ = gsRandf(30.0f, 120.0f);
	}
	if (timer_3_ < 0.0f) {
		//èoåªç¿ïW
		GSvector2 position{
			gsRandf(0.0f,1280.0f - 32.0f),
			0.0f
		};
		//ìGÇÃê∂ê¨
		world_->add_actor(new Enemy3{ world_, position });
		timer_3_ = gsRandf(30.0f, 120.0f);
	}
	if (timer_4_ < 0.0f) {
		//èoåªç¿ïW
		GSvector2 position{
			gsRandf(0.0f,1280.0f - 32.0f),
			0.0f
		};
		//ìGÇÃê∂ê¨
		world_->add_actor(new Enemy4{ world_, position });
		timer_4_ = gsRandf(30.0f, 120.0f);
	}
	//ê∂ê¨ë¨ìx
	timer_1_ -= delta_time;
	timer_2_ -= delta_time*0.2;
	timer_3_ -= delta_time*0.2;
	timer_4_ -= delta_time*0.2;

}
//ï`âÊâΩÇ‡ï\é¶Ç≥ÇπÇ»Ç¢
void EnemyGenerator::draw() const{}