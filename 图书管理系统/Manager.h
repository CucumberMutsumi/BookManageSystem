#pragma once
#include<iostream>



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

	void SetData(int ID, int PasWrd);

	~Manager();
};