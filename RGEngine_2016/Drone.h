#pragma once
#include "Enemy.h"

class CDrone : public CEnemy
{
public:
	CDrone();
	~CDrone();

	void Move();
};

