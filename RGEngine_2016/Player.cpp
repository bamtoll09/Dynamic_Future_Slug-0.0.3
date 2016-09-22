#include "Player.h"
#include "BulletManager.h"
#include "TestScene.h"

CPlayer::CPlayer() : speed(200.f), jumpTime(0.f), jump(false), jumpUp(false)
{
	InitImage("resources/Player/Player.png");
}

CPlayer::~CPlayer()
{
}

void CPlayer::MakeBullet(float x, float y, float angle, float angleRate, float speed, float speedRate)
{
	auto temp = new CBullet(x, y, angle, angleRate, speed, speedRate);
	RGApp->GetScene<TestScene>()->PushBackGameObject(temp);
	BM->bulletList.push_back(temp);
}

void CPlayer::Move()
{
	if (RGInput->Press(DIK_A))
	{
		this->position.Transform(-speed * deltaTime(), 0.f);
	}

	if (RGInput->Press(DIK_D))
	{
		this->position.Transform(speed * deltaTime(), 0.f);
	}

	if (RGInput->Press(DIK_UPARROW))
		speed += 100.f;
	else if (RGInput->Press(DIK_DOWNARROW))
		speed -= 100.f;

	if (!jump)
	{
		if (RGInput->Trigger(DIK_SPACE))
		{
			jump = true;
			jumpUp = true;
		}
	}

	if (jump)
	{
		if (jumpTime <= 0.4f)
			this->position.SetVector(this->position.x, this->position.y + (-320 * powf(jumpTime, 3.f) + 192 * powf(jumpTime, 2.f) + -25.6f*jumpTime) * 20.f);
		else
		{
			jump = false;
			jumpTime = 0.f;
		}
		
		//this->position.SetVector(this->position.x, this->position.y + (100 * powf((jumpTime - 0.1f), 2.f) - 1.f) * 50.f);

		/*if (jumpUp && jumpTime <= 0.2f)	{
			this->position.SetVector(this->position.x, this->position.y + (-1 * powf(320*jumpTime, 3.f) - powf(-192 * jumpTime, 2.f) - 25.6f*jumpTime) * 50.f);
		} else if (jumpUp) {
			jumpUp = false;
		} else if (!jumpUp && jumpTime <= 0.4f) {
			this->position.SetVector(this->position.x, this->position.y + (-1 * powf(320*jumpTime, 3.f) - powf(-192 * jumpTime, 2.f) - 25.6f*jumpTime) * 50.f);
		} else if (!jumpUp) {
			jump = false;
			jumpTime = 0.f;
		}*/

		jumpTime += deltaTime();
	}
}