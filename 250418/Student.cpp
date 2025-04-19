#include "pch.h"
#include "Student.h"
#include "Define.h"

void Student::Release()
{
	SAFE_DELETE(m_pPrev);
	SAFE_DELETE(m_pNext);
}

Student::Student(std::string _sName, float _fScore)
{
	m_sName = _sName;
	m_fScore = _fScore;
}

Student::~Student()
{
	Release();
}
