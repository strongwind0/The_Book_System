#include "Book_Control.h"
#include"Manager.h"
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

//��¼
bool Book_Control::load(string& name, string& password)
{
	cout << "�˺ţ�";
	getline(cin, name);
	cout << "���룺";
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
				cout << "��½�ɹ���" << endl;
				Sleep(2000);
				return true;
			}
			else
			{
				cout << "�û������������" << endl;
				Sleep(3000);
				return false;
			}
		}
	}
}

//���̿���
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
		cout << "��ȡ��......"<<endl;
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
		cout << "�ļ�Ϊ�գ�������������" << endl;
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
		case 1:										//���鼮¼��
		{
			Creat(books);
			break;
		}
		case 2:										//�޸��鼮
		{
			Motify(books);
			break;
		}
		case 3:										//ɾ���鼮
		{
			Delete(books);
			break;
		}
		case 4:										//�����鼮
		{
			LookUp(books);
			break;
		}
		case 5:										//�鿴�����鼮
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
			cout << "�����������������" << endl;
			Sleep(3000);
			continue;
		}
		}
	}
	system("cls");
	cout << "����ɹ��������˳�....." << endl;
	system("cls");
	cout << "�˳����" << endl; 
	return;
	
}

//Ŀ¼
void Book_Control::Manager_Main_Menu()
{
	cout << "��ѡ�����" << endl;
	cout << "1.�����鼮" << endl;
	cout << "2.�޸��鼮" << endl;
	cout << "3.ɾ���鼮" << endl;
	cout << "4.�����鼮" << endl;
	cout << "5.�鿴�鼮" << endl;
	cout << "0.�˳�" << endl;
	cout << "��ѡ��";
	return;
}

//�жϴ���鱾���ļ��Ƿ�Ϊ��
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

//��������
void Book_Control::Creat(vector<Book>& books)
{
	system("cls");
	cin.ignore();
	string name;
	string author;
	string number;
	cout << "�������������������ߡ���ţ�һ������һ������" << endl;
	getline(cin, name);
	getline(cin, author);
	getline(cin, number);
	Book new_book(name, author, number);
	books.push_back(new_book);
	cout << "�鼮¼��ɹ�" << endl;
	Sleep(3000);
	return;
}

//�޸��鼮
void Book_Control::Motify(vector<Book>& books)
{
	system("cls");
	cin.ignore();
	cout << "�������޸��鼮�ı��" << endl;
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
			cout << "�������������������ߡ���ţ�һ������һ������" << endl;
			getline(cin, new_name);
			new_name = Underline_Replace_Space(new_name);
			getline(cin, new_author);
			new_author = Underline_Replace_Space(new_author);
			getline(cin, new_number);
			books[i].Motify_Author(new_author);
			books[i].Motify_Name(new_name);
			books[i].Motify_Number(new_number);
			books[i].Output();
			cout << "�޸����" << endl;
			Sleep(3000);
			break;
		}
	}
	return;
}

//ɾ���鼮
void Book_Control::Delete(vector<Book>& books)
{
	system("cls");
	cin.ignore();
	cout << "�������޸��鼮�ı��" << endl;
	string find_number;
	getline(cin, find_number);
	int max = books.size();
	for (int i = 0; i < max; i++)
	{
		if (books[i].Return_number() == find_number)
		{
			books[i].Output();
			cout << "ȷ��ɾ��������1" << endl;
			int is_sure = 0;
			cin >> is_sure;
			if (is_sure == 1)
			{
				books.erase(books.begin() + i);
				cout << "ɾ�����" << endl;
			}
			else
			{
				cout << "ɾ��ȡ��" << endl;
			}
			Sleep(3000);
			break;
		}
	}
	return;
}

//����ָ���鼮
void Book_Control::LookUp(vector<Book> books)
{
	system("cls");
	cin.ignore();
	cout << "�������޸��鼮�ı��" << endl;
	string find_number;
	getline(cin, find_number);
	int max = books.size();
	for (int i = 0; i < max; i++)
	{
		if (books[i].Return_number() == find_number)
		{
			books[i].Output();
			char is_return;
			cout << "���������ַ�����" << endl;
			cin >> is_return;
			break;
		}
	}
	return;
}

//��������鼮��Ϣ
void Book_Control::Look_Over(vector<Book> books)
{
	system("cls");
	int max = books.size();
	cout << "�����鼮��Ϣ����" << endl;
	for (int i = 0; i < max; i++)
	{
		books[i].Output();
	}
	char is_return;
	cout << "���������ַ�����" << endl;
	cin >> is_return;
	return;
}

//����
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
	cout << "������......" << endl;
	Sleep(3000);
	return;
}

//�ո�ת�»���
//��������������߿��ܺ��пո�תΪ�»��ߣ����ڱȽϲ��ң��Լ���ȡ
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