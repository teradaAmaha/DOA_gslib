#include "Player.h"
#include "Assets.h"
#include "IWorld.h"
#include "PlayerBullet.h"


// �ړ��͈�
const float MovingRangeX = 100.0f;
const float MovingRangeY = 70.0f;

// �R���X�g���N�^
Player::Player(IWorld* world, const GSvector3& position) {
	world_ = world;
	name_ = "Player";
	tag_ = "PlayerTag";
	transform_.position(position);
	collider_ = BoundingSphere{ 5.0f };
}

// �X�V
void Player::update(float delta_time) {
	// ���@�������v���X�����������悤�ɉ�]������
	transform_.eulerAngles(-90.0f, 180.0f, 0.0f);
	// �L�[�{�[�h�̓��͂���ړ��ʂ����߂�
	GSvector3 inputVelocity{ 0.0f, 0.0f, 0.0f };
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE) {
		inputVelocity.x = -1.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE) {
		inputVelocity.x = 1.0f;
	}
	/*  if (gsGetKeyState(GKEY_UP) == GS_TRUE) {
		  inputVelocity.y = 1.0f;
	  }
	  if (gsGetKeyState(GKEY_DOWN) == GS_TRUE) {
		  inputVelocity.y = -1.0f;
	  }*/
	  // �ړ��ʂ��v�Z
	float speed = 1.0f;    // �ړ��X�s�[�h
	velocity_ = inputVelocity.normalized() * speed * delta_time;
	// ���W���擾
	GSvector3 position = transform_.position();
	// ���W�Ɉړ��ʂ����Z
	position += velocity_;
	// ��ʊO�ɏo�Ȃ��悤�Ɉړ��͈͂𐧌�����
	position.x = CLAMP(position.x, -MovingRangeX, MovingRangeX);
	position.y = CLAMP(position.y, -MovingRangeY, MovingRangeY);
	// ���W�̐ݒ�
	transform_.position(position);
	angle_1 += 0.001;
	angle_2 -= 0.001;
	if (isItem == true)
	{
		timer_++;
	}


	if (isItem == true)
	{//�J�E���g���Ă���
		timer_++;
	}


	//���@����
	if (gsGetKeyTrigger(GKEY_Z) == GS_TRUE) {


		if (isItem == true)
		{ //�J�E���g���Ă���


			world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 4.0f, 0.0f }));
			world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_2, 4.0f, 0.0f }));
			world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 8.0f, 0.0f }));
			gsPlaySE(Se_WeaponPlayer);
			if (timer_ >= 90) {

				new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_1, 4.0f, 0.0f });
				if (timer_ > 360) {
					world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 4.0f, 0.0f }));
					world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_2, 4.0f, 0.0f }));
					world_->add_actor(new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f + angle_1, 4.0f, 0.0f }));
					if (timer_ > 360) {
						timer_ = 0;
						isItem = false;
					}
				}
				else if (isItem == false)
				{
					world_->add_actor(
						new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 4.0f, 0.0f }));
					// �V���b�g�����Đ�
					gsPlaySE(Se_WeaponPlayer);
				}
			}



			timer_ = 0;
			isItem = false;
		}
		else if (isItem == false)
		{
			world_->add_actor(
				new PlayerBullet(world_, transform_.position(), GSvector3{ 0.0f, 4.0f, 0.0f }));
			// �V���b�g�����Đ�
			gsPlaySE(Se_WeaponPlayer);
		}
	}
	

}
		

// �`��
void Player::draw() const {
	glPushMatrix();
	glMultMatrixf(transform_.localToWorldMatrix());
	gsDrawMesh(Mesh_Player);
	glPopMatrix();
}

// �Փˏ���
void Player::react(Actor& other) {
	// �G�ƏՓ˂����ꍇ�͎��S

	if (other.tag() == "EnemyTag") {
		//die();
		// ���������Đ�
		gsPlaySE(Se_ExplosionPlayer);
		isItem = false;
	}
	// �G�ƏՓ˂����ꍇ�͎��S
	if (other.tag() == "ItemTag") {
		isItem = true;
	}

}

