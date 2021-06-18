#include "Actor.h"

// 更新
void Actor::update(float delta_time) {}

// 描画
void Actor::draw() const {
    // スプライトの表示
    
    gsDrawSprite2D(texture_, &position_, NULL, NULL, NULL, NULL, angle_);
    gsDrawMesh(texture_);
}

// GUI描画
void Actor::draw_gui() const {}

// 衝突時リアクション
void Actor::react(Actor& other) {}

// 衝突判定
void Actor::collide(Actor& other) {
    // どちらのアクターも衝突判定が有効か？
    if (enable_collider_ && other.enable_collider_) {
        // 衝突判定をする
        if (is_collide(other)) {
            // 衝突した場合は、お互いに衝突リアクションをする
            react(other);
            other.react(*this);
        }
    }
}

// 死亡する
void Actor::die() {
    dead_ = true;
}

// 衝突判定しているか？
bool Actor::is_collide(const Actor& other) const {
    return collider().intersects(other.collider());
}

// 死亡しているか？
bool Actor::is_dead() const {
    return dead_;
}

// 名前を取得
const std::string& Actor::name() const {
    return name_;
}

// タグ名を取得
const std::string& Actor::tag() const {
    return tag_;
}

// 座標を取得
GSvector2 Actor::position() const {
    return position_;
}

// 回転角度を取得
float Actor::rotation() const {
    return angle_;
}

// 移動量を取得
GSvector2 Actor::velocity() const {
    return velocity_;
}

// 衝突判定データを取得
BoundingRectangle Actor::collider() const {
    return collider_.translate(position_);
   // return collider_.translate3D(position3D_);
}
//
//BoundingRectangle Actor::collider() const {
//    return collider_.translate(position_);
//}