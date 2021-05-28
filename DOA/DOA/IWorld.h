#ifndef IWORLD_H_
#define IWORLD_H_

#include <string>

class Actor; // アクタークラスの前方宣言
class Field;

// ワールド抽象インターフェース
class IWorld {
public:
    // 仮想デストラクタ
    virtual ~IWorld() = default;
    // アクターを追加
    virtual void add_actor(Actor* actor) = 0;
    // アクターの検索
    virtual Actor* find_actor(const std::string& name) const = 0;
    // フィールドの取得
    virtual Field& field() = 0;
    // スコアの加算
    virtual void add_score(int score) = 0;

};

#endif
