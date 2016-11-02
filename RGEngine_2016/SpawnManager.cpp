#include "SpawnManager.h"

CSpawnManager::CSpawnManager()
{
}

CSpawnManager::~CSpawnManager()
{
}

CSpawnManager* CSpawnManager::GetInstance()
{
	static CSpawnManager instance;
	return &instance;
}

void CSpawnManager::addEnemy(float x, float y, int type)
{
	CEnemy* enemy = new CEnemy();

	switch (type)
	{
	case Enemy::Normal:
		enemy = new CNormal();
		break;
	case Enemy::Drone:
		enemy = new CDrone();
		break;
	case Enemy::Turret:
		enemy = new CTurret();
		break;
	case Enemy::Mid_Boss:
		enemy = new CBoss1();
		break;
	}

	enemy->position.SetVector(x, y);
	RGApp->GetScene()->PushBackGameObject(enemy);
	enemyList.push_back(enemy);
}

void CSpawnManager::addEnemy(const RGEngine::Math::Vector &v, int type)
{
	CEnemy* enemy = new CEnemy();

	switch (type)
	{
	case Enemy::Normal:
		enemy = new CNormal();
		break;
	case Enemy::Drone:
		enemy = new CDrone();
		break;
	case Enemy::Turret:
		enemy = new CTurret();
		break;
	case Enemy::Mid_Boss:
		enemy = new CBoss1();
		break;
	}

	enemy->position.SetVector(v);
	RGApp->GetScene()->PushBackGameObject(enemy);
	enemyList.push_back(enemy);
}

void CSpawnManager::deleteEnemy(CEnemy *enemy)
{
	enemyList.remove(enemy);
	enemy->Destroy();
}

void CSpawnManager::popEnemy()
{
	if (enemyList.size() > 0)
	{
		CEnemy *enemy = enemyList.front();
		enemyList.pop_front();
		enemy->Destroy();
	}
}