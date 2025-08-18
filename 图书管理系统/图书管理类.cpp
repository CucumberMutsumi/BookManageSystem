#include"图书管理类.h"


BookManage::BookManage()
{
	this->LoadBooks();
	this->LoadManager();
	this->LoadTourist();
}

//身份选择
int BookManage::IdentityVerification()
{
	cout << "-------------------------------------" << endl;
	cout << "----------请输入你的身份-------------" << endl;
	cout << "----------1.图书管理员---------------" << endl;
	cout << "----------2.游客---------------------" << endl;
	cout << "-------------------------------------" << endl;
	int Identity;
	while (true)
	{
		cin >> Identity;
		if (cin.fail() || Identity < 0 || Identity>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "身份输入有误！请重新输入： ";
		}
		else
		{
			break;
		}
	}
	return Identity;
}

//验证游客是否存在
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

//验证管理员是否存在
bool BookManage::Is_ManagerExist(int id, int psw)
{
	cout << "当前管理员列表：" << endl;
	for (auto& pair : this->m_Manager) {
		cout << "ID: " << pair.first << ", 密码: " << pair.second.GetPassWord() << endl;
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

//登录(需要学习状态栈)
bool BookManage::Login(int identity)
{
	while (true)
	{
		statr:
		if (identity == 1)//提示用户输入id和密码
		{
			cout << "请输入id:  ";
			int id;
			while (true)
			{
				cin >> id;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入有误！请重新输入:  ";
				}
				else
				{
					break;
				}
			}
			cout << "请输入密码:  ";
			int psw;
			while (true)
			{
				cin >> psw;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入有误！请重新输入:  ";
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
				cout << "管理员ID或密码错误！" << endl;
				cout << "请选择操作：1-重新尝试 2-返回上一级" << endl;
				int choice;
				cin >> choice;
				if (choice != 1) // 如果用户不选择重新尝试，则返回登录失败
				{
					return false;
				}
			}
			
		}
		else
		{
			//在这里添加询问是否是新用户
			cout << "-----------------------------------" << endl;
			cout << "------------1.登录-----------------" << endl;
			cout << "------------2.创建新账号-----------" << endl;
			cout << "-----------------------------------" << endl;
			int choice = 0;
			while (true)
			{
				cin >> choice;
				if (cin.fail() || choice < 0 || choice>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入有误!请重新输入:";
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
				cout << "请输入id:  ";
				int id;
				while (true)
				{
					cin >> id;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "输入有误！请重新输入:  ";
					}
					else
					{
						break;
					}
				}
				cout << "请输入密码:  ";
				int psw;
				while (true)
				{
					cin >> psw;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "输入有误！请重新输入:  ";
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
					cout << "游客ID或密码错误！" << endl;
					cout << "请选择操作：1-重新尝试 2-返回上一级" << endl;
					int choice;
					cin >> choice;
					if (choice != 1) // 如果用户不选择重新尝试，则返回登录失败
					{
						return false;
					}
				}
			}
		}
	}
	
}

//根据身份显示菜单
void BookManage::ShowMenu(int Identity)
{
	if (Identity == 1)
	{
		cout << "---------- <    登录成功     > ----------" << endl;
		cout << "--------------1.添加书籍-----------------" << endl;
		cout << "--------------2.添加新的管理员-----------" << endl;
		cout << "--------------3.修改书籍信息-------------" << endl;
		cout << "--------------4.查询书籍信息--------------" << endl;
		cout << "--------------5.删除书籍-----------------" << endl;
		cout << "--------------0.退出系统-----------------" << endl;
		cout << "-----------------------------------------" << endl;
	}
	else
	{
		cout << "---------- <    登录成功     > ----------" << endl;
		cout << "--------------1.借书---------------------" << endl;
		cout << "--------------2.还书---------------------" << endl;
		cout << "--------------3.查看已借书籍-------------" << endl;
		cout << "--------------0.退出系统-----------------" << endl;
		cout << "-----------------------------------------" << endl;
	}
}

//保存管理员信息
void BookManage::Save_Manager()
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "文件无法打开！存储数据失败！" << endl;
		return;
	}
	
	for (auto& pair : this->m_Manager)
	{
		auto& M = pair.second;
		ofs << "管理员ID:" << M.GetID() << endl;
		ofs << "密码:" << M.GetPassWord() << endl;
	}
	ofs.close();
}

