#include "pch.h"
#include "Student.h"

Student::Student(istream &cin)
{
	cin >> m_iKor;
	cin >> m_iEng;
	cin >> m_iMath;
	calcTotal();
	calcAve();
}

int Student::getKor()
{
	return m_iKor;
}

int Student::getEng()
{
	return m_iEng;
}

int Student::getMath()
{
	return m_iMath;
}

int Student::getTotal()
{
	return m_iTotal;
}

float Student::getAve()
{
	return m_fAve;
}

void Student::calcTotal()
{
	m_iTotal = m_iKor + m_iEng + m_iMath;
}

void Student::calcAve()
{
	if (m_iTotal <= 0)
	{
		m_fAve = 0.l;
	}
	else
	{
		m_fAve = m_iTotal / 3.f;
	}
}
