#include "Timer.h"
#include "NumberTexture.h"
#include "TextureId.h"
#include <gslib.h>
#include <algorithm>

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
	number.draw(GSvector2{ 280, 0 }, timer_, 4);

	GSvector2 pp{ 302.0f,0.0f };
	gsDrawSprite2D(TextureCoron, &pp, NULL, NULL, NULL, NULL, NULL);
}

int Timer::get() const {
	return timer_;
}

void Timer::clear() {
	timer_ = 0;
}