#include"ͼ�������.h"


BookManage::BookManage()
{

}

void BookManage::ShowMenu_IdentityVerification()
{
	cout << "-------------------------------------" << endl;
	cout << "----------������������-------------" << endl;
	cout << "----------1.ͼ�����Ա---------------" << endl;
	cout << "----------2.�ο�---------------------" << endl;
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