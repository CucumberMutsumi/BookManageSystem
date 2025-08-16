#include"Tourist.h"

Tourist::Tourist()
{
	m_id = 0;
	m_psw = 0;
}

void Tourist::SetData(int id, int psw)
{
	m_id = id;
	m_psw = psw;
}

int Tourist::Getid()
{
	return m_id;
}

int Tourist::Getpsw()
{
	return m_psw;
}

Tourist::~Tourist()
{

}