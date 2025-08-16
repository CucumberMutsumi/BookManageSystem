#include"Book.h"

Book::Book()
{
	m_id = 0;
	m_bookname = " ";
	m_total = 0;
	m_price = 0;
}

void Book::SetBookData(int id, string bookname, int count, double price)
{
	m_id = id;
	m_bookname = bookname;
	m_total = count;
	m_price = price;
}

int Book::GetBookId()
{
	return m_id;
}

string Book::GetBookName()
{
	return m_bookname;
}

int Book::GetTotal()
{
	return m_total;
}

double Book::GetPrice()
{
	return m_price;
}

Book::~Book()
{

}