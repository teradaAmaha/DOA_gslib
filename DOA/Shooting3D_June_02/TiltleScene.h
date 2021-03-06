#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include "IScene.h"
#include <gslib.h>

class TitleScene :public IScene {
public:
	//開始
	virtual void start() override;
	//更新
	virtual void update(float delta_time) override;
	//描画
	virtual void draw() const override;
	//終了しているか
	virtual bool is_end() const override;
	//次のシーンを返す
	virtual std::string next() const override;
	//終了
	virtual void end() override;
private:
	//終了フラグ
	bool is_end_{ false };
	//スクロール値
	float scroll_{ 0.0f };
};

#endif
