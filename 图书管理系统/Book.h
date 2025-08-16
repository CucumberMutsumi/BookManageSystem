#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
	int m_id;
	string m_bookname;
	int m_total;
	double m_price;
public:
	Book();

	void SetBookData(int id, string bookname, int count,double price);

	int GetBookId();

	string GetBookName();

	int GetTotal();

	double GetPrice();

	~Book();
};