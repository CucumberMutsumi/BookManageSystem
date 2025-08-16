#include<iostream>
#include<map>
#include"图书管理类.h"
using namespace std;

int main()
{
	BookManage BM;
	
	/*BM.ShowManager();
	BM.ShowTourist();*/
	int Identity;
	Identity =BM.IdentityVerification();
	int chioce;
	if (BM.Login(Identity))
	{
		while (true)
		{
			BM.ShowMenu(Identity);
			while (true)
			{
				cin >> chioce;
				if (cin.fail() || chioce < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入有误！请重新输入： ";
				}
				else
				{
					break;
				}
			}
			if (Identity == 1)
			{
				switch (chioce)
				{
				case 1:
					BM.AddNewBook();
					break;
				case 2:
					BM.CreatNewManager();
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 0:
					break;
				default:
					system("pause");
					system("cls");
					break;
				}
			}
			else
			{
				switch (chioce)
				{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 0:
					break;
				default:
					break;
				}
			}
		}
	}

	
	system("pause");
	return 0;
	
}