#include "World.h"

// �X�V
void World::update(float delta_time) {
    field_.update(delta_time);    // �t�B�[���h�̍X�V
    actors_.update(delta_time);	// �X�V
    actors_.collide();		// �Փ˔���
    actors_.remove();		// ���S���Ă���A�N�^�[�̍폜
}

// �`��
void World::draw() const {
    field_.draw();
    actors_.draw();
    // �X�R�A�̕`��
    score_.draw();

}


// ����
void World::clear() {
    // �A�N�^�[�̏���
    actors_.clear();
    // �X�R�A�̏���
    score_.clear();
    // �Q�[���I�[�o�[�t���O�̏�����
    is_game_over_ = false;
    // �Q�[���N���A�t���O�̏�����
    is_game_clear_ = false;
}

// �A�N�^�[�̒ǉ��i���[���h���ۃC���^�[�t�F�[�X�̎����j
void World::add_actor(Actor* actor) {
    actors_.add(actor);
}

// �A�N�^�[�̌����i���[���h���ۃC���^�[�t�F�[�X�̎����j
Actor* World::find_actor(const std::string& name) const {
    return actors_.find(name);
}
// �t�B�[���h�̎擾
Field& World::field() {
    return field_;
}

// �X�R�A�̉��Z
void World::add_score(int score) {
    score_.add(score);
}

// �Q�[���I�[�o�[
void World::game_over() {
    is_game_over_ = true;
}

// �Q�[���N���A�[
void World::game_clear() {
    is_game_clear_ = true;
}

// �Q�[���I�[�o�[���H
bool World::is_game_over() const {
    return is_game_over_;
}

// �Q�[���N���A���H
bool World::is_game_clear() const {
    return is_game_clear_;
}
