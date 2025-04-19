#pragma once

class Student
{
public:
	Student* m_pPrev = nullptr;
	Student* m_pNext = nullptr;
	std::string m_sName;
	float m_fScore;

	void Release();

public :
	Student(std::string _sName, float _fScore);
	~Student();
};