#pragma once
#include<iostream>

using namespace std;

class BookManage;

class Manager
{
	friend  class BookManage;
private:
	int Id;
	int PassWord;
public:
	Manager();

	int GetID();

	int GetPassWord();

	void CreatManager();

	~Manager();
};