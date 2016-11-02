#include "Bullet.h"
#include "BulletManager.h"
#include "SpawnManager.h"

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
	
	this->position.x -= (Speed * cosf(rad) * deltaTime() * 50) * 640;
	this->position.y -= (Speed * sinf(rad) * deltaTime() * 50) * 512;

	Angle += AngleRate;
	Speed += SpeedRate;

	if (position.x < -sprite->GetTexture()->GetWidth() || position.x > RGApp->GetGraphic()->GetScreenWidth() || position.y < -sprite->GetTexture()->GetHeight() || position.y > RGApp->GetGraphic()->GetScreenHeight())
	{
		BM->bulletList.remove(this);
		this->Destroy();
	}
}

void CBullet::OnCollision(GameObject *col)
{
	/*if (tag.compare("EBullet") == 0 && col->tag.compare("Player") == 0)
	{
		col->Destroy();

		BM->bulletList.remove(this);
		this->Destroy();

	}
	else */if (tag.compare("PBullet") == 0 && col->tag.compare("Enemy") == 0) {

		//SpawnMgr->deleteEnemy((CEnemy*)col);
		col->Destroy();

		BM->bulletList.remove(this);
		this->Destroy();
	}
	else if (col->tag.compare("Board") == 0) {
		BM->bulletList.remove(this);
		this->Destroy();
	}
}