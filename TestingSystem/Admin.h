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