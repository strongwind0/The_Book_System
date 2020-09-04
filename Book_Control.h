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
	bool load(string& name, string& password);					//登录
	void Manager_Control();										//Manager的操作
	void Manager_Main_Menu();									//目录
	bool is_File_Empty(string& file_path);						//文件是否为空
	void Creat(vector<Book>& books);							//创建
	void Motify(vector<Book>& books);							//修改
	void Delete(vector<Book>& books);							//删除
	void LookUp(vector<Book> books);							//查找
	void Look_Over(vector<Book> books);							//输出所有书籍信息
	string Underline_Replace_Space(string str);					//下划线替换空格
	void Save(vector<Book> books,string& file_path);			//保存
};