#include "World.h"

// �X�V
void World::update(float delta_time) {
    actors_.update(delta_time);	// �X�V
    actors_.collide();		// �Փ˔���
    actors_.remove();		// ���S���Ă���A�N�^�[�̍폜
}

// �`��
void World::draw() const {
    actors_.draw();
}

// ����
void World::clear() {
    actors_.clear();
}

// �A�N�^�[�̒ǉ��i���[���h���ۃC���^�[�t�F�[�X�̎����j
void World::add_actor(Actor* actor) {
    actors_.add(actor);
}

// �A�N�^�[�̌����i���[���h���ۃC���^�[�t�F�[�X�̎����j
Actor* World::find_actor(const std::string& name) const {
    return actors_.find(name);
}