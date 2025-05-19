#include "pch.h"
#include "CMainGame.h"
#include <string>

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	delay = 0;
	m_DC = GetDC(g_hWnd);

	m_pPlayer = new CPlayer();
	m_pPlayer->Initialize();

	m_pEnemy = new CEnemy();
	m_pEnemy->Initialize();
}

void CMainGame::Update()
{
	m_pPlayer->Update();

	if (m_pEnemy)
	{
		m_pEnemy->Update();

		if (m_pPlayer->IsColliding(m_pEnemy))
		{
			m_pPlayer->ResolveCollision(m_pEnemy);
		}

		auto& bulletList = dynamic_cast<CPlayer*>(m_pPlayer)->GetBulletList();
		if (bulletList.empty() == false)
		{
			for (auto bullet = bulletList.begin(); bullet != bulletList.end();)
			{
				if (m_pPlayer->IsColliding((*bullet), m_pEnemy))
				{
					safe_delete(m_pEnemy);
					bullet = dynamic_cast<CPlayer*>(m_pPlayer)->ReleaseBullet(bullet);
					break;
				}
				else
				{
					bullet++;
				}
			}
		}
	}
	else
	{
		delay++;
		if (delay == 100)
		{
			m_pEnemy = new CEnemy();
			m_pEnemy->Initialize();
			delay = 0;
		}
	}
}

void CMainGame::Render()
{
	m_pPlayer->Render(m_DC);
	if (m_pEnemy)
	{
		m_pEnemy->Render(m_DC);
	}
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_DC);
	safe_delete(m_pPlayer);
	safe_delete(m_pEnemy);
}