//加载管理员
void BookManage::LoadManager()
{
	//ifstream ifs;
	//ifs.open("Manager.txt", ios::in);
	//if (!ifs.is_open())
	//{
	//	cout << "打开文件失败！请确认Manager.txt存在" << endl;
	//	return;
	//}
	//// 清空容器
	//m_Manager.clear();
	//// 临时变量
	//int Id = 0;
	//int PassWord = 0;
	//string line;
	//int state = 0;  // 状态标记：0-未开始，1-已获取ID，2-已获取ID和密码
	//int lineNum = 0; // 行号，用于调试
	//// 逐行读取文件
	//while (getline(ifs, line))
	//{
	//	lineNum++;
	//	cout << "进入循环（行" << lineNum << "），内容：【" << line << "】" << endl;
	//	// 跳过空行
	//	if (line.empty())
	//	{
	//		cout << "该行是空行，跳过" << endl;
	//		continue;
	//	}
	//	// 尝试匹配管理员ID
	//	size_t idPos = line.find("管理员ID:");
	//	if (idPos != string::npos)
	//	{
	//		cout << "匹配到管理员ID关键字" << endl;
	//		try
	//		{
	//			// 截取ID（"管理员ID:"占9字节）
	//			string idStr = line.substr(9);
	//			cout << "截取的ID字符串：【" << idStr << "】" << endl;
	//			// 检查是否为空
	//			if (idStr.empty())
	//			{
	//				throw invalid_argument("ID字符串为空");
	//			}
	//			// 转换为整数
	//			Id = stoi(idStr);
	//			state++; // 状态变为1（已获取ID）
	//			cout << "存入ID：" << Id << "，当前state：" << state << endl;
	//		}
	//		catch (const invalid_argument& e)
	//		{
	//			cout << "行" << lineNum << " ID转换失败：" << e.what() << endl;
	//			state = 0; // 重置状态
	//			Id = 0;
	//		}
	//		continue; // 处理完ID，继续下一行
	//	}
	//	// 尝试匹配密码（只有ID未匹配时才会执行这里）
	//	size_t pswPos = line.find("密码:");
	//	if (pswPos != string::npos)
	//	{
	//		cout << "匹配到密码关键字" << endl;
	//		try
	//		{
	//			// 截取密码（"密码:"占5字节）
	//			string pswStr = line.substr(5);
	//			cout << "截取的密码字符串：【" << pswStr << "】" << endl;
	//			// 检查是否为空
	//			if (pswStr.empty())
	//			{
	//				throw invalid_argument("密码字符串为空");
	//			}
	//			// 转换为整数
	//			PassWord = stoi(pswStr);
	//			state++; // 状态变为2（已获取ID和密码）
	//			cout << "存入密码：" << PassWord << "，当前state：" << state << endl;
	//			// 检查是否凑齐一组数据
	//			if (state == 2)
	//			{
	//				Manager M;
	//				M.SetData(Id, PassWord);
	//				m_Manager.insert(make_pair(Id, M));
	//				cout << "已插入管理员（ID:" << Id << "，密码:" << PassWord << "）" << endl;
	//				// 重置状态，准备下一组数据
	//				state = 0;
	//				Id = 0;
	//				PassWord = 0;
	//			}
	//		}
	//		catch (const invalid_argument& e)
	//		{
	//			cout << "行" << lineNum << " 密码转换失败：" << e.what() << endl;
	//			state = 0; // 重置状态
	//			PassWord = 0;
	//		}
	//		continue; // 处理完密码，继续下一行
	//	}
	//	// 既不是ID也不是密码的行
	//	cout << "该行无匹配关键字，跳过" << endl;
	//}
	//// 关闭文件
	//ifs.close();
	//cout << "\n加载完成，共 " << m_Manager.size() << " 个管理员数据" << endl;
	ifstream ifs;
	ifs.open("Manager.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
		return;
	}

	//清空容器
	this->m_Manager.clear();
	//定义临时变量
	int Id=0;
	int PassWord=0;
	string line;
	int state = 0;
	
	//读入数据
	while (getline(ifs, line))
	{
		//cout << "进入循环" << endl;
		if (line.find("管理员ID:") != string::npos)
		{
			//cout << "存入ID" << endl;
			Id = stoi(line.substr(9));//重点:substr()里的是字节数,utf-8(没有BOM),每个中文占三个字节,若是ANSI(GBK)则每个中文占两个字节
			state++;
		}
		else if (line.find("密码:") != string::npos)
		{
			//cout << "存入密码" << endl;
			PassWord = stoi(line.substr(5));
			state++;
		}

		if (state == 2)
		{
			Manager M;
			M.SetData(Id, PassWord);
			this->m_Manager.insert(make_pair(Id, M));
			//cout << "已插入管理员！" << endl;
			state = 0;
			Id = 0;
			PassWord = 0;
		}
	}
	
	cout << "加载"<<this->m_Manager.size()<<"个管理员数据成功!" << endl;
	ifs.close();
}

