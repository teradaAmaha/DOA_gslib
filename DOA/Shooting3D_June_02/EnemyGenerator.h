#ifndef ENEMY_GENERATOR_H_
#define ENEMY_GENERATOR_H_

#include "Actor.h"
#include "CSVReader.h"

// �G�����N���X
class EnemyGenerator : public Actor {
public:
    // �R���X�g���N�^
    EnemyGenerator(IWorld* world, const std::string& file_name);
    // �X�V
    virtual void update(float delta_time) override;
private:
    // �G�̐���
    void generate();

private:
    // �o���f�[�^
    CsvReader   csv_;
    // ���݂̓ǂݍ��݈ʒu
    int         current_row_{ 0 };
    // �o���^�C�}
    float       timer_{ 0.0f };
};

#endif


