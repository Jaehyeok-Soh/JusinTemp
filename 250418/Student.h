#pragma once

class Student
{
public:
	Student(std::string _sName, float _fScore);
	Student* pPrev = nullptr;
	Student* pNext = nullptr;
	std::string sName;
	float fScore;
};