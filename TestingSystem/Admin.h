#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"

class Admin : public Person
{
public:
	//-----------------------------------------------
	Admin (string newName) : Person (newName)  // pass new name to base constructor
	{
		
	}
	//-----------------------------------------------
	bool adminExists()
	{
		bool result = false;
		return result;
	}
	//-----------------------------------------------
	void addUser()
	{

	}
	//-----------------------------------------------
	void saveUser() // add or update
	{

	}
	//-----------------------------------------------
	void deleteUser()
	{

	}
	//-----------------------------------------------
	// filter by category, by user, by test
	// out can be std::out or text output file stream
	void viewResults(string filter, ostream out) 
	{

	}

	//-----------------------------------------------
	void addCategory()
	{

		ofstream out("Categories.txt", ios::out | ios::app);

		string Category, Description, Professor;

		cout << "New Category: ";
		getline(std::cin, Category, '\n');

		cout << "Description: ";
		getline(std::cin, Description, '\n');

		cout << "Professor: ";
		getline(std::cin, Professor, '\n');

		out << setw(10) << Category << setw(40) << Description << setw(20) << Professor << endl;
		out.close();
	}
	//-----------------------------------------------
	void deleteCategory()
	{

	}
	//-----------------------------------------------
	void saveCategory()
	{

	}
	//-----------------------------------------------
	void addQuestion() // must also add right answer
	{

	}
	//-----------------------------------------------
	void saveQuestion() // must also add right answer
	{

	}
	//-----------------------------------------------
	void deleteQuestion()
	{

	}
	//-----------------------------------------------
private:

}; // end class Admin

#endif