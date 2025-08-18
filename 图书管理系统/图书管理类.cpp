#include"ͼ�������.h"


BookManage::BookManage()
{
	this->LoadBooks();
	this->LoadManager();
	this->LoadTourist();
}

//���ѡ��
int BookManage::IdentityVerification()
{
	cout << "-------------------------------------" << endl;
	cout << "----------������������-------------" << endl;
	cout << "----------1.ͼ�����Ա---------------" << endl;
	cout << "----------2.�ο�---------------------" << endl;
	cout << "-------------------------------------" << endl;
	int Identity;
	while (true)
	{
		cin >> Identity;
		if (cin.fail() || Identity < 0 || Identity>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��������������������룺 ";
		}
		else
		{
			break;
		}
	}
	return Identity;
}

//��֤�ο��Ƿ����
bool BookManage::Is_TouristExist(int id, int psw)
{
	for (auto& pair : this->m_Tourist)
	{
		auto& T = pair.second;
		if (pair.first == id && T.Getpsw()==psw)
		{
			return true;
		}
	}
	return false;
}

//��֤����Ա�Ƿ����
bool BookManage::Is_ManagerExist(int id, int psw)
{
	cout << "��ǰ����Ա�б�" << endl;
	for (auto& pair : this->m_Manager) {
		cout << "ID: " << pair.first << ", ����: " << pair.second.GetPassWord() << endl;
	}

	for (auto& pair : this->m_Manager)
	{
		auto& M = pair.second;
		if (pair.first == id && M.GetPassWord() == psw)
		{
			return true;
		}
	}
	return false;
}

//��¼(��Ҫѧϰ״̬ջ)
bool BookManage::Login(int identity)
{
	while (true)
	{
		statr:
		if (identity == 1)//��ʾ�û�����id������
		{
			cout << "������id:  ";
			int id;
			while (true)
			{
				cin >> id;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "������������������:  ";
				}
				else
				{
					break;
				}
			}
			cout << "����������:  ";
			int psw;
			while (true)
			{
				cin >> psw;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "������������������:  ";
				}
				else
				{
					break;
				}
			}
			
			if (this->Is_ManagerExist(id, psw))
			{
				return true;
			}
			else
			{
				cout << "����ԱID���������" << endl;
				cout << "��ѡ�������1-���³��� 2-������һ��" << endl;
				int choice;
				cin >> choice;
				if (choice != 1) // ����û���ѡ�����³��ԣ��򷵻ص�¼ʧ��
				{
					return false;
				}
			}
			
		}
		else
		{
			//���������ѯ���Ƿ������û�
			cout << "-----------------------------------" << endl;
			cout << "------------1.��¼-----------------" << endl;
			cout << "------------2.�������˺�-----------" << endl;
			cout << "-----------------------------------" << endl;
			int choice = 0;
			while (true)
			{
				cin >> choice;
				if (cin.fail() || choice < 0 || choice>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "��������!����������:";
				}
				else
				{
					break;
				}
			}
		
			if(choice==2)
			 {
				this->AddNewTourist();
				goto statr;
			 }
			else
			{
				cout << "������id:  ";
				int id;
				while (true)
				{
					cin >> id;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "������������������:  ";
					}
					else
					{
						break;
					}
				}
				cout << "����������:  ";
				int psw;
				while (true)
				{
					cin >> psw;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "������������������:  ";
					}
					else
					{
						break;
					}
				}
				if (this->Is_TouristExist(id, psw))
				{
					this->RecoreLoginT=this->m_Tourist[id];
					return true;
				}
				else
				{
					cout << "�ο�ID���������" << endl;
					cout << "��ѡ�������1-���³��� 2-������һ��" << endl;
					int choice;
					cin >> choice;
					if (choice != 1) // ����û���ѡ�����³��ԣ��򷵻ص�¼ʧ��
					{
						return false;
					}
				}
			}
		}
	}
	
}

