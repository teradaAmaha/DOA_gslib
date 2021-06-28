#include "TiltleScene.h"
#include "Assets.h"

//開始
void TitleScene::start() {
	//画像の読み込み
	gsLoadTexture(TextureTitleBG, "Assets/2DSprite/BG4.png");
	gsLoadTexture(TextureTitleLogo,"Assets/2DSprite/TITLE1.png");
	//終了フラグ初期化
	is_end_ = false;
}

//更新
void TitleScene::update(float delta_time) {
	//エンターキーを押したらシーン終了
	if (gsGetKeyTrigger(GKEY_RETURN)) {
		is_end_ = true;
	}
	
}

//描画
void TitleScene::draw() const {
	//背景の描画
	gsDrawSprite2D(TextureTitleBG, 0, NULL, NULL, NULL, NULL, 0.0f);
	//タイトルロゴの描画位置
	const static GSvector2 position_logo{ 64.0f, 50.0f };
	//タイトルロゴの描画
	gsDrawSprite2D(TextureTitleLogo, &position_logo, NULL, NULL, NULL, NULL, 0.0f);
}

bool TitleScene::is_end() const {
	return is_end_; //終了グラフを返す
}

//次のシーンを返す
std::string TitleScene::next() const {
	return "GamePlayScene";//次のシーン名を返す
}

void TitleScene::end() {
	//画像の削除
	gsDeleteTexture(TextureTitleBG);
	gsDeleteTexture(TextureTitleLogo);
}
