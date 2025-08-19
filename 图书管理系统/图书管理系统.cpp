#include<iostream>
#include<map>
#include"图书管理类.h"
using namespace std;

int main()
{
	BookManage BM;
	
	/*BM.ShowManager();
	BM.ShowTourist();*/
	int Identity;
	Identity =BM.IdentityVerification();
	int chioce;
	if (BM.Login(Identity))
	{
		while (true)
		{
			BM.ShowMenu(Identity);
			while (true)
			{
				cin >> chioce;
				if (cin.fail() || chioce < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入有误！请重新输入： ";
				}
				else
				{
					break;
				}
			}
			if (Identity == 1)
			{
				switch (chioce)
				{
				case 1:
					BM.AddNewBook();
					break;
				case 2:
					BM.CreatNewManager();
					break;
				case 3:
					BM.ModifyBookInfo();
					break;
				case 4:
					BM.ShowBookInfo();
					break;
				case 5:
					BM.DeleteBook();
					break;
				case 0:
					BM.ExitSystem();
					break;
				default:
					system("pause");
					system("cls");
					break;
				}
			}
			else
			{
				switch (chioce)
				{
				case 1:
					BM.BorrowBook();
					break;
				case 2:
					break;
				case 3:
					BM.ShowBorrowBook();
					break;
				case 0:
					BM.ExitSystem();
					break;
				default:
					system("pause");
					system("cls");
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}
/*
总结
1.学习了for循环如何输出map容器，对pair<>的操作，输出，做为返回值都学习了
2.用goto语句简单替代返回到某个节点（页面），goto不可以跨函数
3.学习了用string的substr()，()里的是字节数，在.txt文件里如果是UTF-8则每个中文占3个字节，英文每个一个字节
  如果是ANSI（GBK）编码模式下，每个中文占2个字节，英文每个一个字节，有时无法从(.txt)文件读取数据
  是因为中文 Windows 下的编译器默认用 ANSI（GBK）编码 存储字符串常量
  .txt 是 UTF-8 编码 时，        文件中的字节序列是 UTF-8 格式但程序中的字节序列是 ANSI（GBK）格式
  两者的字节序列完全不同，find() 自然匹配失败（返回 string::npos），无法进入解析分支，最终无法录入信息。
4.快捷键；在头文件里使用alt+enter+d可以快速在.cpp文件里创建函数定义
*/