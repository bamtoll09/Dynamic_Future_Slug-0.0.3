#pragma once
#include "RGEngine.h"

#define GM CGameManager::GetInstance()

using namespace RGEngine;

class CGameManager
{
public:
	bool isPause;

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

