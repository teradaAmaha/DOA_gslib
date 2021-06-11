#ifndef WORLD_H_
#define WORLD_H_

#include "IWorld.h"
#include "ActorManager.h"
#include"Field.h"
#include "Score.h"
#include "Timer.h"
#include "BaseLife.h"
#include "Base.h"

// ワールドクラス
class World : public IWorld {
public:
    // コンストラクタ
    World() = default;
    // 更新
    void update(float delta_time);
    // 描画
    void draw() const;
    // 消去
    void clear();
    // アクターの追加（ワールド抽象インターフェースの実装）
    virtual void add_actor(Actor* actor) override;
    // アクターの検索（ワールド抽象インターフェースの実装）
    virtual Actor* find_actor(const std::string& name) const override;
    //フィールドの取得
    virtual Field& field()override;
    // スコアの加算
    virtual void add_score(int score) override;
    //タイムの減算
    virtual void  sub_timer(int timer) override;
    //hpの減算
    virtual void sub_hp(int hp) override;

    // ゲームオーバー
    virtual void game_over() override;
    // ゲームクリア
    virtual void game_clear() override;

    // ゲームオーバーか？
    bool is_game_over() const;
    // ゲームクリアか？
    bool is_game_clear() const;

    Timer& get_timer() {
        return timer_;
    };

  /*  Base* get_base(){
        return &life;
    };*/

    // コピー禁止
    World(const World& other) = delete;
    World& operator = (const World& other) = delete;
private:
    // アクターマネージャー
    ActorManager actors_;
    //フィールド
    Field field_;
    // スコア
    Score		score_;
    //タイマー
    Timer timer_;

    //Base Life;

    BaseLife baselife;

    // ゲームオーバーか？
    bool            is_game_over_{ false };
    // ゲームクリアか？
    bool            is_game_clear_{ false };

};

#endif



