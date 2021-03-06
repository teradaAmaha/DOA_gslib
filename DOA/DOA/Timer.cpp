#include "Timer.h"
#include "NumberTexture.h"
#include "TextureId.h"
#include <gslib.h>
#include <algorithm>
#include "IWorld.h"
#include "World.h"
#include <iostream>

//コンストラクタ
Timer::Timer(int timer) :
	timer_{ timer } {}

void Timer::initialize(int timer) {
	timer_ = timer;
}

void Timer::sub(int timer) {
	timer_ = std::max(0, timer_ - timer);
	
}

void Timer::draw() const
{
	static const NumberTexture number{ TextureNumber, 16, 16 };

	number.draw(GSvector2{ 600, 0 }, timer_, 2);

	number.draw(GSvector2{ 280, 0 }, timer_, 4);

	
	GSvector2 pp{ 622.0f,0.0f };
	gsDrawSprite2D(TextureCoron, &pp, NULL, NULL, NULL, NULL, NULL);
}

int Timer::get() const {
	return timer_;
}

void Timer::clear() {
	timer_ = 3000;
}

void Timer::zero(int timeUp)
{
	
}