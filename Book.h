#pragma once
#include<string>
#include<fstream>
using namespace std;
class Book
{
private:
	string Book_Name;		//����
	string Book_Author;		//����
	string Book_Number;		//���
public:
	Book(string name, string author, string number);				//������Ķ���
	void Output();													//���������Ϣ		
	void Motify_Name(string name);									//�޸�����
	void Motify_Author(string author);								//�޸�����
	void Motify_Number(string number);								//�޸ı��
	string Return_name();											//��������
	string Return_author();											//��������
	string Return_number();											//���ر��
};
