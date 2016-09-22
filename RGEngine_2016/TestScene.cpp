#include "TestScene.h"
#include "GameManager.h"
#include "Mover.h"
#include "Bullet.h"

TestScene::TestScene(void)
{
	PushBackGameObject(background = new Sprite("resources/Background/Background.png"));
	PushBackGameObject(boss = new CBoss1());
	boss->position.SetVector(1000, 500);
	PushBackGameObject(player = new CPlayer());
	player->position.SetVector(0, RGGraphic->GetScreenHeight() - player->sprite->GetTexture()->GetHeight());
	//PushBackGameObject(new CBullet(500, 500, 0.5, 0, 0.02, 0));
}
TestScene::~TestScene()
{
}

void TestScene::OnUpdate(void)
{
	if (!GM->isPause)
	{
		auto gameObjects = GetGameObjects();

		for (int i = 0; i < GetGameObjectSize(); ++i)
		{
			CMover *gameObject = dynamic_cast<CMover*>(gameObjects[i]);
			if (gameObject)
				gameObject->Move();
		}
	}
}
