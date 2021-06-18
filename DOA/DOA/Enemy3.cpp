#include "Enemy3.h"
#include "IWorld.h"
#include "TextureId.h"
#include "EnemyBeam.h"
#include <unordered_map>
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
        Scatter();
	}
	if (other.tag() == "PlayerBulletTag") {

		if (other.tag() == "PlayerBulletTag") {
			life -= 1;
			if (life < 1) {
				die();
                Scatter();
				world_->add_score(100);
			}
		}

	}
}

void Enemy3::Scatter(int size)
{


    std::unordered_map<int, float> a;

    for (float i = 0; i < size; i++)
    {

        if (velocity_.x <= -6.0f)
        {
            velocity_.x += 3.0f;
        }
        if (velocity_.x >= 6.0f)
        {
            velocity_.x -= 3.0f;
        }
        a[i] = velocity_.x;
        for (float j = 0; j < size; j++)
        {
            if (velocity_.y <= -6.0f)
            {
                velocity_.y += 3.0f;
            }
            if (velocity_.y >= 6.0f)
            {
                velocity_.y -= 3.0f;
            }
            a[j] = velocity_.y;
            world_->add_actor(new EnemyBeam{ world_,
                  position_ + GSvector2{ 50.0f, 25.0f }, GSvector2{ a[i], a[j] } });
        }
    }

    /* std::vector<float> a;
     for (float i = 0; i < size; i++)
     {

       if(velocity_.x <= -1.f)
       {
           velocity_.x += 0.5f;
       }
       if (velocity_.x >= 4.0f)
       {
           velocity_.x -= 0.5f;
       }
       a.push_back(velocity_.x);
       for (float j = 0; j < size; j++)
       {
           if (velocity_.y <= 4.0f)
           {
               velocity_.y += 0.5f;
           }
           if (velocity_.y >= 4.0f)
           {
               velocity_.y -= 0.5f;
           }
           a.push_back(velocity_.y);
           world_->add_actor(new PlayerBeam{ world_,
                 position_ + GSvector2{ 40.0f, 25.0f }, GSvector2{ a[i], a[j] } });
       }
     }*/
}