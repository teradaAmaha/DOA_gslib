#ifndef BOM_EXPLOSION_H_
#define BOM_EXPLOSION_H_

#include "Actor.h"

class BomExplosion :public Actor {
public:
	//�R���X�g���N�^
	BomExplosion(IWorld* world, const GSvector3& position);
	//�X�V
	virtual void update(float delta_time) override;


};

#endif // !BOM_EXPLOSION_H_


