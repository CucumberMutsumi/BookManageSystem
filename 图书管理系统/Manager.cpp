#include"Manager.h"

Manager::Manager()
{
	this->Id = 0;
	this->PassWord = 0;
}

Manager::~Manager()
{

}

int Manager::GetID()
{
	return this->Id;
}

int Manager::GetPassWord()
{
	return this->PassWord;
}

void Manager::SetData(int ID, int PasWrd)
{
	Id = ID;
	PassWord = PasWrd;
}