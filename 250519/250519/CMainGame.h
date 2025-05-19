#pragma once

#include "Define.h"
#include "CPlayer.h"
#include "CEnemy.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Release();
	void Render();

private:
	HDC m_DC;

	CObj* m_pPlayer;
	CObj* m_pEnemy;

	int delay;
};

