#include<iostream>
#include"ͼ�������.h"
using namespace std;

int main()
{
	BookManage BM;
	BM.ShowMenu_IdentityVerification();
	int Identity;
	while (true)
	{
		cin >> Identity;
		if (cin.fail() || Identity < 0 || Identity>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��������������������룺 ";
		}
		else
		{
			break;
		}
	}

	system("pause");
	return 0;
	
}