#include "pch.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo = { WINCX >> 1, WINCY >> 1, 10.f, 10.f };
}

void CBullet::Initialize(INFO _tInfo, float _x, float _y)
{
	m_tInfo = {_tInfo.fX, _tInfo.fY, 10.f, 10.f};

	if (_x > 0)
	{
		m_tInfo.fX = _tInfo.fX + _tInfo.fCX / 2.f;
		m_tInfo.fY = _tInfo.fY;
	}
	else if (_x < 0)
	{
		m_tInfo.fX = _tInfo.fX - _tInfo.fCX / 2.f;
		m_tInfo.fY = _tInfo.fY;
	}
	else if (_y > 0)
	{
		m_tInfo.fX = _tInfo.fX;
		m_tInfo.fY = _tInfo.fY + _tInfo.fCY / 2.f;
	}
	else if (_y < 0)
	{
		m_tInfo.fX = _tInfo.fX;
		m_tInfo.fY = _tInfo.fY - _tInfo.fCY / 2.f;
	}

	m_fSpeedX = _x;
	m_fSpeedY = _y;
}

int CBullet::Update()
{
	int bRet = 1;

	m_tInfo.fX += m_fSpeedX;
	m_tInfo.fY += m_fSpeedY;
	__super::Update_Rect();

	if (m_tInfo.fX - m_tInfo.fCX / 2.f <= 0 || m_tInfo.fX + m_tInfo.fCX / 2.f >= WINCX)
	{
		bRet = 0;
	}
	else if (m_tInfo.fY - m_tInfo.fCY / 2.f <= 0 || m_tInfo.fY + m_tInfo.fCY / 2.f >= WINCY)
	{
		bRet = 0;
	}

	return bRet;
}

void CBullet::Render(HDC hDc)
{
	Ellipse(hDc, m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{
}