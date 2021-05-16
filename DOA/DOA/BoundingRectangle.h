#ifndef BOUNDING_RECTANGLE_H_
#define BOUNDING_RECTANGLE_H_

#include <gslib.h> // gslib全機能のヘッダファイル（GSvector2のために必要）

// 矩形クラス
class BoundingRectangle {
public:
    // コンストラクタ
    BoundingRectangle() = default;
    // コンストラクタ
    BoundingRectangle(float left, float top, float right, float bottom);
    // コンストラクタ
    BoundingRectangle(const GSvector2& min, const GSvector2& max);
    // 矩形が重なっているか？
    bool intersects(const BoundingRectangle& other) const;
    // 平行移動
    BoundingRectangle translate(const GSvector2& position) const;
    // 幅
    float width() const;
    // 高さ
    float height() const;
    // 左上の座標
    const GSvector2& min() const;
    // 右下の座標
    const GSvector2& max() const;

private:
    GSvector2 min_{ 0.0f, 0.0f };     // 矩形の左上の座標
    GSvector2 max_{ 0.0f, 0.0f };     // 矩形の右下の座標
};

#endif
