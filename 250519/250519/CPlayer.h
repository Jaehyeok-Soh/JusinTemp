#pragma once
#include "CObj.h"
#include "CBullet.h"

class CBullet;

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Initialize() override;
	int Update() override;
	void Render(HDC hDc) override;
	void Release() override;

public:
	list<CBullet*>& GetBulletList();
	list<CBullet*>::iterator ReleaseBullet(list<CBullet*>::iterator iter);

private:
	list<CBullet*> m_BulletList;
	float m_fHeadX = 10.f;
	float m_fHeadY = 0.f;

	void Key_Input();
	void Action(HDC hDc);
	void BulletAction(HDC hDc);
};

