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
					BM.BorrowBook();
					break;
				case 2:
					break;
				case 3:
					BM.ShowBorrowBook();
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
/*
�ܽ�
1.ѧϰ��forѭ��������map��������pair<>�Ĳ������������Ϊ����ֵ��ѧϰ��
2.��goto����������ص�ĳ���ڵ㣨ҳ�棩��goto�����Կ纯��
3.ѧϰ����string��substr()��()������ֽ�������.txt�ļ��������UTF-8��ÿ������ռ3���ֽڣ�Ӣ��ÿ��һ���ֽ�
  �����ANSI��GBK������ģʽ�£�ÿ������ռ2���ֽڣ�Ӣ��ÿ��һ���ֽڣ���ʱ�޷���(.txt)�ļ���ȡ����
  ����Ϊ���� Windows �µı�����Ĭ���� ANSI��GBK������ �洢�ַ�������
  .txt �� UTF-8 ���� ʱ��        �ļ��е��ֽ������� UTF-8 ��ʽ�������е��ֽ������� ANSI��GBK����ʽ
  ���ߵ��ֽ�������ȫ��ͬ��find() ��Ȼƥ��ʧ�ܣ����� string::npos�����޷����������֧�������޷�¼����Ϣ��
4.��ݼ�����ͷ�ļ���ʹ��alt+enter+d���Կ�����.cpp�ļ��ﴴ����������
*/