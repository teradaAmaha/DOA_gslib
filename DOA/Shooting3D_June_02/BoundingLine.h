#ifndef BOUNDING_LINE_H_
#define BOUNDING_LINE_H_

#include <gslib.h>

class BoundingLine {
public:
	//コンストラクタ
	BoundingLine(const GSvector3& pLine0 = GSvector3{ 0.0f,0.0f,0.0f }, const GSvector3& pLine1 = GSvector3{ 0.0f,0.0f,0.0f });
	//平行移動
	//BoundingLine translate(const GSvector3& position)const;
	//座標変換
	BoundingLine transform(const GSmatrix4& matrix)const;
	//重なっているか
	bool intersects(const BoundingLine& other)const;
	//デバッグ表示
	void draw() const;

public:
	GSvector3 pLine0{ 0.0f,0.0f,0.0f };

	GSvector3 pLine1{ 0.0f,0.0f,0.0f };
};

#endif
//gsCollisionPolyAndLineをつかって
//const GSvector3* pCenter,		/* 球体の中心座標			*/
//GSfloat				Radius,			/* 球体の半径				*/
//const GSvector3* pLine0,			/* 線分の始点				*/
//const GSvector3* pLine1,			/* 線分の終点				*/
//GSvector3* pIntersect		/*-> 線分との交点
//const GSvector3& pCenter = GSvector3{ 0.0f,0.0f,0.0f }, float Radius = 0.0f, 