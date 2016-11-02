#include "Enemy.h"
#include "BulletManager.h"
#include "SpawnManager.h"
#include "TestScene.h"

CEnemy::CEnemy() : ShootTimer(0), PatternTimer(0), MineTimer(0)
{
	tag = "Enemy";
}

CEnemy::~CEnemy()
{
}

void CEnemy::MakeBullet(float x, float y, float angle, float angleRate, float speed, float speedRate)
{
	auto temp = new CBullet(x, y, angle, angleRate, speed, speedRate);
	temp->tag = "EBullet";
	RGApp->GetScene<TestScene>()->PushBackGameObject(temp);
	BM->bulletList.push_back(temp);
}

void CEnemy::Move()
{
	if (hp <= 0)
	{
		SpawnMgr->deleteEnemy(this);
	}
}