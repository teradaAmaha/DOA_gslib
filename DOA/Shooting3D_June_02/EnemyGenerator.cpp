#include "EnemyGenerator.h"
#include "IWorld.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "Bomboss.h"
#include "Item.h"

const int CsvTime{ 0 };	// �^�C�}�̗�
const int CsvName{ 1 };	// ���O�̗�
const int CsvPosition{ 2 }; // ���W�̗�
const int CsvVelocity{ 5 }; // �ړ��ʂ̗�

// �R���X�g���N�^
EnemyGenerator::EnemyGenerator(IWorld* world, const std::string& file_name) {
    world_ = world;
    name_ = "EnemeyGenerator";
    tag_ = "Generator";
    csv_.load(file_name);    // CSV�t�@�C���̓ǂݍ���
}

// �X�V
void EnemyGenerator::update(float delta_time) {
    // CSV�̃f�[�^���܂����� && �o�����Ԃł����
    while (current_row_ < csv_.rows()
        && (csv_.getf(current_row_, CsvTime) * 60.0f) <= timer_) {
        // �G�̐���
        generate();
        // CSV�f�[�^�̓ǂݍ��ݍs���X�V
        ++current_row_;
    }
    // �o���^�C�}�̍X�V
    timer_ += delta_time;

}

// ����
void EnemyGenerator::generate() {
    // ���O���擾
    std::string name = csv_.get(current_row_, CsvName);
    // ���W���擾
    GSvector3 position{
        csv_.getf(current_row_, CsvPosition + 0),
        csv_.getf(current_row_, CsvPosition + 1),
        csv_.getf(current_row_, CsvPosition + 2) };
    // �L�����N�^�̐���
    if (name == "Enemy") {
        // �G�̐���
        world_->add_actor(new Enemy{ world_, position });
    }
    else if (name == "Asteroid") {
        // 覐΂̏ꍇ�͈ړ��ʂ��擾
        GSvector3 velocity{
            csv_.getf(current_row_, CsvVelocity + 0),
            csv_.getf(current_row_, CsvVelocity + 1),
            csv_.getf(current_row_, CsvVelocity + 2) };
        // 覐΂̐���
        world_->add_actor(new Asteroid{ world_, position, velocity });
    }
    else if (name == "Bomboss")
    {
        // ���W���擾
        world_->add_actor(new Bomboss{ world_, position });
    }
    // �L�����N�^�̐���
    else if (name == "Item") {
        // �G�̐���
        world_->add_actor(new Item{ world_, position});
    }
}

