#include"图书管理类.h"


BookManage::BookManage()
{

}

void BookManage::ShowMenu_IdentityVerification()
{
	cout << "-------------------------------------" << endl;
	cout << "----------请输入你的身份-------------" << endl;
	cout << "----------1.图书管理员---------------" << endl;
	cout << "----------2.游客---------------------" << endl;
	cout << "-------------------------------------" << endl;
}

void BookManage::IdentityVerification(int Identyty)
{

}

void BookManage::Save_Manager()
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::out || ios::app);

}

BookManage::~BookManage()
{

}