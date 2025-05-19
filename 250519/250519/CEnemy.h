#pragma once

class CEnemy : public CObj
{
public:
	CEnemy();
	virtual ~CEnemy();

public:
	void Initialize() override;
	int Update() override;
	void Render(HDC hDc) override;
	void Release() override;

private:
	float m_fHeadX = 10.f;
	float m_fHeadY = 0.f;

	void Action(HDC hDc);
	void MoveRandom();
};