//���������ʾ�˵�
void BookManage::ShowMenu(int Identity)
{
	if (Identity == 1)
	{
		cout << "---------- <    ��¼�ɹ�     > ----------" << endl;
		cout << "--------------1.����鼮-----------------" << endl;
		cout << "--------------2.����µĹ���Ա-----------" << endl;
		cout << "--------------3.�޸��鼮��Ϣ-------------" << endl;
		cout << "--------------4.��ѯ�鼮��Ϣ--------------" << endl;
		cout << "--------------5.ɾ���鼮-----------------" << endl;
		cout << "--------------0.�˳�ϵͳ-----------------" << endl;
		cout << "-----------------------------------------" << endl;
	}
	else
	{
		cout << "---------- <    ��¼�ɹ�     > ----------" << endl;
		cout << "--------------1.����---------------------" << endl;
		cout << "--------------2.����---------------------" << endl;
		cout << "--------------3.�鿴�ѽ��鼮-------------" << endl;
		cout << "--------------0.�˳�ϵͳ-----------------" << endl;
		cout << "-----------------------------------------" << endl;
	}
}

//�������Ա��Ϣ
void BookManage::Save_Manager()
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "�ļ��޷��򿪣��洢����ʧ�ܣ�" << endl;
		return;
	}
	
	for (auto& pair : this->m_Manager)
	{
		auto& M = pair.second;
		ofs << "����ԱID:" << M.GetID() << endl;
		ofs << "����:" << M.GetPassWord() << endl;
	}
	ofs.close();
}

