#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"

class Admin : public Person
{
public:
	//-----------------------------------------------
	Admin () : Person ()  
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
	void viewResults() 
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
	void saveQuestion() 
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