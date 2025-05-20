#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX >> 1, WINCY >> 1, 100.f, 100.f };
}

int CPlayer::Update()
{
	Key_Input();
	__super::Update_Rect();
	return 0;
}

void CPlayer::Render(HDC hDc)
{
	Action(hDc);
	BulletAction(hDc);
}

void CPlayer::Release()
{
	for (auto it = m_BulletList.begin(); it != m_BulletList.end();)
	{
		delete *it;
		*it = nullptr;
		it = m_BulletList.erase(it);
	}
}

list<CBullet*>& CPlayer::GetBulletList()
{
	return m_BulletList;
}

list<CBullet*>::iterator CPlayer::ReleaseBullet(list<CBullet*>::iterator iter)
{
	auto temp = *iter;
	iter = m_BulletList.erase(iter);
	safe_delete(temp);
	return iter;
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		CBullet* bullet = new CBullet();
		bullet->Initialize(m_tInfo, m_fHeadX, m_fHeadY);
		m_BulletList.push_back(bullet);
	}
	else if (GetAsyncKeyState('W'))
	{
		MoveTop();

		if (GetTop() <= 0)
		{
			MoveBottom();
		}

		m_fHeadX = 0.f;
		m_fHeadY = -10.f;
	}
	else if (GetAsyncKeyState('S'))
	{
		MoveBottom();

		if (GetBottom() >= WINCY)
		{
			MoveTop();
		}

		m_fHeadX = 0.f;
		m_fHeadY = 10.f;
	}
	else if (GetAsyncKeyState('A'))
	{
		MoveLeft();

		if (GetLeft() <= 0)
		{
			MoveRight();
		}

		m_fHeadX = -10.f;
		m_fHeadY = 0.f;
	}
	else if (GetAsyncKeyState('D'))
	{
		MoveRight();

		if (GetRight() >= WINCX)
		{
			MoveLeft();
		}

		m_fHeadX = 10.f;
		m_fHeadY = 0.f;
	}
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
}

void CPlayer::Action(HDC hDc)
{
	Rectangle(hDc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::BulletAction(HDC hDc)
{
	for (auto bullet : m_BulletList)
	{
		bullet->Render(hDc);
		bullet->Update();
	}

	for (auto bullet = m_BulletList.begin(); bullet != m_BulletList.end();)
	{
		(*bullet)->Render(hDc);
		if ((*bullet)->Update() == false)
		{
			safe_delete(*bullet);
			bullet = m_BulletList.erase(bullet);
		}
		else
		{
			bullet++;
		}
	}
}

