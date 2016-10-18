#include "Player.h"
#include "BulletManager.h"
#include "GameManager.h"
#include "TestScene.h"

bool CPlayer::isLeft{ NULL };

CPlayer::CPlayer() : isOnGround(true), gravity(0.f), speed(250.f), weight(20.f), //attribute
					 jump(false), jumpPower(600.f), // jump
					 cameraSpeed(150.f) //camera_view
{
	isLeft = false;
	tag = "Player";
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

void CPlayer::PrecomposeGrenade(CGrenade *_grenades[])
{
	for (int i = 0; i < 2; i++)
	{
		grenades[i] = _grenades[i];
		grenades[i]->SetEnabled(false);
	}
}

void CPlayer::ThrowGrenade()
{
	float x = position.x + sprite->GetTexture()->GetWidth();

	if (isLeft)
		x = position.x;

	if (!grenades[0]->GetEnabled())
	{
		grenades[0]->SetEnabled(true);
		grenades[0]->position.SetVector(x, position.y + sprite->GetTexture()->GetHeight() / 2.f);
	}
	else if (!grenades[1]->GetEnabled())
	{
		grenades[1]->SetEnabled(true);
		grenades[1]->position.SetVector(x, position.y + sprite->GetTexture()->GetHeight() / 2.f);
	}
}

void CPlayer::Move()
{
	if (RGInput->Press(DIK_LEFTARROW))
	{
		this->position.Transform(-speed * deltaTime(), 0.f);
		isLeft = true;
	}
	// Move Left

	if (RGInput->Press(DIK_RIGHTARROW))
	{
		this->position.Transform(speed * deltaTime(), 0.f);
		isLeft = false;
	}
	// Move Right

	if (RGInput->Press(DIK_UPARROW))
	{
		printf("%f, %f\n", RGApp->GetScene()->GetCamera()->position.x, RGApp->GetScene()->GetCamera()->position.y);
		if (RGApp->GetScene()->GetCamera()->position.y < 150.f)
			RGApp->GetScene()->GetCamera()->position.Transform(0.f, cameraSpeed * deltaTime());
	}
	// CameraView Up

	else if (RGInput->Press(DIK_DOWNARROW))
	{
		printf("%f, %f\n", RGApp->GetScene()->GetCamera()->position.x, RGApp->GetScene()->GetCamera()->position.y);
		if (RGApp->GetScene()->GetCamera()->position.y > -150.f)
			RGApp->GetScene()->GetCamera()->position.Transform(0.f, -cameraSpeed * deltaTime());
	}
	// CameraView Down

	else if (RGApp->GetScene()->GetCamera()->position.y != 0.f)
	{
		if (RGApp->GetScene()->GetCamera()->position.y < 0.f)
		{
			if (RGApp->GetScene()->GetCamera()->position.y + (cameraSpeed * deltaTime()) > 0.f)
				RGApp->GetScene()->GetCamera()->position.y = 0.f;
			else
				RGApp->GetScene()->GetCamera()->position.Transform(0.f, cameraSpeed * deltaTime());
		}
		// CameraView Return (Up)
		else if (RGApp->GetScene()->GetCamera()->position.y > 0.f)
		{
			if (RGApp->GetScene()->GetCamera()->position.y - (cameraSpeed * deltaTime()) < 0.f)
				RGApp->GetScene()->GetCamera()->position.y = 0.f;
			else
				RGApp->GetScene()->GetCamera()->position.Transform(0.f, -cameraSpeed * deltaTime());
		}
		// CameraView Return (Down)
	}
	// CameraView Return

	if (RGInput->Trigger(DIK_Z))
	{
		printf("attack\n");
	}
	// Attack (unimplement)

	if (RGInput->Trigger(DIK_X))
	{
		ThrowGrenade();
		//printf("grenade\n");
	}
	// Grenade (unimplement)


	if (!jump)
	{
		if (RGInput->Trigger(DIK_C))
		{
			jump = true;
			isOnGround = false;
		}
	}
	if (jump)
	{
		position.SetVector(position.x, position.y - (jumpPower * deltaTime()));

		/*
		if (jumpTime <= 0.4f)
			this->position.SetVector(this->position.x, this->position.y + (-320 * powf(jumpTime, 3.f) + 192 * powf(jumpTime, 2.f) + -25.6f*jumpTime) * 20.f);
		else
		{
			jump = false;
			jumpTime = 0.f;
		}
		
		//this->position.SetVector(this->position.x, this->position.y + (100 * powf((jumpTime - 0.1f), 2.f) - 1.f) * 50.f);

		//
		if (jumpUp && jumpTime <= 0.2f)	{
			this->position.SetVector(this->position.x, this->position.y + (-1 * powf(320*jumpTime, 3.f) - powf(-192 * jumpTime, 2.f) - 25.6f*jumpTime) * 50.f);
		} else if (jumpUp) {
			jumpUp = false;
		} else if (!jumpUp && jumpTime <= 0.4f) {
			this->position.SetVector(this->position.x, this->position.y + (-1 * powf(320*jumpTime, 3.f) - powf(-192 * jumpTime, 2.f) - 25.6f*jumpTime) * 50.f);
		} else if (!jumpUp) {
			jump = false;
			jumpTime = 0.f;
		}
		//

		jumpTime += deltaTime();
		*/
	}
	// Jump

	if (RGInput->Trigger(DIK_G))
	{
		printf("ultimate\n");
	}
	// Ultimate (unimplement)

	if (RGInput->Trigger(DIK_R))
	{
		printf("reload\n");
	}
	// Reload (unimplement)

	if (RGInput->Trigger(DIK_LCONTROL))
	{
		printf("sliding\n");
	}
	// Sliding (unimplement)

	if (!isOnGround)
	{
		gravity += ((CGameManager::g + weight) * deltaTime());

		// When dropped pos overlaps with ground
		// Set player's position on the ground
		if ((position.y + sprite->GetTexture()->GetHeight() + gravity) >= RGGraphic->GetScreenHeight())
		{
			position.SetVector(position.x, RGGraphic->GetScreenHeight() - sprite->GetTexture()->GetHeight());

			isOnGround = true;
			jump = false;
			gravity = 0.f;
		}
		else
			position.Transform(0.f, gravity);
	}
	// Gravity
	
}