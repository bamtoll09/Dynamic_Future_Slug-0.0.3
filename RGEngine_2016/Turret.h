#pragma once
#include "Enemy.h"

class CTurret : public CEnemy
{
public:
	CTurret();
	~CTurret();

	void Move();
};

