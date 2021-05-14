#ifndef IWORLD_H_
#define IWORLD_H_

#include <string>

class IWorld {
public:
	//仮想デストラクタ
	virutual ~IWorld() = default;
	//アクターを追加
	virtual void add_actor(Actor* actor) = 0;
	//アクターの検索
	virtual Actor* find_actor(const std::string& name) const = 0;

	//このクラス抽象クラスだから実体持てない。全部ポインタだよ
};

#endif 

