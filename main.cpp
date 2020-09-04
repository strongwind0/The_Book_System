#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"Book_Control.h"
using namespace std;
int main()
{
	int Borrower_or_Manager;
	system("cls");
	Book_Control manager_control;
	manager_control.Manager_Control();
	return 0;
}