#include "pch.h"

int main()
{
	StudentList list;
	string sName;
	float fScore;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "번째 학생 이름을 입력하세요 : ";
		cin >> sName;
		cout << i + 1 << "번째 학생 성적을 입력하세요 : ";
		cin >> fScore;

		list.Add(sName, fScore);
	}

	int input(0);
	while (input != 4)
	{
		system("cls");

		cout << "1. 추가 2. 출력 3. 검색 4. 종료 : ";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "학생 이름을 입력하세요 : ";
			cin >> sName;
			cout << "학생 성적을 입력하세요 : ";
			cin >> fScore;
			list.Add(sName, fScore);
			break;
		case 2:
			list.Print();
			break;
		case 3:
			cout << "검색 할 학생 이름을 입력하세요 : ";
			cin >> sName;
			cout << "검색 할 학생 성적을 입력하세요 : ";
			cin >> fScore;
			list.Search(sName, fScore);
			break;
		default:
			cout << "잘 못 입력하셨습니다. 머쓱하니 거꾸로 출력\n";
			list.PrintReverse();
			break;
		}

		system("pause");
	}
}