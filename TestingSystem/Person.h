#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include <cctype>
#include <locale>

using namespace std;

class Person 
{
public:
	//-----------------------------------------------
	Person (string newName)
	{
		this->loggedIn = false;
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
		this->name = this->truncate(newName, this->maxNameLength);
	}
	//-----------------------------------------------
	string getPhone()
	{
		return this->name;
	}
	//-----------------------------------------------
	void setPhone(string newPhone)
	{
		this->phone = this->truncate(newPhone, this->maxPhoneLength);
	}
	//-----------------------------------------------
	string getAddress()
	{
		return addr;
	}
	//-----------------------------------------------
	void setAddress(string newAddress)
	{
		this->addr = this->truncate(newAddress, this->maxAddressLength);
	}
	//-----------------------------------------------
	string truncate (string s, int len)
	{
		return s.substr(0, min(len, (int) (s.length()) ));
	}
	//-----------------------------------------------
	bool login()
	{
		string _userID; 
		string _password;
		string userRecord;
		string truePassword;
		bool authenticated = false;
		while (true) 
		{ 
			cout << "User ID [or 'exit']: ";

			cin >> _userID;
			if (_userID.compare("exit") == 0)
				break;

			cout << "Password [or 'exit']: ";

			cin >> _password;
			if (_password.compare("exit") == 0)
				break;

			userRecord = this->readUser(_userID);

			if (userRecord.empty())
			{
				cout << "User "<< _userID <<" not found." << endl;
			}
			else
			{
				truePassword = userRecord.substr(20,Person::maxPasswordLength);
				padRight(_password, Person::maxPasswordLength);

				if (_password.compare(truePassword) == 0)
				{
					int position = 0;

					this->setUserID(_userID);
					position += Person::maxUserIDLength;

					this->setPassword(userRecord.substr(position,Person::maxPasswordLength));					
					position += Person::maxPasswordLength;

					this->setName(userRecord.substr(position,Person::maxNameLength));
					position += Person::maxNameLength;

					this->setAddress(userRecord.substr(position, Person::maxAddressLength));
					position += Person::maxAddressLength;

					this->setPhone(userRecord.substr(position, Person::maxPhoneLength));

					this->setLoggedIn(true);
					authenticated = this->isLoggedIn();

					break;
				}
			}
		}
		
		return authenticated;
	}
	//-----------------------------------------------
	bool registerPerson()
	{
		bool result = true;

		ofstream out("Users.txt", ios::out | ios::app);

		string Category, Description, Professor;

		cout << "New Category: ";
		getline(cin, Category, '\n');

		cout << "Description: ";
		getline(cin, Description, '\n');

		cout << "Professor: ";
		getline(cin, Professor, '\n');

		out << setfill(' ') << left 
			<< setw(10) << Category 
			<< setw(40) << Description 
			<< setw(20) << Professor << endl;
		
		out.close();

		return result;
	}
	//-----------------------------------------------
	void padRight(string &str, const size_t num, const char paddingChar = ' ')
	{
		if(num > str.size())
			str.insert(str.end(), num - str.size(), paddingChar);
	}
	//-----------------------------------------------
	string readUser(string user)
	{
		return readByKey("Users.txt", user, Person::maxUserIDLength);
	}
	//-----------------------------------------------
	string readCategory(string category)
	{
		return readByKey("Categories.txt", category, 10);
	}
	//-----------------------------------------------
	string readByKey(string flname, string key, int keyLength)
	{
		string result = "";
		string currentKey;
		string line;
		
		ifstream in(flname);

		while ( getline ( in, line, '\n' ) )
		{
			currentKey = line.substr(0,keyLength);
			
			this->padRight(key, keyLength);
			
			if ( currentKey.compare(key) == 0 )
			{
				result = line;
				break;
			}
		}
		
		in.close();
		return result;
	}
	//-----------------------------------------------
	void readAllCategories(vector<string>& collection)
	{
		readAll("Categories.txt", collection);
	}
	//-----------------------------------------------
	void readAll(string flname, vector<string>& collection)
	{
		string line;
		ifstream in(flname);
		while ( getline ( in, line, '\n' ) )
			collection.insert(collection.end(), line);
	}
	//-----------------------------------------------
	bool isLoggedIn()
	{
		return this->loggedIn;
	}
	//-----------------------------------------------
	void setLoggedIn(bool logdin)
	{
		this->loggedIn = logdin;
	}
	//-----------------------------------------------
	string getUserID()
	{
		return this->userID;
	}
	//-----------------------------------------------
	void setUserID(string usrid)
	{
		this->userID = this->truncate(usrid, Person::maxUserIDLength);
	}
	//-----------------------------------------------
	string getPassword()
	{
		return this->userID;
	}
	//-----------------------------------------------
	void setPassword(string _password)
	{
		this->password = this->truncate(_password,Person::maxPasswordLength);
	}
	//-----------------------------------------------
private:
	string userID; 
	static const int maxUserIDLength = 20;

	string name;
	static const int maxNameLength = 40;

	string addr;
	static const int maxAddressLength = 40;
	
	string phone;
	static const int maxPhoneLength = 20;

	string password;
	static const int maxPasswordLength = 30;

	bool loggedIn;
}; // end class Person

#endif