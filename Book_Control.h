#include"Book.h"
#include"Manager.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
class Book_Control
{
public:
	Book_Control(void) {};
	bool load(string& name, string& password);					//��¼
	void Manager_Control();										//Manager�Ĳ���
	void Manager_Main_Menu();									//Ŀ¼
	bool is_File_Empty(string& file_path);						//�ļ��Ƿ�Ϊ��
	void Creat(vector<Book>& books);							//����
	void Motify(vector<Book>& books);							//�޸�
	void Delete(vector<Book>& books);							//ɾ��
	void LookUp(vector<Book> books);							//����
	void Look_Over(vector<Book> books);							//��������鼮��Ϣ
	string Underline_Replace_Space(string str);					//�»����滻�ո�
	void Save(vector<Book> books,string& file_path);			//����
};