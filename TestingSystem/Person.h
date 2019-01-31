#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>


#include <cctype>
#include <locale>

using namespace std;

class Person 
{
public:



	// trim from start (in place)
	static inline void ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
			return !std::isspace(ch);
		}));
	}

	// trim from end (in place)
	static inline void rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(std::string &s) {
		ltrim(s);
		rtrim(s);
	}

	// trim from start (copying)
	static inline std::string ltrim_copy(std::string s) {
		ltrim(s);
		return s;
	}

	// trim from end (copying)
	static inline std::string rtrim_copy(std::string s) {
		rtrim(s);
		return s;
	}

	// trim from both ends (copying)
	static inline std::string trim_copy(std::string s) {
		trim(s);
		return s;
	}

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

	string * readCategory(string cat)
	{
		string * result = new string[3];
		result[0];// = "\0";
		result[1];//; = "\0";
		result[2];// = "\0";

		ifstream in("Categories.txt");
		
		char * Category = new char[10];  
		char * Description = new char[40]; 
		char * Professor = new char[20];

		while (!in.eof()) {
			
			in.read(Category, 10);

			string categ (Category);
			string descr (Description);
			string prof (Professor);

			in.read(Description, 40);
			in.read(Professor, 21);

			categ = trim_copy(categ);
			descr = trim_copy(descr);
			prof = trim_copy(prof);

			if (cat == categ) {
				result[0] = categ;
				result[1] = descr;
				result[2] = prof;
			}
		}
		in.close();
		return result;
	}
	//-----------------------------------------------
	void readAllCategory()
	{

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