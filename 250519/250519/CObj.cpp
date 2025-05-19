#include "pch.h"

#include <algorithm>

#include "CObj.h"

CObj::CObj()
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY / 2.f));
}

bool CObj::IsColliding(CObj* _pOther)
{
	return !(GetLeft() > _pOther->GetRight() ||
		GetRight() < _pOther->GetLeft() ||
		GetTop() > _pOther->GetBottom() ||
		GetBottom() < _pOther->GetTop());
}

bool CObj::IsColliding(CObj* _pA, CObj* _pB)
{
	return !(_pA->GetLeft() > _pB->GetRight() ||
		_pA->GetRight() < _pB->GetLeft() ||
		_pA->GetTop() > _pB->GetBottom() ||
		_pA->GetBottom() < _pB->GetTop());
}

void CObj::ResolveCollision(CObj* _pOther)
{
	if (GetLeft() < _pOther->GetRight())
	{
		MoveRight(5.f);
		_pOther->MoveLeft(5.f);
	}

	if (GetRight() > _pOther->GetLeft())
	{
		MoveLeft(5.f);
		_pOther->MoveRight(5.f);
	}

	if (GetTop() < _pOther->GetBottom())
	{
		MoveBottom(5.f);
		_pOther->MoveTop(5.f);
	}

	if (GetBottom() > _pOther->GetTop())
	{
		MoveTop(5.f);
		_pOther->MoveBottom(5.f);
	}

	float overlapX = min(GetRight(), _pOther->GetRight()) - max(GetLeft(), _pOther->GetLeft());
	float overlapY = min(GetBottom(), _pOther->GetBottom()) - max(GetTop(), _pOther->GetTop());

	if (overlapX <= 0.f || overlapY <= 0.f)
		return;

	if (overlapX < overlapY)
	{
		if (m_tInfo.fX < _pOther->m_tInfo.fX)
			MoveLeft(overlapX / 2.f);
		else
			MoveRight(overlapX / 2.f);
	}
	else
	{
		if (m_tInfo.fY < _pOther->m_tInfo.fY)
			MoveTop(overlapY / 2.f);
		else
			MoveBottom(overlapY / 2.f);
	}
}

float CObj::GetLeft() const
{
	return m_tInfo.fX - m_tInfo.fCX / 2.f;
}

float CObj::GetRight() const
{
	return m_tInfo.fX + m_tInfo.fCX / 2.f;;
}

float CObj::GetTop() const
{
	return m_tInfo.fY - m_tInfo.fCY / 2.f;
}

float CObj::GetBottom() const
{
	return m_tInfo.fY + m_tInfo.fCY / 2.f;;
}

void CObj::MoveLeft(float _fValue)
{
	m_tInfo.fX -= _fValue;
}

void CObj::MoveRight(float _fValue)
{
	m_tInfo.fX += _fValue;
}

void CObj::MoveTop(float _fValue)
{
	m_tInfo.fY -= _fValue;
}

void CObj::MoveBottom(float _fValue)
{
	m_tInfo.fY += _fValue;
}
