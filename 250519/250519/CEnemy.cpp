#include "pch.h"

#include <ctime>

#include "CEnemy.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
	Release();
}

void CEnemy::Initialize()
{
	srand(static_cast<unsigned int>(time(0)));
	m_tInfo = { (WINCX >> 1) + 100.f, (WINCY >> 1) + 100.f, 100.f, 100.f };
}

int CEnemy::Update()
{
	MoveRandom();
	__super::Update_Rect();
	return 0;
}

void CEnemy::Render(HDC hDc)
{
	Action(hDc);
}

void CEnemy::Release()
{
}

void CEnemy::Action(HDC hDc)
{
	Rectangle(hDc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CEnemy::MoveRandom()
{
	m_tInfo.fX += rand() % 20 - 10;
	m_tInfo.fY += rand() % 20 - 10;

	if (GetTop() <= 0)
	{
		MoveBottom();
	}

	if (GetBottom() >= WINCY)
	{
		MoveTop();
	}

	if (GetLeft() <= 0)
	{
		MoveRight();
	}

	if (GetRight() >= WINCX)
	{
		MoveLeft();
	}
}
