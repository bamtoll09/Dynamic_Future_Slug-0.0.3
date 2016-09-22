#pragma once
#include "Mover.h"
#include "Bullet.h"

class CEnemy : public CMover
{
public:
	CEnemy();
	~CEnemy();

	std::list<CBullet> bulletList;
	float ShootTimer;
	float PatternTimer;
	float MineTimer;

	void MakeBullet(float x, float y, float angle, float angleRate, float speed, float speedRate);
	void CEnemy::ShootNWay(float x, float y, float angle, float angleRange, float speed, int count, float angleRate, float speedRate)
	{
		if (count > 1)
			for (int i = 0; i < count; i++)
				MakeBullet(x, y, angle + angleRange*((float)i / (count - 1) - 0.5f), angleRate, speed, speedRate);
		else if (count == 1)
			MakeBullet(x, y, angle, angleRate, speed, speedRate);
	}
};

