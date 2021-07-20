#include "Item.h"
#include "Assets.h"
#include "IWorld.h"





// コンストラクタ
Item::Item(IWorld* world, const GSvector3& position) {
    world_ = world;
    name_ = "Item";
    tag_ = "ItemTag";
    velocity_ = GSvector3{ 0.0f, -1.0f, 0.0f };
    transform_.position(position);
    collider_ = BoundingSphere{ 25.0f };
}

// 更新
void Item::update(float delta_time) {
    // アイテムがｙ軸プラス方向を向くように回転させる
    transform_.eulerAngles(-180.0f, 180.0f, 0.0f);
    // 移動する（ワールド座標系基準）
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    
    //GSvector3 position = transform_.position();
   

}

// 描画
void Item::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    //glScalef(7.5f, 7.5f, 7.5f);
    gsDrawMesh(Mesh_Item);
    glPopMatrix();
}

// 衝突処理
void Item::react(Actor& other) {
    // 敵と衝突した場合は死亡
    if (other.tag() == "PlayerTag") {
        die();
    }
}