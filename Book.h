#pragma once
#include<string>
#include<fstream>
using namespace std;
class Book
{
private:
	string Book_Name;		//书名
	string Book_Author;		//作者
	string Book_Number;		//编号
public:
	Book(string name, string author, string number);				//构造书的对象
	void Output();													//输出所有信息		
	void Motify_Name(string name);									//修改书名
	void Motify_Author(string author);								//修改作者
	void Motify_Number(string number);								//修改编号
	string Return_name();											//返回书名
	string Return_author();											//返回作者
	string Return_number();											//返回编号
};
