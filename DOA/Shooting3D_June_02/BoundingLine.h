#ifndef BOUNDING_LINE_H_
#define BOUNDING_LINE_H_

#include <gslib.h>

class BoundingLine {
public:
	//�R���X�g���N�^
	BoundingLine(const GSvector3& pLine0 = GSvector3{ 0.0f,0.0f,0.0f }, const GSvector3& pLine1 = GSvector3{ 0.0f,0.0f,0.0f });
	//���s�ړ�
	//BoundingLine translate(const GSvector3& position)const;
	//���W�ϊ�
	BoundingLine transform(const GSmatrix4& matrix)const;
	//�d�Ȃ��Ă��邩
	bool intersects(const BoundingLine& other)const;
	//�f�o�b�O�\��
	void draw() const;

public:
	GSvector3 pLine0{ 0.0f,0.0f,0.0f };

	GSvector3 pLine1{ 0.0f,0.0f,0.0f };
};

#endif
//gsCollisionPolyAndLine��������
//const GSvector3* pCenter,		/* ���̂̒��S���W			*/
//GSfloat				Radius,			/* ���̂̔��a				*/
//const GSvector3* pLine0,			/* �����̎n�_				*/
//const GSvector3* pLine1,			/* �����̏I�_				*/
//GSvector3* pIntersect		/*-> �����Ƃ̌�_
//const GSvector3& pCenter = GSvector3{ 0.0f,0.0f,0.0f }, float Radius = 0.0f, 