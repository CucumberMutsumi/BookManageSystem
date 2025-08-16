#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include"Manager.h"
#include"Tourist.h"
#include"Book.h"

using namespace	std;

class BookManage
{
public:
	BookManage();

	int IdentityVerification();//���ѡ��
	
	bool Login(int identity);//��¼

	bool Is_ManagerExist(int id, int psw);//��֤����Ա�Ƿ����

	bool Is_TouristExist(int id, int psw);//��֤�ο��Ƿ����

	void ShowMenu(int Identity);//���������ʾ�˵�

	void Save_Manager();//������Ϣ

	void LoadManager();//���ع���Ա

	map<int, Manager> m_Manager;//�洢����Ա

	map<int, Tourist>m_Tourist;//�洢�ο�

	map<int, Book>m_Books;//�洢�鼮

	void CreatNewManager();//����µĹ���Ա

	bool Is_IDExist(int ID);//������Ա�Ƿ����غϵ�ID

	bool Is_PassWordExist(int password); //������Ա�Ƿ����غϵ�����

	bool Is_BookIdExist(int id);//����鼮�Ƿ����غϵ�ID

	bool Is_BookNameExist(string name); //����鼮�Ƿ����غϵ�����

	void AddNewBook();//����µ��鼮��Ϣ

	void SaveBook();//�����鼮��Ϣ

	void LoadBooks();//�鼮��Ϣ�������

	bool Is_TouristIdExist(int id);//����Ƿ����غϵ��ο�ID

	void AddNewTourist();//����µ��ο�

	void SaveTourist();//�洢�ο���Ϣ

	void LoadTourist();//�ÿ���Ϣ�������

	void ShowManager();//�������Ա

	void ShowTourist();//����ο�

	void ShowBooks();//����鼮��Ϣ

	~BookManage();
};