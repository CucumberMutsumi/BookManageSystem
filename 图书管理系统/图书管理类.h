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

	int IdentityVerification();//身份选择
	
	bool Login(int identity);//登录

	bool Is_ManagerExist(int id, int psw);//验证管理员是否存在

	bool Is_TouristExist(int id, int psw);//验证游客是否存在

	void ShowMenu(int Identity);//根据身份显示菜单

	void Save_Manager();//保存信息

	void LoadManager();//加载管理员

	map<int, Manager> m_Manager;//存储管理员

	map<int, Tourist>m_Tourist;//存储游客

	map<int, Book>m_Books;//存储书籍

	void CreatNewManager();//添加新的管理员

	bool Is_IDExist(int ID);//检查管理员是否有重合的ID

	bool Is_PassWordExist(int password); //检查管理员是否有重合的密码

	bool Is_BookIdExist(int id);//检查书籍是否有重合的ID

	bool Is_BookNameExist(string name); //检查书籍是否有重合的书名

	void AddNewBook();//添加新的书籍信息

	void SaveBook();//保存书籍信息

	void LoadBooks();//书籍信息读入程序

	bool Is_TouristIdExist(int id);//检查是否有重合的游客ID

	void AddNewTourist();//添加新的游客

	void SaveTourist();//存储游客信息

	void LoadTourist();//旅客信息读入程序

	void ShowManager();//输出管理员

	void ShowTourist();//输出游客

	void ShowBooks();//输出书籍信息

	~BookManage();
};