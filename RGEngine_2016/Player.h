#pragma once
#include "Mover.h"
#include "Bullet.h"

class CPlayer : public CMover
{
private:
	float speed;
	float jumpTime;
	bool jump, jumpUp;

public:
	CPlayer();
	~CPlayer();

	void MakeBullet(float x, float y, float angle, float angleRate, float speed, float speedRate);

	virtual void Move() override;
};

