#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book;

class Tourist
{
private:
	int m_id;
	int m_psw;
public:
	vector<string> books;

	Tourist();

	void SetData(int id, int psw);

	int Getid();

	int Getpsw();

	~Tourist();
};
