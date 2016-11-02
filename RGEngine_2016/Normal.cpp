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
	this->position.Transform(-300 * deltaTime(), 0);

	if (this->position.x < -sprite->GetTexture()->GetWidth())
	{
		this->position.SetVector(RGApp->GetGraphic()->GetScreenWidth(), this->position.y);
	} // just fun

	CEnemy::Move();
}