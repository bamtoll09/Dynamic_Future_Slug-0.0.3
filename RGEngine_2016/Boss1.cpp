#include "Boss1.h"
#include "TestScene.h"

CBoss1::CBoss1() : mineCount(0)
{
	InitImage("resources/Boss/Boss.png");
}

CBoss1::~CBoss1()
{
}

void CBoss1::Move()
{
	Math::Vector centerPos;
	centerPos.SetVector(position.x + (float)sprite->GetTexture()->GetWidth() / 2, position.y + (float)sprite->GetTexture()->GetHeight() / 2);

	if (ShootTimer >= 0.2f && PatternTimer <= 1.1f)
	{
		ShootTimer = 0;
		ShootNWay(centerPos.x, centerPos.y, 0.01f, 0.1f, 0.03f, 2, 0, 0);
	}
	else if (ShootTimer >= 0.2f && PatternTimer <= 3 && PatternTimer > 2)
	{
		ShootTimer = 0;
		MakeBullet(centerPos.x, centerPos.y, 0, 0, 0.03f, 0);
	}
	else if (ShootTimer >= 0.2f && PatternTimer <= 5 && PatternTimer > 4)
	{
		ShootTimer = 0;
		ShootNWay(centerPos.x, centerPos.y, 0.01f, 0.1f, 0.03f, 2, 0, 0);

	}
	else if (PatternTimer <= 6 && PatternTimer > 5)
		mineCount = 0;
	else if (ShootTimer >= 0.2f && PatternTimer <= 7 && PatternTimer > 6)
	{
		ShootTimer = 0;
		MakeBullet(centerPos.x, centerPos.y, 0, 0, 0.03f, 0);
	}
	//Áö·Ú
	if (MineTimer >= 0.4f && PatternTimer <= 5 && PatternTimer >= 4)
	{
		MineTimer = 0;
		auto temp = new CMine();
		if (mineCount == 0)
			temp->position.SetVector(850, 840);
		else if (mineCount == 1)
			temp->position.SetVector(700, 840);
		else
			temp->position.SetVector(550, 840);
		RGApp->GetScene<TestScene>()->PushBackGameObject(temp);
		mineList[mineCount++] = temp;
	}
	//Áö·Ú Á¦°Å
	if (MineTimer >= 0.4f && PatternTimer <= 7 && PatternTimer >= 6)
	{
		MineTimer = 0;
		CMine *mine = mineList[mineCount++];
		Math::Vector tempPos;
		tempPos.SetVector(mine->position.x, mine->position.y - 300);
		RGApp->GetScene<TestScene>()->PushBackGameObject(new CMineExplode(tempPos));
		mine->Destroy();
	}
	PatternTimer += deltaTime();
	ShootTimer += deltaTime();
	MineTimer += deltaTime();
}