//���ع���Ա
void BookManage::LoadManager()
{
	//ifstream ifs;
	//ifs.open("Manager.txt", ios::in);
	//if (!ifs.is_open())
	//{
	//	cout << "���ļ�ʧ�ܣ���ȷ��Manager.txt����" << endl;
	//	return;
	//}
	//// �������
	//m_Manager.clear();
	//// ��ʱ����
	//int Id = 0;
	//int PassWord = 0;
	//string line;
	//int state = 0;  // ״̬��ǣ�0-δ��ʼ��1-�ѻ�ȡID��2-�ѻ�ȡID������
	//int lineNum = 0; // �кţ����ڵ���
	//// ���ж�ȡ�ļ�
	//while (getline(ifs, line))
	//{
	//	lineNum++;
	//	cout << "����ѭ������" << lineNum << "�������ݣ���" << line << "��" << endl;
	//	// ��������
	//	if (line.empty())
	//	{
	//		cout << "�����ǿ��У�����" << endl;
	//		continue;
	//	}
	//	// ����ƥ�����ԱID
	//	size_t idPos = line.find("����ԱID:");
	//	if (idPos != string::npos)
	//	{
	//		cout << "ƥ�䵽����ԱID�ؼ���" << endl;
	//		try
	//		{
	//			// ��ȡID��"����ԱID:"ռ9�ֽڣ�
	//			string idStr = line.substr(9);
	//			cout << "��ȡ��ID�ַ�������" << idStr << "��" << endl;
	//			// ����Ƿ�Ϊ��
	//			if (idStr.empty())
	//			{
	//				throw invalid_argument("ID�ַ���Ϊ��");
	//			}
	//			// ת��Ϊ����
	//			Id = stoi(idStr);
	//			state++; // ״̬��Ϊ1���ѻ�ȡID��
	//			cout << "����ID��" << Id << "����ǰstate��" << state << endl;
	//		}
	//		catch (const invalid_argument& e)
	//		{
	//			cout << "��" << lineNum << " IDת��ʧ�ܣ�" << e.what() << endl;
	//			state = 0; // ����״̬
	//			Id = 0;
	//		}
	//		continue; // ������ID��������һ��
	//	}
	//	// ����ƥ�����루ֻ��IDδƥ��ʱ�Ż�ִ�����
	//	size_t pswPos = line.find("����:");
	//	if (pswPos != string::npos)
	//	{
	//		cout << "ƥ�䵽����ؼ���" << endl;
	//		try
	//		{
	//			// ��ȡ���루"����:"ռ5�ֽڣ�
	//			string pswStr = line.substr(5);
	//			cout << "��ȡ�������ַ�������" << pswStr << "��" << endl;
	//			// ����Ƿ�Ϊ��
	//			if (pswStr.empty())
	//			{
	//				throw invalid_argument("�����ַ���Ϊ��");
	//			}
	//			// ת��Ϊ����
	//			PassWord = stoi(pswStr);
	//			state++; // ״̬��Ϊ2���ѻ�ȡID�����룩
	//			cout << "�������룺" << PassWord << "����ǰstate��" << state << endl;
	//			// ����Ƿ����һ������
	//			if (state == 2)
	//			{
	//				Manager M;
	//				M.SetData(Id, PassWord);
	//				m_Manager.insert(make_pair(Id, M));
	//				cout << "�Ѳ������Ա��ID:" << Id << "������:" << PassWord << "��" << endl;
	//				// ����״̬��׼����һ������
	//				state = 0;
	//				Id = 0;
	//				PassWord = 0;
	//			}
	//		}
	//		catch (const invalid_argument& e)
	//		{
	//			cout << "��" << lineNum << " ����ת��ʧ�ܣ�" << e.what() << endl;
	//			state = 0; // ����״̬
	//			PassWord = 0;
	//		}
	//		continue; // ���������룬������һ��
	//	}
	//	// �Ȳ���IDҲ�����������
	//	cout << "������ƥ��ؼ��֣�����" << endl;
	//}
	//// �ر��ļ�
	//ifs.close();
	//cout << "\n������ɣ��� " << m_Manager.size() << " ������Ա����" << endl;
	ifstream ifs;
	ifs.open("Manager.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}

	//�������
	this->m_Manager.clear();
	//������ʱ����
	int Id=0;
	int PassWord=0;
	string line;
	int state = 0;
	
	//��������
	while (getline(ifs, line))
	{
		//cout << "����ѭ��" << endl;
		if (line.find("����ԱID:") != string::npos)
		{
			//cout << "����ID" << endl;
			Id = stoi(line.substr(9));//�ص�:substr()������ֽ���,utf-8(û��BOM),ÿ������ռ�����ֽ�,����ANSI(GBK)��ÿ������ռ�����ֽ�
			state++;
		}
		else if (line.find("����:") != string::npos)
		{
			//cout << "��������" << endl;
			PassWord = stoi(line.substr(5));
			state++;
		}

		if (state == 2)
		{
			Manager M;
			M.SetData(Id, PassWord);
			this->m_Manager.insert(make_pair(Id, M));
			//cout << "�Ѳ������Ա��" << endl;
			state = 0;
			Id = 0;
			PassWord = 0;
		}
	}
	
	cout << "����"<<this->m_Manager.size()<<"������Ա���ݳɹ�!" << endl;
	ifs.close();
}

//������Ա�Ƿ����غϵ�ID
bool BookManage::Is_IDExist(int ID)//����m_Manager��ID
{
	map<int, Manager>::iterator pos = this->m_Manager.find(ID);
	if (pos != this->m_Manager.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//������Ա�Ƿ����غϵ�����
bool BookManage::Is_PassWordExist(int password)
{
	for (auto& pair : this->m_Manager)
	{
		auto& M = pair.second;
		if (M.GetPassWord()==password )
		{
			return true;
		}	
	}
	return false;
}

//����µĹ���Ա
void BookManage::CreatNewManager()
{
	cout << "�������µĹ���ԱID(10000-10010)������(6λ):  " << endl;
	cout << "ID :  ";
	int ID;
	while (true)
	{
		cin >> ID;
		if (cin.fail() || ID < 10000 || ID > 10010 || this->Is_IDExist(ID))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�����ID��������Ѵ��ڣ�����������:   ";
		}
		else
		{
			break;
		}
	}
	cout << "���� : ";
	int password;
	while (true)
	{
		cin >> password;
		if (cin.fail() || password < 100000 || password>1000000||this->Is_PassWordExist(password))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "����������������Ѵ��ڣ�����������:   ";
		}
		else
		{
			break;
		}
	}
	Manager M;
	M.SetData(ID, password);
	this->m_Manager.insert(make_pair(ID, M));
	this->Save_Manager();
}

//����鼮�Ƿ����غϵ�ID
bool BookManage::Is_BookIdExist(int id)
{
	map<int, Book>::iterator pos=this->m_Books.find(id);
	if (pos != this->m_Books.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����鼮�Ƿ����غϵ�����
bool BookManage::Is_BookNameExist(string name)
{
	for (auto& pair : this->m_Books)
	{
		auto& B = pair.second;
		if (B.GetBookName() == name)
		{
			return true;
		}
	}
	return false;
}

//����µ��鼮��Ϣ
void BookManage::AddNewBook()
{
	Book book;
	int id;
	string name;
	int count;
	double price;
	cout << "�������µ��鼮ID(10000-99999):  ";
	while (true)
	{
		cin >> id;
		if (cin.fail() || id < 10000 || id > 99999 || this->Is_BookIdExist(id))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "����Id��������������:  ";
		}
		else
		{
			break;
		}
	}
	cout << "���� : ";
	while (true)
	{
		cin >> name;
		if (this->Is_BookNameExist(name))
		{
			cout << "�鼮�����Ѵ��ڣ�����������: ";
		}
		else
		{
			break;
		}
	}
	cout << "����: ";
	while (true)
	{
		cin >> count;
		if (cin.fail() || count < 0 || count>100)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "����Ŀ��������������������: ";
		}
		else
		{
			break;
		}
	}
	cout << "����: ";
	while (true)
	{
		cin >> price;
		if (cin.fail() || price < 10.0 || price>100.0)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "����ļ۸񲻺���!����������: ";
		}
		else
		{
			break;
		}
	}
	book.SetBookData(id, name, count, price);
	this->m_Books.insert(make_pair(id, book));
	this->SaveBook();
}

