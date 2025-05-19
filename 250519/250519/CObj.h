#pragma once
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hDc)PURE;
	virtual void Release()PURE;
	
	bool IsColliding(CObj* _pOther);
	bool IsColliding(CObj* _pA, CObj* _pB);
	void ResolveCollision(CObj* _pOther);

	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;

	void MoveLeft(float _fValue = 10);
	void MoveRight(float _fValue = 10);
	void MoveTop(float _fValue = 10);
	void MoveBottom(float _fValue = 10);

protected:
	void Update_Rect();

protected:
	INFO m_tInfo;
	RECT m_tRect;
};