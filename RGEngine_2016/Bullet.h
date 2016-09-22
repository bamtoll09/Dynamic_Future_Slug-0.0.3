#pragma once
#include "Mover.h"

class CBullet : public CMover
{
public:
	float Angle;
	float AngleRate;
	float Speed;
	float SpeedRate;

public:
	CBullet(float x, float y, float angle, float angleRate, float speed, float speedRate, BulletShape shapeType = Red);
	~CBullet() {}

	virtual void Move();
};