//�����鼮
void BookManage::SaveBook()
{
	ofstream ofs;
	ofs.open("Books.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "�޷����ļ���";
		return;
	}
	for (auto& pair : this->m_Books)
	{
		auto& B = pair.second;
		ofs << "------------------------" << endl;
		ofs << "�鼮ID:" << B.GetBookId() << endl;
		ofs << "�鼮����:" << B.GetBookName() << endl;
		ofs << "����:" << B.GetPrice() << endl;
		ofs << "���:" << B.GetTotal() << endl;
		ofs << "------------------------" << endl;
	}
	cout << "�鼮��Ϣ���³ɹ�!" << endl;
	ofs.close();
}

//�鼮��Ϣ�������
void BookManage::LoadBooks()
{
	ifstream ifs;
	ifs.open("Books.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	//�������
	this->m_Books.clear();
	//������ʱ����
	Book book;
	int b_id;
	string b_bookname;
	int b_total;
	double b_price;
	string line;
	int state=0;
	//��ȡ����
	while (getline(ifs, line))
	{
		if (line == "------------------------")
		{
			if (state == 4)
			{
				book.SetBookData(b_id, b_bookname, b_total, b_price);
				this->m_Books.insert(make_pair(b_id, book));
				state = 0;
			}
			continue;
		}
		
		if (line.find("�鼮ID:") != string::npos)
		{
			b_id = stoi(line.substr(7));
			state++;
		}
		else if (line.find("�鼮����:") != string::npos)
		{
			b_bookname = line.substr(9);
			state++;
		}
		else if (line.find("����:") != string::npos)
		{
			b_price = stoi(line.substr(5));
			state++;
		}
		else if(line.find("���:")!=string::npos)
		{
			b_total = stoi(line.substr(5));
			state++;
		}
	}
	cout << "����"<<this->m_Books.size()<<"��ͼ�����ݳɹ�!" << endl;
	ifs.close();
}

//����Ƿ����غϵ��ο�ID
bool BookManage::Is_TouristIdExist(int id)
{
	map<int, Tourist>::iterator pos = this->m_Tourist.find(id);
	if (pos != this->m_Tourist.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����µ��ο�
void BookManage::AddNewTourist()
{
	int id;
	int psw;
	Tourist tourist;
	cout << "����������ID: ";
	while (true)
	{
		cin >> id;
		if (cin.fail() || id < 10000 || id>1000000||this->Is_TouristIdExist(id))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�������ID��������Ѵ��ڣ�����������: ";
		}
		else
		{
			break;
		}
	}
	cout << "��������������:";
	while (true)
	{
		cin >> psw;
		if (cin.fail() || psw < 100000 || psw>9999999)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "����������벻����!����������: ";
		}
		else
		{
			break;
		}
	}
	tourist.SetData(id, psw);
	this->m_Tourist.insert(make_pair(id, tourist));
	this->SaveTourist();
}

//�洢�ο���Ϣ
void BookManage::SaveTourist()
{
	ofstream ofs;
	ofs.open("Tourist.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (auto& pair : this->m_Tourist)
	{
		auto& T = pair.second;
		ofs << "�ο�ID:" << T.Getid() << endl;
		ofs << "����:" << T.Getpsw() << endl;
		ofs << "�ѽ��鼮:" << endl;
		for (int i = 0; i < T.books.size(); i++)
		{
			ofs<< T.books[i] << endl;
		}
	}
	cout << "���ݱ���ɹ���" << endl;
	ofs.close();
}

//�ÿ���Ϣ�������
void BookManage::LoadTourist()
{
	ifstream ifs;
	ifs.open("Tourist.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}

	//�������
	this->m_Tourist.clear();
	//���壻��ʱ����
	int id=0;
	int psw=0;
	string line;
	int state = 0;
	bool IsFoundKeyWord = false;
	vector<string> TempBookName;
	//��������
	while (getline(ifs, line))
	{
		if (line.find("�ο�ID:") != string::npos)
		{
			//cout << "�����ο�ID" << endl;
			id = stoi(line.substr(7));
			state++;
		}
		else if (line.find("����:") != string::npos)
		{
			//cout << "�������룡" << endl;
			psw = stoi(line.substr(5));
			state++;
		}
		//�����ѽ���鼮

		if (state == 2)
		{
			Tourist tourist;
			tourist.SetData(id, psw);
			this->m_Tourist.insert(make_pair(id, tourist));
			state = 0;
			id = 0;
			psw = 0;
		}
	}
	
	cout << "����"<<this->m_Tourist.size()<<"�ο����ݳɹ�!" << endl;
	ifs.close();
}

//�������Ա
void BookManage::ShowManager()
{
	for (auto& pair : this->m_Manager)
	{
		auto& M = pair.second;
		cout << "Id :" << pair.first << "   " << "����:  " << M.GetPassWord();
	}
}

//����ο�
void BookManage::ShowTourist()
{
	for (auto& pair : this->m_Tourist)
	{
		cout << pair.first << "   " << pair.second.Getpsw();
	}
}

//����鼮��Ϣ
void BookManage::ShowBooks()
{
	for (auto& pair : this->m_Books)
	{
		cout << "-------------------------------" << endl;
		cout << pair.first << endl;
		cout << pair.second.GetBookName() << endl;
		cout << pair.second.GetPrice() << endl;
		cout << "-------------------------------" << endl;
	}
}

//�˳�ϵͳ
void BookManage::ExitSystem()
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);
}

//����鼮��Ϣ
void BookManage::ShowBookInfo()
{
	Restart:
	cout << "---------------------------" << endl;
	cout << "-------1.����������--------" << endl;
	cout << "-------2.��ID����----------" << endl;
	cout << "---------------------------" << endl;
	int choice = 0;
	while (true)
	{
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��������!����������:";
		}
		else
		{
			break;
		}
	}
	
	if (choice == 1)
	{
		TryAgain:
		pair<bool, int> it = this->IsBookNameExist();
		if (it.second==-1)
		{
			cout << "δ�ҵ��鼮!����ѡ��:" << endl;
			cout << "---------1.����-------------" << endl;
			cout << "---------2.�л�������ʽ-----" << endl;
			cout << "---------0.�˳�-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�������!����������:";
				}
				else
				{
					break;
				}
			}
			if (input == 1)
			{
				goto TryAgain;
			}
			else if (input == 2)
			{
				goto Restart;
			}
			else if (input == 0)
			{
				exit(0);
			}
		}
		else
		{
			cout << "�鼮ID:" << this->m_Books[it.second].GetBookId() << endl;
			cout << "����:" << this->m_Books[it.second].GetBookName() << endl;
			cout << "���:" << this->m_Books[it.second].GetTotal() << endl;
			cout << "����:" << this->m_Books[it.second].GetPrice() << endl;
		}
	}
	else
	{
		TryAgain02:
		int id;
		cout << "�����鼮ID:" << endl;
		
		while (true)
		{
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "�������˲���ȷ���ַ��������³���: ";
			}
			else
			{
				break;
			}
		}
		if (this->IsBookIdExist(id))
		{
			cout << "�鼮ID:" << this->m_Books[id].GetBookId() << endl;
			cout << "����:" << this->m_Books[id].GetBookName() << endl;
			cout << "���:" << this->m_Books[id].GetTotal() << endl;
			cout << "����:" << this->m_Books[id].GetPrice() << endl;
		}
		else
		{
			cout << "δ�ҵ��鼮!����ѡ��:" << endl;
			cout << "---------1.����-------------" << endl;
			cout << "---------2.�л�������ʽ-----" << endl;
			cout << "---------0.�˳�-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�������!����������:";
				}
				else
				{
					break;
				}
			}
			if (input == 1)
			{
				goto TryAgain02;
			}
			else if (input == 2)
			{
				goto Restart;
			}
			else if (input == 0)
			{
				exit(0);
			}
		}
	}
	system("pause");
	system("cls");
}

