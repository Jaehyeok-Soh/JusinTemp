#pragma once
class Student
{
public:
	Student(int _iKor, int _iEng, int _iMath) 
		: m_iKor(_iKor), m_iEng(_iEng), m_iMath(_iMath), m_iTotal(m_iKor + m_iEng + m_iMath), m_fAve(m_iTotal / 3.f) {}
	Student(istream &cin);

	int getKor();
	int getEng();
	int getMath();
	int getTotal();
	float getAve();

private:
	int m_iKor, m_iEng, m_iMath, m_iTotal;
	float m_fAve;

	void calcTotal();
	void calcAve();
};

