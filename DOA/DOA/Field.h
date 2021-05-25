#ifndef FIELD_H_
#define FIELD_H_

#include "BoundingRectangle.h"

// フィールドクラス
class Field {
public:
    // コンストラクタ
    Field() = default;
    // 初期化
    void initialize();
    // 更新
    void update(float delta_time);
    // 描画
    void draw() const;
    // 拡張エリアの外側か？
    bool is_outside(const BoundingRectangle& rect) const;
    // エリアの取得
    const BoundingRectangle& area() const;

private:
    // ゲーム画面エリア
    BoundingRectangle area_{ 0.0f, 0.0f, 640.0f, 480.0f };
    // 拡張エリア
    BoundingRectangle extend_area_{ -128, -128, 640.0f + 128.0f, 480.0f + 128.0f };
};

#endif
