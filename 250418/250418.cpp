#include "pch.h"

int main()
{
	StudentList list;
	string sName;
	float fScore;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "��° �л� �̸��� �Է��ϼ��� : ";
		cin >> sName;
		cout << i + 1 << "��° �л� ������ �Է��ϼ��� : ";
		cin >> fScore;

		list.Add(sName, fScore);
	}

	int input(0);
	while (input != 4)
	{
		system("cls");

		cout << "1. �߰� 2. ��� 3. �˻� 4. ���� : ";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "�л� �̸��� �Է��ϼ��� : ";
			cin >> sName;
			cout << "�л� ������ �Է��ϼ��� : ";
			cin >> fScore;
			list.Add(sName, fScore);
			break;
		case 2:
			list.Print();
			break;
		case 3:
			cout << "�˻� �� �л� �̸��� �Է��ϼ��� : ";
			cin >> sName;
			cout << "�˻� �� �л� ������ �Է��ϼ��� : ";
			cin >> fScore;
			list.Search(sName, fScore);
			break;
		default:
			cout << "�� �� �Է��ϼ̽��ϴ�. �Ӿ��ϴ� �Ųٷ� ���\n";
			list.PrintReverse();
			break;
		}

		system("pause");
	}
}