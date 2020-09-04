#include "Book.h"

#include<iostream>
using namespace std;

Book::Book(string name, string author, string number)	//¹¹ÔìÆ÷
{
	this->Book_Name = name;
	this->Book_Author = author;
	this->Book_Number = number;
	return;
}

void Book::Output()
{
	cout << "¡¶" << this->Book_Name << "¡·		" << this->Book_Author << "		" << this->Book_Number << endl;
	return;
}

void Book::Motify_Name(string name)
{
	this->Book_Name = name;
	return;
}

void Book::Motify_Author(string author)
{
	this->Book_Author = author;
	return;
}

void Book::Motify_Number(string number)
{
	this->Book_Number = number;
	return;
}

string Book::Return_name()
{
	return this->Book_Name;
}

string Book::Return_author()
{
	return this->Book_Author;
}

string Book::Return_number()
{
	return this->Book_Number;
}
