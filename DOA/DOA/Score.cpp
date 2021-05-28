#include "Score.h"
#include "NumberTexture.h"
#include "TextureID.h"
#include <gslib.h>
#include <algorithm> // std::min関数のために必要

// コンストラクタ
Score::Score(int score) :
    score_{ score } {
}

// スコアの初期化
void Score::initialize(int score) {
    score_ = score;
}

// スコアの加算
void Score::add(int score) {
    // スコアの上限値を9999999とする
    score_ = std::min(score_ + score, 9999999);
}

// スコアの描画
void Score::draw() const {
    static const NumberTexture number{ TextureNumber, 16, 16 };

    number.draw(GSvector2{ 520, 0 }, score_, 7);

}

// スコアの取得
int Score::get() const {
    return score_;
}


// スコアのクリア
void Score::clear() {
    score_ = 0;
}

