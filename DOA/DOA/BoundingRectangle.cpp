#include "BoundingRectangle.h"

// コンストラクタ
BoundingRectangle::BoundingRectangle(float left, float top, float right, float bottom)
    : BoundingRectangle{ GSvector2{ left, top }, GSvector2{ right, bottom } } {
}

// コンストラクタ
BoundingRectangle::BoundingRectangle(const GSvector2& min, const GSvector2& max)
    : min_{ min }, max_{ max } {
}

// 矩形が重なっているか？
bool BoundingRectangle::intersects(const BoundingRectangle& other) const {
    if (min_.x > other.max_.x) return false;
    if (max_.x < other.min_.x) return false;
    if (min_.y > other.max_.y) return false;
    if (max_.y < other.min_.y) return false;
    return true;
}

// 平行移動
BoundingRectangle BoundingRectangle::translate(const GSvector2& position) const {
    return BoundingRectangle{ min_ + position, max_ + position };
}

// 幅
float BoundingRectangle::width() const {
    return max_.x - min_.x;
}

// 高さ
float BoundingRectangle::height() const {
    return max_.y - min_.y;
}

// 左上の座標
const GSvector2& BoundingRectangle::min() const {
    return min_;
}

// 右下の座標
const GSvector2& BoundingRectangle::max() const {
    return max_;
}