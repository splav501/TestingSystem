#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>

#include "Entity.h"

using namespace std;

class Person : public Entity
{
public:
	static const int maxUserIDLength = 20;
	static const int maxPasswordLength = 30;
	static const int maxNameLength = 40;
	static const int maxAddressLength = 40;
	static const int maxPhoneLength = 20;
	//-----------------------------------------------
	Person () : Entity("Users.txt")
	{
		loggedIn = false;
		addColumn("UserID", Person::maxUserIDLength, true);
		addColumn("Password", Person::maxPasswordLength);
		addColumn("UserName", Person::maxNameLength);
		addColumn("Address", Person::maxAddressLength);
		addColumn("Phone", Person::maxPhoneLength);
	}
	//-----------------------------------------------
	string getName()
	{
		return name;
	}
	//-----------------------------------------------
	void setName(string newName)
	{
		name = truncate(newName, maxNameLength);
	}
	//-----------------------------------------------
	string getPhone()
	{
		return name;
	}
	//-----------------------------------------------
	void setPhone(string newPhone)
	{
		phone = truncate(newPhone, maxPhoneLength);
	}
	//-----------------------------------------------
	string getAddress()
	{
		return addr;
	}
	//-----------------------------------------------
	void setAddress(string newAddress)
	{
		addr = truncate(newAddress, maxAddressLength);
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
			cin.ignore();

			_userID = promptColumnValue("UserID");
			_password = promptColumnValue("Password");

			userRecord = readUser(_userID);

			if (userRecord.empty())
			
				cout << "User "<< _userID <<" not found" << endl;
			
			else
			{
				truePassword = userRecord.substr(20,Person::maxPasswordLength);
				padRight(_password, Person::maxPasswordLength);

				if (_password.compare(truePassword) == 0)
				{
					setPerson(userRecord);

					setLoggedIn(true);
					authenticated = isLoggedIn();

					break;
				}
				else
					cout << "Incorrect password" << endl;
			}
		}
		
		if (authenticated)
			cout << "Successfully logged in: "  << getName() << endl;
		else
			cout << "Login failed" << endl;

		return authenticated;
	}
	//-----------------------------------------------
	void setPerson(string userRecord)
	{
		int position = 0;
		vector<string> vals;
		setValues(userRecord, vals);
		setUserID(vals[0]);
		setPassword(vals[1]);
		setName(vals[2]);
		setAddress(vals[3]);
		setPhone(vals[4]);
	}
	//-----------------------------------------------
	bool registerPerson()
	{
		bool result = true;

		fstream out("Users.txt", ios::in | ios::out | ios::app);

		string _userID, _name, _addr, _phone, _password;
		
		cin.ignore();

		while (true)
		{
			_userID = promptColumnValue("UserID");
			
			string adminString = "admin";
			padRight(adminString, getColumn("UserID")->getLength());

			if (_userID.compare(adminString) != 0)
			{
				// OK, because user did NOT choose admin
				break;
			}
			else
			{
				if ( readUser("admin").empty() )
				{
					// OK, because admin account does not exist yet
					break;
				}
				else
				{
					// NOT OK, because admin account already exists, so we stay in the WHILE loop
					cout << "admin account already exists. Use another user id." << endl;
				}
			}
		}

		_password = promptColumnValue("Password");
		_name = promptColumnValue("UserName");
		_addr = promptColumnValue("Address");
		_phone = promptColumnValue("Phone");
		
		string userLine = _userID + _password + _name + _addr + _phone + "\n";
		out << userLine;
		setPerson(userLine);

		out.close();

		setLoggedIn(true);
		result = isLoggedIn();

		cout << _name << ", you have been registered and logged in" << endl;

		return result;
	}

	//-----------------------------------------------
	string readUser(string user)
	{
		return readRecord(user);
	}
	//-----------------------------------------------
	void showUser(string user)
	{
		cout << readUser(user) << endl;
	}
	//-----------------------------------------------
	void readAllUsers(vector<string>& collection)
	{
		readAll(collection);
	}
	//-----------------------------------------------
	void displayUsers()
	{
		displayFile();
	}
	//-----------------------------------------------
	bool isLoggedIn()
	{
		return loggedIn;
	}
	//-----------------------------------------------
	void setLoggedIn(bool logdin)
	{
		loggedIn = logdin;
	}
	//-----------------------------------------------
	string getUserID()
	{
		return userID;
	}
	//-----------------------------------------------
	void setUserID(string usrid)
	{
		userID = truncate(usrid, Person::maxUserIDLength);
	}
	//-----------------------------------------------
	string getPassword()
	{
		return userID;
	}
	//-----------------------------------------------
	void setPassword(string _password)
	{
		password = truncate(_password,Person::maxPasswordLength);
	}
	//-----------------------------------------------
private:
	string userID; 
	string name;
	string addr;
	string phone;
	string password;
	bool loggedIn;
}; // end class Person

#endif