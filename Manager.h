#pragma once
#include<string>
#include<fstream>
using namespace std;
class Manager
{
private:
	string Manager_Number;
	string Manager_Password;
public:
	Manager(string number, string password);
	string Return_Numble();
	string Return_Paaword();
};

