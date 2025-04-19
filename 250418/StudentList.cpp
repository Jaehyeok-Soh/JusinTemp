#include "pch.h"
#include "StudentList.h"
#include "Student.h"

void StudentList::Add(std::string _sName, float _fScore)
{
	Student* newStud = new Student(_sName, _fScore);

	if (m_pHead == nullptr)
	{
		m_pHead = newStud;
		m_pTail = newStud;
		return;
	}

	m_pTail->m_pNext = newStud;
	newStud->m_pPrev = m_pTail;
	m_pTail = newStud;
}

void StudentList::Search(std::string sSearchContext, float fScore)
{
	Student* current = m_pHead;
	while (current != nullptr)
	{
		if (current->m_sName == sSearchContext || current->m_fScore == fScore)
		{
			cout << "===============\n";
			cout << current->m_sName << '\t' << current->m_fScore << '\n';
		}
		current = current->m_pNext;
	}
}

void StudentList::Print()
{
	Student* current = m_pHead;
	while (current != nullptr)
	{
		cout << "===============\n";
		cout << current->m_sName << '\t' << current->m_fScore << '\n';

		current = current->m_pNext;
	}
}

void StudentList::PrintReverse()
{
	Student* current = m_pTail;
	while (current != nullptr)
	{
		cout << "===============\n";
		cout << current->m_sName << '\t' << current->m_fScore << '\n';

		current = current->m_pPrev;
	}
}