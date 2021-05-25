#include "Field.h"
#include "TextureID.h"


void Field::update(float delta_time) {
}

// 拡張エリアの外側か？
bool Field::is_outside(const BoundingRectangle& rect) const {
    return !extend_area_.intersects(rect);
}

// エリアの取得
const BoundingRectangle& Field::area() const {
    return area_;
}