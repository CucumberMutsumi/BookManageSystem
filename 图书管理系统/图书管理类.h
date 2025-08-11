#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include"Manager.h"

using namespace	std;

class BookManage
{
public:
	BookManage();

	void ShowMenu_IdentityVerification();

	void IdentityVerification(int Identyty);
	
	void Save_Manager();

	map<int, Manager> m_Manager;

	~BookManage();
};