#include "MineExplode.h"

CMineExplode::CMineExplode(Math::Vector pos) : deleteTimer(0)
{
	InitImage("resources/Boom/Explode.png");
	this->position = pos;
}

CMineExplode::~CMineExplode()
{
}

void CMineExplode::Move()
{
	if (deleteTimer >= 0.5)
		this->Destroy();
	deleteTimer+=deltaTime();
}