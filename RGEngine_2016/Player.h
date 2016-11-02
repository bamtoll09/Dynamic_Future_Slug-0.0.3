#pragma once
#include "Mover.h"
#include "Bullet.h"
#include "Grenade.h"

class CPlayer : public CMover
{
private:
	bool isOnGround;
	float gravity, weight, speed;
	int life, hp, ap;
	// attribute

	CGrenade *grenades[2];
	//grenade

	bool jump;
	float jumpPower;
	// jump

	float shootTime;
	// attack

	float cameraSpeed;
	// camera_view

public:
	static bool isLeft;

public:
	CPlayer();
	~CPlayer();

	void MakeBullet(float x, float y, float angle, float angleRate, float speed, float speedRate);
	void PrecomposeGrenade(CGrenade *grenades[]);
	void ThrowGrenade();

	void Move();
};

