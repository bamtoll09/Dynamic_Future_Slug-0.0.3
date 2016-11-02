#pragma once
#include "Bullet.h"

class CConstrainedHomingBullet : public CBullet
{
public:
	//�ִ� ��ȸ ���ӵ�
	float MaxAngleRate;
	
public:
	CConstrainedHomingBullet(BulletShape shapeType, float x,float y,float angle, float speed, float maxAngleRate);
	~CConstrainedHomingBullet();
	void Move();
	float GetMyShipAngle(float x, float y);
};

