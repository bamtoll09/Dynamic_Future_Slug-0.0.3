#include "Normal.h"

CNormal::CNormal() : CEnemy()
{
	InitImage("resources/Enemy/Normal/Enemy.png");
	hp = 100;
}

CNormal::~CNormal()
{
}

void CNormal::Move()
{
	CEnemy::Move();

	this->position.Transform(-300 * deltaTime(), 0);

	if (this->position.x < 0)
	{
		this->position.SetVector(RGApp->GetGraphic()->GetScreenWidth(), this->position.y);
	} // just fun
}