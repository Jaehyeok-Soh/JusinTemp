#include "pch.h"
#include <vector>

int main()
{
	int iInput(0);
	vector<Student> list;
	vector<Student>::iterator itr;
	while (iInput == 9)
	{
		cout << "현재 입력한 학생 수 : " << list.size() << endl;
		cout << "메모리 : " << list.capacity() << endl;
		cout << "1. 학생추가 2. 학생삭제 3. 출력" << endl;
		switch (iInput)
		{
		case 1:
			cout << "국영수 점수를 순서대로 입력하세요" << endl;
			list.push_back(Student(cin));
			break;
		case 2:
			cout << "삭제할 학생 순번 입력 : ";
			cin >> iInput;
			itr = list.begin();
			for (auto i = 0; i < list.size(); i++)
			{
				if (i == iInput - 1)
				{
					itr = list.erase(itr);
					break;
				}
				itr++;
			}
			break;
		case 3:
			for (auto a : list)
			{
				cout << "국어 : " << a.getKor() << " 영어 : " << a.getEng() << " 수학 : " << a.getMath() << endl;
			}
			break;
		default:
			break;
		}
	}



}