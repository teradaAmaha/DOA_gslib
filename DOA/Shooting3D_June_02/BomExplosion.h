#ifndef BOM_EXPLOSION_H_
#define BOM_EXPLOSION_H_

#include "Actor.h"

class BomExplosion :public Actor {
public:
	//コンストラクタ
	BomExplosion(IWorld* world, const GSvector3& position);
	//更新
	virtual void update(float delta_time) override;


};

#endif // !BOM_EXPLOSION_H_


