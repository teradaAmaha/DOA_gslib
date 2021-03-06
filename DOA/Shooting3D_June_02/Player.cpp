#include "Player.h"
#include "Assets.h"
#include "IWorld.h"
#include "PlayerBullet.h"


// 移動範囲
const float MovingRangeX = 130.0f;
const float MovingRangeY = 70.0f;


// コンストラクタ
Player::Player(IWorld* world, const GSvector3& position) {
	world_ = world;
	name_ = "Player";
	tag_ = "PlayerTag";
	transform_.position(position);
	collider_ = BoundingSphere{ 5.0f };
	// 自機がｙ軸プラス方向を向くように回転させる
	transform_.eulerAngles(90.0f, 180.0f, 0.0f);
}

// 更新
void Player::update(float delta_time) {

<<<<<<< HEAD
	
	transform_.eulerAngles(90.0f, 140.0f, 0.0f);
	
=======
	// 自機がｙ軸プラス方向を向くように回転させる
	//transform_.eulerAngles(90.0f, 180.0f, 0.0f);
	float bullet = transform_.position().y + 40.0f;
>>>>>>> origin/master

	// キーボードの入力から移動量を決める
	GSvector3 inputVelocity{ 0.0f, 0.0f, 0.0f };
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE) {
		inputVelocity.x = -1.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE) {
		inputVelocity.x = 1.0f;
	}
	// 移動量を計算
	float speed = 2.0f;    // 移動スピード
	velocity_ = inputVelocity.normalized() * speed * delta_time;
	// 座標を取得
	GSvector3 position = transform_.position();
	// 座標に移動量を加算
	position += velocity_;
	// 画面外に出ないように移動範囲を制限する
	position.x = CLAMP(position.x, -MovingRangeX-15.0f, MovingRangeX);
	position.y = CLAMP(position.y, -MovingRangeY, MovingRangeY);
	// 座標の設定
	transform_.position(position);


<<<<<<< HEAD

	//if (isItem == true)
	//{ //カウントしておく

	//	if (timer_ <= 360) {
	//		world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 4.0f, 0.0f }));
	//		world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_2, 4.0f, 0.0f }));
	//		world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_1, 4.0f, 0.0f }));
	//		gsPlaySE(Se_WeaponPlayer);
	//	}
	//	else
	//	{
	//		timer_ = 0;
	//		isItem = false;
	//	}
	//}
	//else if (isItem == false)
	//{
	//	world_->add_actor(
	//		new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 4.0f, 0.0f }));
	//	 ショット音を再生
	//	gsPlaySE(Se_WeaponPlayer);
	//}
=======
>>>>>>> origin/master
	//状態
	switch (state_)
	{
	case Player::State::nomal:
		nomal_state_(delta_time);
		break;
	case Player::State::get_item_:
		get_item_state_(delta_time);
		break;

	}
}






// 描画
void Player::draw() const {
	glPushMatrix();
	glMultMatrixf(transform_.localToWorldMatrix());
	gsDrawMesh(Mesh_Player);
	glPopMatrix();
}

// 衝突処理
void Player::react(Actor& other) {
	// 敵と衝突した場合は死亡

	if (other.tag() == "EnemyTag") {
		//die();
		// 爆発音を再生
		//gsPlaySE(Se_ExplosionPlayer);
		state_ = State::nomal;
	}
	if (other.tag() == "ItemTag") {

<<<<<<< HEAD
		isItem = true;
		gsPlaySE(Se_WeaponChange);


=======
		gsPlaySE(Se_WeaponChange);

>>>>>>> origin/master
		state_ = State::get_item_;

	}

}

//通常状態
void Player::nomal_state_(float delta_time)
{

	if (gsGetKeyTrigger(GKEY_Z) == GS_TRUE) {
		world_->add_actor(
			new PlayerBullet(world_, transform_.position() + GSvector3{ 10.0f,0.0f,0.0f }, GSvector3{ 0.0f, 4.0f, 0.0f }));
		// ショット音を再生
		gsPlaySE(Se_WeaponPlayer);
	}
}

void Player::get_item_state_(float delta_time)
{
	//タイマー

	timer_++;

	//角度
	angle_1 += 0.001;
	angle_2 -= 0.001;

	if (gsGetKeyTrigger(GKEY_Z) == GS_TRUE) {

		new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_1, 4.0f, 0.0f });
		if (timer_ < 600)
		{
			world_->add_actor(new PlayerBullet(world_, transform_.position() + GSvector3{ 10.0f,0.0f,0.0f }, GSvector3{ 0.0f, 4.0f, 0.0f }));
			world_->add_actor(new PlayerBullet(world_, transform_.position() + GSvector3{ 10.0f,0.0f,0.0f }, GSvector3{ 0.0f + angle_2, 4.0f, 0.0f }));
			world_->add_actor(new PlayerBullet(world_, transform_.position() + GSvector3{ 10.0f,0.0f,0.0f }, GSvector3{ 0.0f + angle_1, 4.0f, 0.0f }));
			// ショット音を再生
			gsPlaySE(Se_WeaponPlayer);

		}
		else if (timer_ > 600)
		{
			state_ = State::nomal;
			timer_ = 0;
		}
	}
}
