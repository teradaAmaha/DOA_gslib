#include "BaseLife.h"
#include "NumberTexture.h"
#include "TextureId.h"
#include "Base.h"
#include <gslib.h>
#include <algorithm>

class Base;

BaseLife::BaseLife(int hp) :
	hp_{ hp } {}

void BaseLife::initialize(int hp)
{
	hp_ = hp;
}

void BaseLife::sub(int hp)
{
	hp_ = std::max(0, hp_ - hp);


}

void BaseLife::draw() const
{
	static const NumberTexture number{ TextureNumber, 16, 16 };//NumberTextureのコンストラクタから
	number.draw(GSvector2{ 280, 400 }, hp_, 3);

	//GSvector2 per{ 310.0f, 400.0f };
	//gsDrawSprite2D(TexturePer, &per, NULL, NULL, NULL, NULL, NULL);
}

int BaseLife::get() const {
	return hp_;
}

void BaseLife::clear() {
	hp_ = 0;
}

