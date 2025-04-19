#include "pch.h"
#include "StudentList.h"
#include "Student.h"

void StudentList::Add(std::string _sName, float _fScore)
{
	Student* newStud = new Student(_sName, _fScore);

	if (pHead == nullptr)
	{
		pHead = newStud;
		pTail = newStud;
		return;
	}

	pTail->pNext = newStud;
	newStud->pPrev = pTail;
	pTail = newStud;
}

void StudentList::Search(std::string sSearchContext, float fScore)
{
	Student* current = pHead;
	while (current != nullptr)
	{
		if (current->sName == sSearchContext || current->fScore == fScore)
		{
			cout << "===============\n";
			cout << current->sName << '\t' << current->fScore << '\n';
		}
		current = current->pNext;
	}
}

void StudentList::Print()
{
	Student* current = pHead;
	while (current != nullptr)
	{
		cout << "===============\n";
		cout << current->sName << '\t' << current->fScore << '\n';

		current = current->pNext;
	}
}

void StudentList::PrintReverse()
{
	Student* current = pTail;
	while (current != nullptr)
	{
		cout << "===============\n";
		cout << current->sName << '\t' << current->fScore << '\n';

		current = current->pPrev;
	}
}