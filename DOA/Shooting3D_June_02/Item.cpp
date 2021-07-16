#include "Item.h"
#include "Assets.h"
#include "IWorld.h"





// コンストラクタ
Item::Item(IWorld* world, const GSvector3& position,const GSvector3& velocity) {
    world_ = world;
    name_ = "Item";
    tag_ = "ItemTag";
    transform_.position(position);
    velocity_ = velocity;
    collider_ = BoundingSphere{ 25.0f };
}

// 更新
void Item::update(float delta_time) {
    // アイテムがｙ軸プラス方向を向くように回転させる
    transform_.eulerAngles(-180.0f, 180.0f, 0.0f);
    // 移動する（ワールド座標系を基準に移動）
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