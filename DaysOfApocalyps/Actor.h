#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <string>
#include "BoundingRectangle.h"

class IWorld;//前方宣言 インクルードを必要としないテクニック
//ポインタ型の変数や参照型の変数を包含している場合と、メンバ関数の引き数として関連している場合のみ許される。

class Actor {
public:
	//コンストラクタ
	Actor() = default;
	//仮想デストラクタ
	virtual ~Actor() = default;
	//更新
	virtual void update(float delta_time);
	//描画
	virtual void draw() const;
	//GUI描画
	virtual void draw_gui() const;
	//衝突時のリアクション
	virtual void react(Actor& other);
	//衝突判定
	void collide(Actor& other);
	// 死亡しているか
	void die();
    // 衝突判定しているか？
    bool is_collide(const Actor& other) const;
    // 死亡しているか？
    bool is_dead() const;
    // 名前を取得
    const std::string& name() const;
    // タグ名を取得
    const std::string& tag() const;
    // 座標を取得
    GSvector2 position() const;
    // 回転角度を取得
    float rotation() const;
    // 移動量を取得
    GSvector2 velocity() const;
    // 衝突判定データを取得
    BoundingRectangle collider() const;
    // コピー禁止
    Actor(const Actor& other) = delete;
    Actor& operator = (const Actor& other) = delete;

protected:
    // ワールド
    IWorld* world_{ nullptr };
    // 名前
    std::string        name_;
    // タグ名
    std::string        tag_;
    // 座標
    GSvector2          position_{ 0.0f, 0.0f };
    // 回転角度
    float              angle_{ 0.0f };
    // 移動量
    GSvector2          velocity_{ 0.0f, 0.0f };
    // 衝突判定が有効か？
    bool               enable_collider_{ true };
    // 衝突判定
    BoundingRectangle  collider_{ 0.0f, 0.0f, 0.0f, 0.0f };
    // 死亡フラグ
    bool               dead_{ false };
    // テクスチャＩＤ 
    GSuint             texture_{ 0 };
};

#endif