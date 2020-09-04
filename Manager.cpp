#include "Manager.h"

Manager::Manager(string number, string password)
{
	this->Manager_Number = number;
	this->Manager_Password = password;
	return;
}

string Manager::Return_Numble()
{
	return this->Manager_Number;
}

string Manager::Return_Paaword()
{
	return this->Manager_Password;
}