#include "TitleScene.h"
#include "TextureID.h"

// 開始
void TitleScene::start() {
    // 画像の読み込み
    gsLoadTexture(TextureTitleLogo, "Assets/TITLE1.png");
    gsLoadTexture(TextureTitleStart, "Assets/TITLE2.png");
  /*  gsLoadTexture(TextureBG1, "Assets/BG1.png");
    gsLoadTexture(TextureBG2, "Assets/BG2.png");
    gsLoadTexture(TextureBG3, "Assets/BG3.png");*/
    gsLoadTexture(TextureBG4, "Assets/BG4.png");
    // 終了フラグの初期化
    is_end_ = false;
}

// 更新
void TitleScene::update(float delta_time) {
    // エンターキーを押したらシーン終了
    if (gsGetKeyTrigger(GKEY_RETURN)) {
        is_end_ = true;     // シーン終了
    }
    // 背景のスクロール値を更新
    scroll_ += delta_time;
}

// 描画
void TitleScene::draw() const {
    // 背景の描画
    draw_background(TextureBG3, scroll_ * 0.5f);
    draw_background(TextureBG2, scroll_ * 2.0f);
    draw_background(TextureBG1, scroll_ * 3.0f);
    gsDrawSprite2D(TextureBG4,0 , NULL, NULL, NULL, NULL, 0.0f);
    // タイトルロゴの描画
    const static GSvector2 position_logo{ 400.0f, 60.0f };
    gsDrawSprite2D(TextureTitleLogo, &position_logo, NULL, NULL, NULL, NULL, 0.0f);
    // 操作方法の描画
    const static GSvector2 position_start{ 500.0f, 350.0f };
    gsDrawSprite2D(TextureTitleStart, &position_start, NULL, NULL, NULL, NULL, 0.0f);
}

// 終了しているか？
bool TitleScene::is_end() const {
    return is_end_;         // 終了フラグを返す
}

// 次のシーン名を返す
std::string TitleScene::next() const {
    return "GamePlayScene"; // 次のシーン名を返す
}

// 終了
void TitleScene::end() {
    // 画像の削除
    gsDeleteTexture(TextureTitleLogo);
    gsDeleteTexture(TextureTitleStart);
    gsDeleteTexture(TextureBG1);
    gsDeleteTexture(TextureBG2);
    gsDeleteTexture(TextureBG3);
    gsDeleteTexture(TextureBG4);
    //背景
}

// 背景の描画
void TitleScene::draw_background(GSuint id, float scroll) const {
    GSrect rect{ scroll, 0.0f, scroll + 1280.0f, 720.0f };
    gsDrawSprite2D(id, NULL, &rect, NULL, NULL, NULL, 0.0f);
}

