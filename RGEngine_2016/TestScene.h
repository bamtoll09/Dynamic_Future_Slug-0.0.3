#pragma once
#include "RGEngine.h"

#include "Sound.h"
#include "Sprite.h"
#include "Text.h"
#include "Boss1.h"
#include "Player.h"

using namespace RGEngine;

class TestScene : public RGEngine::Scene
{
private:
	Sprite *background;
	Text *text;
	CBoss1 *boss;
	CPlayer *player;

public:
	TestScene(void);
	~TestScene() override;

public:
	void OnUpdate(void) override;

};

