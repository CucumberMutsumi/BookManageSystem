#include<iostream>
#include<map>
#include"ͼ�������.h"
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
					cout << "�����������������룺 ";
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
					BM.ModifyBookInfo();
					break;
				case 4:
					BM.ShowBookInfo();
					break;
				case 5:
					BM.DeleteBook();
					break;
				case 0:
					BM.ExitSystem();
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
					BM.ExitSystem();
					break;
				default:
					system("pause");
					system("cls");
					break;
				}
			}
		}
	}

	
	system("pause");
	return 0;
	
}