//检查管理员是否有重合的ID
bool BookManage::Is_IDExist(int ID)//查找m_Manager的ID
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

//检查管理员是否有重合的密码
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

//添加新的管理员
void BookManage::CreatNewManager()
{
	cout << "请输入新的管理员ID(10000-10010)和密码(6位):  " << endl;
	cout << "ID :  ";
	int ID;
	while (true)
	{
		cin >> ID;
		if (cin.fail() || ID < 10000 || ID > 10010 || this->Is_IDExist(ID))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入的ID的有误或已存在！请重新输入:   ";
		}
		else
		{
			break;
		}
	}
	cout << "密码 : ";
	int password;
	while (true)
	{
		cin >> password;
		if (cin.fail() || password < 100000 || password>1000000||this->Is_PassWordExist(password))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入的密码的有误或已存在！请重新输入:   ";
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

//检查书籍是否有重合的ID
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

//检查书籍是否有重合的书名
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

//添加新的书籍信息
void BookManage::AddNewBook()
{
	Book book;
	int id;
	string name;
	int count;
	double price;
	cout << "请输入新的书籍ID(10000-99999):  ";
	while (true)
	{
		cin >> id;
		if (cin.fail() || id < 10000 || id > 99999 || this->Is_BookIdExist(id))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入Id有误！请重新输入:  ";
		}
		else
		{
			break;
		}
	}
	cout << "书名 : ";
	while (true)
	{
		cin >> name;
		if (this->Is_BookNameExist(name))
		{
			cout << "书籍名称已存在！请重新输入: ";
		}
		else
		{
			break;
		}
	}
	cout << "存量: ";
	while (true)
	{
		cin >> count;
		if (cin.fail() || count < 0 || count>100)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "输入的库存量不合理！请重新输入: ";
		}
		else
		{
			break;
		}
	}
	cout << "单价: ";
	while (true)
	{
		cin >> price;
		if (cin.fail() || price < 10.0 || price>100.0)
		{
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "输入的价格不合理!请重新输入: ";
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

//保存书籍
void BookManage::SaveBook()
{
	ofstream ofs;
	ofs.open("Books.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "无法打开文件！";
		return;
	}
	for (auto& pair : this->m_Books)
	{
		auto& B = pair.second;
		ofs << "------------------------" << endl;
		ofs << "书籍ID:" << B.GetBookId() << endl;
		ofs << "书籍名称:" << B.GetBookName() << endl;
		ofs << "单价:" << B.GetPrice() << endl;
		ofs << "库存:" << B.GetTotal() << endl;
		ofs << "------------------------" << endl;
	}
	cout << "书籍信息更新成功!" << endl;
	ofs.close();
}

//书籍信息读入程序
void BookManage::LoadBooks()
{
	ifstream ifs;
	ifs.open("Books.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	//容器清空
	this->m_Books.clear();
	//定义临时变量
	Book book;
	int b_id;
	string b_bookname;
	int b_total;
	double b_price;
	string line;
	int state=0;
	//读取数据
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
		
		if (line.find("书籍ID:") != string::npos)
		{
			b_id = stoi(line.substr(7));
			state++;
		}
		else if (line.find("书籍名称:") != string::npos)
		{
			b_bookname = line.substr(9);
			state++;
		}
		else if (line.find("单价:") != string::npos)
		{
			b_price = stoi(line.substr(5));
			state++;
		}
		else if(line.find("库存:")!=string::npos)
		{
			b_total = stoi(line.substr(5));
			state++;
		}
	}
	cout << "加载"<<this->m_Books.size()<<"本图书数据成功!" << endl;
	ifs.close();
}

//检查是否有重合的游客ID
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

//添加新的游客
void BookManage::AddNewTourist()
{
	int id;
	int psw;
	Tourist tourist;
	cout << "请输入您的ID: ";
	while (true)
	{
		cin >> id;
		if (cin.fail() || id < 10000 || id>1000000||this->Is_TouristIdExist(id))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "您输入的ID不合理或已存在！请重新输入: ";
		}
		else
		{
			break;
		}
	}
	cout << "请输入您的密码:";
	while (true)
	{
		cin >> psw;
		if (cin.fail() || psw < 100000 || psw>9999999)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "您输入的密码不合理!请重新输入: ";
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

//存储游客信息
void BookManage::SaveTourist()
{
	ofstream ofs;
	ofs.open("Tourist.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	for (auto& pair : this->m_Tourist)
	{
		auto& T = pair.second;
		ofs << "游客ID:" << T.Getid() << endl;
		ofs << "密码:" << T.Getpsw() << endl;
		ofs << "已借书籍:" << endl;
		for (int i = 0; i < T.books.size(); i++)
		{
			ofs<< T.books[i] << endl;
		}
	}
	cout << "数据保存成功！" << endl;
	ofs.close();
}

//旅客信息读入程序
void BookManage::LoadTourist()
{
	ifstream ifs;
	ifs.open("Tourist.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败！" << endl;
		return;
	}

	//清空容器
	this->m_Tourist.clear();
	//定义；临时变量
	int id=0;
	int psw=0;
	string line;
	int state = 0;
	bool IsFoundKeyWord = false;
	vector<string> TempBookName;
	//读入数据
	while (getline(ifs, line))
	{
		if (line.find("游客ID:") != string::npos)
		{
			//cout << "存入游客ID" << endl;
			id = stoi(line.substr(7));
			state++;
		}
		else if (line.find("密码:") != string::npos)
		{
			//cout << "存入密码！" << endl;
			psw = stoi(line.substr(5));
			state++;
		}
		//存入已借的书籍

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
	
	cout << "加载"<<this->m_Tourist.size()<<"游客数据成功!" << endl;
	ifs.close();
}

//输出管理员
void BookManage::ShowManager()
{
	for (auto& pair : this->m_Manager)
	{
		auto& M = pair.second;
		cout << "Id :" << pair.first << "   " << "密码:  " << M.GetPassWord();
	}
}

//输出游客
void BookManage::ShowTourist()
{
	for (auto& pair : this->m_Tourist)
	{
		cout << pair.first << "   " << pair.second.Getpsw();
	}
}

//输出书籍信息
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

//退出系统
void BookManage::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}

//输出书籍信息
void BookManage::ShowBookInfo()
{
	Restart:
	cout << "---------------------------" << endl;
	cout << "-------1.用书名查找--------" << endl;
	cout << "-------2.用ID查找----------" << endl;
	cout << "---------------------------" << endl;
	int choice = 0;
	while (true)
	{
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入有误!请重新输入:";
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
			cout << "未找到书籍!输入选择:" << endl;
			cout << "---------1.重试-------------" << endl;
			cout << "---------2.切换搜索方式-----" << endl;
			cout << "---------0.退出-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入错误!请重新输入:";
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
			cout << "书籍ID:" << this->m_Books[it.second].GetBookId() << endl;
			cout << "书名:" << this->m_Books[it.second].GetBookName() << endl;
			cout << "库存:" << this->m_Books[it.second].GetTotal() << endl;
			cout << "单价:" << this->m_Books[it.second].GetPrice() << endl;
		}
	}
	else
	{
		TryAgain02:
		int id;
		cout << "输入书籍ID:" << endl;
		
		while (true)
		{
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "您输入了不正确的字符！请重新尝试: ";
			}
			else
			{
				break;
			}
		}
		if (this->IsBookIdExist(id))
		{
			cout << "书籍ID:" << this->m_Books[id].GetBookId() << endl;
			cout << "书名:" << this->m_Books[id].GetBookName() << endl;
			cout << "库存:" << this->m_Books[id].GetTotal() << endl;
			cout << "单价:" << this->m_Books[id].GetPrice() << endl;
		}
		else
		{
			cout << "未找到书籍!输入选择:" << endl;
			cout << "---------1.重试-------------" << endl;
			cout << "---------2.切换搜索方式-----" << endl;
			cout << "---------0.退出-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入错误!请重新输入:";
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

//查找书名
pair<bool, int> BookManage::IsBookNameExist()
{
	string bookname;
	cout << "输入书籍名称" << endl;
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

//书籍ID是否存在
bool BookManage::IsBookIdExist(int id)
{
	map<int, Book>::iterator pos = this->m_Books.find(id);
	if (pos != this->m_Books.end())
	{
		return true;
	}
	return false;
}

//删除书籍
void BookManage::DeleteBook()
{
	Restart01:
	cout << "---------------------------" << endl;
	cout << "-------1.用书名删除--------" << endl;
	cout << "-------2.用ID删除----------" << endl;
	cout << "---------------------------" << endl;
	int choice = 0;
	while (true)
	{
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入有误!请重新输入:";
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
			cout << "未找到书籍!输入选择:" << endl;;
			cout << "---------1.重试-------------" << endl;
			cout << "---------2.切换搜索方式-----" << endl;
			cout << "---------0.退出-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入错误!请重新输入:";
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
		cout << "输入书籍ID:" << endl;

		while (true)
		{
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "您输入了不正确的字符！请重新尝试: ";
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
			cout << "未找到书籍!输入选择:" << endl;
			cout << "---------1.重试-------------" << endl;
			cout << "---------2.切换搜索方式-----" << endl;
			cout << "---------0.退出-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入错误!请重新输入:";
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

//修改书籍信息
void BookManage::ModifyBookInfo()
{
	Restart02:
	cout << "--------------------------------------------" << endl;
	cout << "---------------请选择搜索方式---------------" << endl;
	cout << "------------1.需要修改的书籍名称------------" << endl;
	cout << "------------2.需要修改的书籍ID--------------" << endl;
	cout << "--------------------------------------------" << endl;
	int choice;
	while (true)
	{
		cin >> choice;
		if (cin.fail() || choice < 0 || choice>2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入错误，请重新输入: ";
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
			cout << "未找到书籍!请输入选择:" << endl;
			cout << "---------1.重试-------------" << endl;
			cout << "---------2.切换搜索方式-----" << endl;
			cout << "---------0.退出-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000,'\n');
					cout << "输入不正确!请重新输入:";
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
			cout << "请输入需要修改的内容" << endl;
			cout << "书籍ID:";
			int bookid;
			while (true)
			{
				cin >> bookid;
				if (cin.fail() || bookid < 10000 || bookid>1000000 || this->IsBookIdExist(bookid))
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "书籍ID不合理或已存在!请重新输入:";
				}
				else
				{
					break;
				}
			}
			cout << "书名:";
			string bookname;
			cin >> bookname;
			cout << "库存:";
			int count;
			while (true)
			{
				cin >> count;
				if (cin.fail() || count < 0 || count>1000)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "书籍库存不合理或输入错误!请重新输入:";
				}
				else
				{
					break;
				}
			}
			cout << "单价:";
			int price;
			while (true)
			{
				cin >> price;
				if (cin.fail() || price < 0 || price>150)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "书籍单价不合理或输入错误!请重新输入:";
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
		//按ID修改
		TryAgain03:
		cout << "请输入书籍ID:" << endl;
		int id;
		
		while (true)
		{
			cin >> id;
			if (cin.fail() || id < 10000 || id>100000)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "输入错误!请重新输入:";
			}
			else
			{
				break;
			}
		}
		if (!this->IsBookIdExist(id))
		{
			cout << "未找到书籍!请输入选择:" << endl;
			cout << "---------1.重试-------------" << endl;
			cout << "---------2.切换搜索方式-----" << endl;
			cout << "---------0.退出-------------" << endl;
			int input;
			while (true)
			{
				cin >> input;
				if (cin.fail() || input < 0 || input>2)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入不正确!请重新输入:";
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
			cout << "请输入需要修改的内容" << endl;
			cout << "书籍ID:";
			int bookid;
			while (true)
			{
				cin >> bookid;
				if (cin.fail() || bookid < 10000 || bookid>100000 || this->IsBookIdExist(bookid))
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "书籍ID不合理或已存在!请重新输入:";
				}
			}
			cout << "书名:";
			string bookname;
			cin >> bookname;
			cout << "库存:";
			int count;
			while (true)
			{
				cin >> count;
				if (cin.fail() || count < 0 || count>1000)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "书籍库存不合理或输入错误!请重新输入:";
				}
				else
				{
					break;
				}
			}
			cout << "单价:";
			int price;
			while (true)
			{
				cin >> price;
				if (cin.fail() || price < 0 || price>150)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "书籍单价不合理或输入错误!请重新输入:";
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

//借书
void BookManage::BorrowBook()
{
	this->ShowBooks();
	cout << "请输入需要借书的书籍ID" << endl;
	int bookid;
	while (true)
	{
		cin >> bookid;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入的ID错误!请输入选择:";
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

//还书
void BookManage::ReturnBook()
{

}

//显示已借的书籍
void BookManage::ShowBorrowBook()
{

}

BookManage::~BookManage()
{

}