#pragma once
#include "RGEngine.h"

#define GM CGameManager::GetInstance()

using namespace RGEngine;

class CGameManager
{
public:
	bool isPause;
	static float g;

public:
	CGameManager();
	~CGameManager() {}

	static CGameManager* GetInstance()
	{
		static CGameManager GameManagerIns;
		return &GameManagerIns;
	}

	void Initiate();
};

