#include "Book_Control.h"
#include"Manager.h"
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

//登录
bool Book_Control::load(string& name, string& password)
{
	cout << "账号：";
	getline(cin, name);
	cout << "密码：";
	getline(cin, password);
	bool is_loading = false;
	fstream manager_file;
	string readname;
	string readpassword;
	manager_file.open("Manager.TXT", ios_base::in | ios_base::out | ios_base::binary);
	if (manager_file.is_open())
	{
		while (manager_file.good())
		{
			manager_file >> readname;
			manager_file >> readpassword;
			if (readname == name && readpassword == password)
			{
				cout << "登陆成功！" << endl;
				Sleep(2000);
				return true;
			}
			else
			{
				cout << "用户名或密码错误" << endl;
				Sleep(3000);
				return false;
			}
		}
	}
}

//流程控制
void Book_Control::Manager_Control()
{
	string manager_number;
	string manager_password;
	while (!load(manager_number, manager_password))
	{
		system("cls");
	}
	Manager manager(manager_number, manager_password);
	string file_path = "Books.TXT";
	vector<Book> books;
	if (!is_File_Empty(file_path))
	{
		cout << "读取中......"<<endl;
		Sleep(3000);
		fstream book_file(file_path, ios_base::in);
		if (book_file.is_open())
		{
			string name;
			string author;
			string number;
			while (book_file.good())
			{
				book_file >> name;
				book_file >> author;
				book_file >> number;
				Book book(name, author, number);
				books.push_back(book);
			}
			book_file.close();
		}
	}
	else
	{
		cout << "文件为空，请先输入内容" << endl;
		Sleep(3000);
	}
	int choice = 1;
	bool is_true = true;
	while (is_true)
	{
		system("cls");
		Manager_Main_Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:										//新书籍录入
		{
			Creat(books);
			break;
		}
		case 2:										//修改书籍
		{
			Motify(books);
			break;
		}
		case 3:										//删除书籍
		{
			Delete(books);
			break;
		}
		case 4:										//查找书籍
		{
			LookUp(books);
			break;
		}
		case 5:										//查看所有书籍
		{
			Look_Over(books);
			break;
		}
		case 0:
		{
			Save(books, file_path);
			is_true = false;
			break;
		}
		default:
		{
			cout << "输入错误，请重新输入" << endl;
			Sleep(3000);
			continue;
		}
		}
	}
	system("cls");
	cout << "保存成功，正在退出....." << endl;
	system("cls");
	cout << "退出完成" << endl; 
	return;
	
}

//目录
void Book_Control::Manager_Main_Menu()
{
	cout << "请选择操作" << endl;
	cout << "1.创建书籍" << endl;
	cout << "2.修改书籍" << endl;
	cout << "3.删除书籍" << endl;
	cout << "4.查找书籍" << endl;
	cout << "5.查看书籍" << endl;
	cout << "0.退出" << endl;
	cout << "请选择：";
	return;
}

//判断存放书本的文件是否为空
bool Book_Control::is_File_Empty(string& file_path)
{
	struct stat buf;
	stat(file_path.c_str(), &buf);
	size_t size = buf.st_size;
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//创建新书
void Book_Control::Creat(vector<Book>& books)
{
	system("cls");
	cin.ignore();
	string name;
	string author;
	string number;
	cout << "请依次输入书名、作者、编号，一行输入一个数据" << endl;
	getline(cin, name);
	getline(cin, author);
	getline(cin, number);
	Book new_book(name, author, number);
	books.push_back(new_book);
	cout << "书籍录入成功" << endl;
	Sleep(3000);
	return;
}

//修改书籍
void Book_Control::Motify(vector<Book>& books)
{
	system("cls");
	cin.ignore();
	cout << "请输入修改书籍的编号" << endl;
	string find_number;
	string new_name;
	string new_author;
	string new_number;
	int max = books.size();
	getline(cin, find_number);
	for (int i = 0; i < max; i++)
	{
		if (books[i].Return_number() == find_number)
		{
			books[i].Output();
			cout << "请依次输入书名、作者、编号，一行输入一个数据" << endl;
			getline(cin, new_name);
			new_name = Underline_Replace_Space(new_name);
			getline(cin, new_author);
			new_author = Underline_Replace_Space(new_author);
			getline(cin, new_number);
			books[i].Motify_Author(new_author);
			books[i].Motify_Name(new_name);
			books[i].Motify_Number(new_number);
			books[i].Output();
			cout << "修改完成" << endl;
			Sleep(3000);
			break;
		}
	}
	return;
}

//删除书籍
void Book_Control::Delete(vector<Book>& books)
{
	system("cls");
	cin.ignore();
	cout << "请输入修改书籍的编号" << endl;
	string find_number;
	getline(cin, find_number);
	int max = books.size();
	for (int i = 0; i < max; i++)
	{
		if (books[i].Return_number() == find_number)
		{
			books[i].Output();
			cout << "确认删除请输入1" << endl;
			int is_sure = 0;
			cin >> is_sure;
			if (is_sure == 1)
			{
				books.erase(books.begin() + i);
				cout << "删除完成" << endl;
			}
			else
			{
				cout << "删除取消" << endl;
			}
			Sleep(3000);
			break;
		}
	}
	return;
}

//查找指定书籍
void Book_Control::LookUp(vector<Book> books)
{
	system("cls");
	cin.ignore();
	cout << "请输入修改书籍的编号" << endl;
	string find_number;
	getline(cin, find_number);
	int max = books.size();
	for (int i = 0; i < max; i++)
	{
		if (books[i].Return_number() == find_number)
		{
			books[i].Output();
			char is_return;
			cout << "输入任意字符返回" << endl;
			cin >> is_return;
			break;
		}
	}
	return;
}

//输出所有书籍信息
void Book_Control::Look_Over(vector<Book> books)
{
	system("cls");
	int max = books.size();
	cout << "所有书籍信息如下" << endl;
	for (int i = 0; i < max; i++)
	{
		books[i].Output();
	}
	char is_return;
	cout << "输入任意字符返回" << endl;
	cin >> is_return;
	return;
}

//保存
void Book_Control::Save(vector<Book> books,string& file_path)
{
	ofstream book_file;
	book_file.open(file_path, ios_base::out | ios_base::trunc);
	int max = books.size();
	for (int i = 0; i < max; i++)
	{
		if (i == (max - 1))
		{
			book_file << books[i].Return_name() << "	" << books[i].Return_author() << "	" << books[i].Return_number();
			break;
		}
		book_file << books[i].Return_name() << "	" << books[i].Return_author() << "	" << books[i].Return_number() << endl;
	}
	book_file.close();
	cout << "保存中......" << endl;
	Sleep(3000);
	return;
}

//空格转下划线
//输入的书名、作者可能含有空格，转为下划线，便于比较查找，以及读取
string Book_Control::Underline_Replace_Space(string str)
{
	string space = " ";
	string underline = "_";
	string::size_type pos = 0;
	string::size_type Space = space.size();
	string::size_type Underline = underline.size();
	while ((pos = str.find(space, pos)) != string::npos)
	{
		str.replace(pos, Space, underline);
		pos += Space;
	}
	return str;
}