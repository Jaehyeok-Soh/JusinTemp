#pragma once
#include "Student.h"

class StudentList
{
public:
	void Add(std::string _sName, float _fScore);
	void Search(std::string _sSearchContext, float _fScore = NULL);
	void Print();
	void PrintReverse();

private:
	Student* m_pHead = nullptr;
	Student* m_pTail = nullptr;
};