#include "GameManager.h"

float CGameManager::g{ NULL };

CGameManager::CGameManager() : isPause(false) { g = 9.81f; }
void CGameManager::Initiate()
{
	isPause = false;
}
