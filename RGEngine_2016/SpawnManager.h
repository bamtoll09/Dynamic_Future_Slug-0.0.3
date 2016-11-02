#pragma once
#include "Normal.h"
#include "Drone.h"
#include "Turret.h"
#include "Boss1.h"

#define SpawnMgr CSpawnManager::GetInstance()

enum { NORMAL = 1 };

namespace Enemy
{
	enum Type
	{
		Normal,
		Drone,
		Turret,
		Mid_Boss
	};
}

using namespace std;

class CSpawnManager
{
private:
	list<CEnemy*> enemyList;
public:
	CSpawnManager();
	~CSpawnManager();

	static CSpawnManager *GetInstance();

	void addEnemy(float x, float y, int type = Enemy::Normal);
	void addEnemy(const RGEngine::Math::Vector &v, int type = Enemy::Normal);
	void deleteEnemy(CEnemy *enemy);
	void popEnemy();
};