//��������
pair<bool, int> BookManage::IsBookNameExist()
{
	string bookname;
	cout << "�����鼮����" << endl;
	cin >> bookname;
	
	for (auto& pair : this->m_Books)
	{
		auto & B = pair.second;
		if (B.GetBookName() == bookname)
		{
			int id = B.GetBookId();
			return { true,id };
		}
	}
	
	return { false,-1 };
}

//�鼮ID�Ƿ����
bool BookManage::IsBookIdExist(int id)
{
	map<int, Book>::iterator pos = this->m_Books.find(id);
	if (pos != this->m_Books.end())
	{
		return true;
	}
	return false;
}

//ɾ���鼮
void BookManage::DeleteBook()
{
	Restart01:
	cout << "---------------------------" << endl;
	cout << "-------1.������ɾ��--------" << endl;
	cout << "-------2.��IDɾ��----------" << endl;
	cout << "---------------------------" << endl;
	int choice = 0;
	while (true)
	{
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��������!����������:";
		}
		else
		{
			break;
		}
	}
	if (choice == 1)
	{
	    TryAgain01:
		pair<bool, int> it = this->IsBookNameExist();
		if (it.second == -1)
		{
			cout << "δ�ҵ��鼮!����ѡ��:" << endl;;
			cout << "---------1.����-------------" << endl;
			cout << "---------2.�л�������ʽ-----" << endl;
			cout << "---------0.�˳�-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�������!����������:";
				}
				else
				{
					break;
				}
			}
			if (input == 1)
			{
				goto TryAgain01;
			}
			else if (input == 2)
			{
				goto Restart01;
			}
			else if (input == 0)
			{
				exit(0);
			}
		}
		else
		{
			this->m_Books.erase(it.second);
			this->SaveBook();
		}
	}
	else
	{
		TryAgain02:
		int id;
		cout << "�����鼮ID:" << endl;

		while (true)
		{
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "�������˲���ȷ���ַ��������³���: ";
			}
			else
			{
				break;
			}
		}
		if (this->IsBookIdExist(id))
		{
			this->m_Books.erase(id);
			this->SaveBook();
		}
		else
		{
			cout << "δ�ҵ��鼮!����ѡ��:" << endl;
			cout << "---------1.����-------------" << endl;
			cout << "---------2.�л�������ʽ-----" << endl;
			cout << "---------0.�˳�-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�������!����������:";
				}
				else
				{
					break;
				}
			}
			if (input == 1)
			{
				goto TryAgain02;
			}
			else if (input == 2)
			{
				goto Restart01;
			}
			else if (input == 0)
			{
				exit(0);
			}
		}
	}
	system("pause");
	system("cls");
}

