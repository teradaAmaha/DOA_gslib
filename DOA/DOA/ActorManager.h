#ifndef ACTOR_MANAGER_H_
#define ACTOR_MANAGER_H_

#include <list>
#include <string>


class Actor;  // アクタークラスの前方宣言

// アクターマネージャークラス
class ActorManager {
public:
    // コンストラクタ
    ActorManager() = default;
    // デストラクタ
    ~ActorManager();
    // アクターの追加
    void add(Actor* actor);
    // アクターの更新
    void update(float delta_time);
    // アクターの描画
    void draw() const;
    // アクターのGUI描画
    void draw_gui() const;
    // アクターの衝突判定
    void collide();
    // 死亡しているアクターの削除
    void remove();
    // アクターの検索
    Actor* find(const std::string& name) const;
    // 消去
    void clear();
    // コピー禁止
    ActorManager(const ActorManager& other) = delete;
    ActorManager& operator = (const ActorManager& other) = delete;
private:
    // アクターリスト
    std::list<Actor*> actors_;
};

#endif
