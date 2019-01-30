#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Person 
{
public:
	//-----------------------------------------------
	Person (string newName)
	{
		this->setName(newName);
	}
	//-----------------------------------------------
	string getName()
	{
		return this->name;
	}
	//-----------------------------------------------
	void setName(string newName)
	{
		this->name = truncate(newName, this->maxNameLength);
	}
	//-----------------------------------------------
	string getPhone()
	{
		return this->name;
	}
	//-----------------------------------------------
	void setPhone(string newPhone)
	{
		this->phone = truncate(newPhone, this->maxPhoneLength);
	}
	//-----------------------------------------------
	string getAddress()
	{
		return addr;
	}
	//-----------------------------------------------
	void setAddress(string newAddress)
	{
		this->addr = truncate(newAddress, this->maxAddressLength);
	}
	//-----------------------------------------------
	string truncate (string s, int len)
	{
		return s.substr(0, min(len, (int) (s.length()) ));
	}
	//-----------------------------------------------
	bool login()
	{
		return true;
	}
	//-----------------------------------------------
	bool registerPerson()
	{
		bool result = true;

		return result;
	}
	//-----------------------------------------------
private:
	int studentID; 

	string name;
	static const int maxNameLength = 40;

	string addr;
	static const int maxAddressLength = 40;
	
	string phone;
	static const int maxPhoneLength = 20;
}; // end class Person

#endif