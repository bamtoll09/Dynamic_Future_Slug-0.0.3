#include "Bullet.h"

CBullet::CBullet(float x, float y, float angle, float angleRate, float speed, float speedRate, BulletShape bulletShape) : Angle(angle), AngleRate(angleRate), Speed(speed), SpeedRate(speedRate)
{
	position.SetVector(x, y);
	tag = "Bullet";
	InitImage("resources/Bullet/Bullet.png");
	auto collider = AttachComponent<Components::CircleCollider>();
	float radius = ((float)sprite->GetTexture()->GetWidth()) / 2;
	Math::Vector colliderCenter((float)sprite->GetTexture()->GetWidth() / 2, (float)sprite->GetTexture()->GetHeight() / 2);
	collider->circle.SetCircle(colliderCenter.x, colliderCenter.y, radius);
}

void CBullet::Move()
{
	float rad = Angle * D3DX_PI * 2;
	
	this->center.x += (Speed * cosf(rad) * deltaTime() * 50) * 640;
	this->center.y += (Speed * sinf(rad) * deltaTime() * 50) * 512;

	Angle += AngleRate;
	Speed += SpeedRate;

	if (center.x <= -100 || center.x >= 1300 || center.y <= -1000 || center.y >= 1040)
		this->Destroy();
}