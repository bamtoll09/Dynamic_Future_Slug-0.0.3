#include "Enemy.h"
#include "BulletManager.h"
#include "TestScene.h"

CEnemy::CEnemy() : ShootTimer(0), PatternTimer(0), MineTimer(0)
{
}

CEnemy::~CEnemy()
{
}

void CEnemy::MakeBullet(float x, float y, float angle, float angleRate, float speed, float speedRate)
{
	auto temp = new CBullet(x, y, angle, angleRate, speed, speedRate);
	RGApp->GetScene<TestScene>()->PushBackGameObject(temp);
	BM->bulletList.push_back(temp);		
}