//�޸��鼮��Ϣ
void BookManage::ModifyBookInfo()
{
	Restart02:
	cout << "--------------------------------------------" << endl;
	cout << "---------------��ѡ��������ʽ---------------" << endl;
	cout << "------------1.��Ҫ�޸ĵ��鼮����------------" << endl;
	cout << "------------2.��Ҫ�޸ĵ��鼮ID--------------" << endl;
	cout << "--------------------------------------------" << endl;
	int choice;
	while (true)
	{
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�����������������: ";
		}
		else
		{
			break;
		}
	}
	if (choice == 1)
	{	
		TryAgain02:
		pair<bool, int> B = this->IsBookNameExist();
		if (B.second == -1)
		{
			cout << "δ�ҵ��鼮!������ѡ��:" << endl;
			cout << "---------1.����-------------" << endl;
			cout << "---------2.�л�������ʽ-----" << endl;
			cout << "---------0.�˳�-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000,'\n');
					cout << "���벻��ȷ!����������:";
				}
				else
				{
					break;
				}
			}
			if (input == 1)
			{
				goto TryAgain02;
			}
			else if (input == 2)
			{
				goto Restart02;
			}
			else if (input == 0)
			{
				exit(0);
			}
		}
		else
		{
			cout << "��������Ҫ�޸ĵ�����" << endl;
			cout << "�鼮ID:";
			int bookid;
			while (true)
			{
				cin >> bookid;
				if (cin.fail() || bookid < 10000 || bookid>1000000 || this->IsBookIdExist(bookid))
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�鼮ID��������Ѵ���!����������:";
				}
				else
				{
					break;
				}
			}
			cout << "����:";
			string bookname;
			cin >> bookname;
			cout << "���:";
			int count;
			while (true)
			{
				cin >> count;
				if (cin.fail() || count < 0 || count>1000)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�鼮��治������������!����������:";
				}
				else
				{
					break;
				}
			}
			cout << "����:";
			int price;
			while (true)
			{
				cin >> price;
				if (cin.fail() || price < 0 || price>150)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�鼮���۲�������������!����������:";
				}
				else
				{
					break;
				}
			}
			this->m_Books[B.second].SetBookData(bookid, bookname, count, price);
			this->SaveBook();
		}
	}
	else
	{	
		//��ID�޸�
		TryAgain03:
		cout << "�������鼮ID:" << endl;
		int id;
		
		while (true)
		{
			cin >> id;
			if (cin.fail() || id < 10000 || id>100000)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "�������!����������:";
			}
			else
			{
				break;
			}
		}
		if (!this->IsBookIdExist(id))
		{
			cout << "δ�ҵ��鼮!������ѡ��:" << endl;
			cout << "---------1.����-------------" << endl;
			cout << "---------2.�л�������ʽ-----" << endl;
			cout << "---------0.�˳�-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "���벻��ȷ!����������:";
				}
				else
				{
					break;
				}
			}
			if (input == 1)
			{
				goto TryAgain03;
			}
			else if (input == 2)
			{
				goto Restart02;
			}
			else if (input == 0)
			{
				exit(0);
			}
		}
		else
		{
			cout << "��������Ҫ�޸ĵ�����" << endl;
			cout << "�鼮ID:";
			int bookid;
			while (true)
			{
				cin >> bookid;
				if (cin.fail() || bookid < 10000 || bookid>100000 || this->IsBookIdExist(bookid))
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�鼮ID��������Ѵ���!����������:";
				}
			}
			cout << "����:";
			string bookname;
			cin >> bookname;
			cout << "���:";
			int count;
			while (true)
			{
				cin >> count;
				if (cin.fail() || count < 0 || count>1000)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�鼮��治������������!����������:";
				}
				else
				{
					break;
				}
			}
			cout << "����:";
			int price;
			while (true)
			{
				cin >> price;
				if (cin.fail() || price < 0 || price>150)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "�鼮���۲�������������!����������:";
				}
				else
				{
					break;
				}
			}
			this->m_Books[id].SetBookData(bookid, bookname, count, price);
			this->SaveBook();
		}
	}
}

//����
void BookManage::BorrowBook()
{
	this->ShowBooks();
	cout << "��������Ҫ������鼮ID" << endl;
	int bookid;
	while (true)
	{
		cin >> bookid;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�����ID����!������ѡ��:";
		}
		else
		{
			break;
		}
	}
	map<int, Book>::iterator pos = this->m_Books.find(bookid);
	if (pos != this->m_Books.end()&& pos->second.GetTotal() != 0)
	{
		pos->second.m_total--;
		this->RecoreLoginT.books.push_back(pos->second.GetBookName());
		this->SaveBook();
		this->SaveTourist();
	}
}

//����
void BookManage::ReturnBook()
{

}

//��ʾ�ѽ���鼮
void BookManage::ShowBorrowBook()
{

}

BookManage::~BookManage()
{

}