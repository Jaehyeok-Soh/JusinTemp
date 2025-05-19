#pragma once
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void Initialize() override;
	void Initialize(INFO _tInfo, float _x, float _y);
	int Update() override;
	void Render(HDC hDc) override;
	void Release() override;

private:
	float m_fSpeedX;
	float m_fSpeedY;
};

