#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Test.h"

#include <list>

class Student : public Person
{
public:
	//-----------------------------------------------
	Student () : Person () 
	{
		// initialize empty list of classes
		this->tests = new list<Test *>();
	}
	//-----------------------------------------------
	void startTest()
	{
		cout << "Starting Test" << endl;
	}
	//-----------------------------------------------
	void continueTest()
	{
		cout << "Continuing Test" << endl;
	}
	//-----------------------------------------------
	void checkStatistics()
	{
		cout << "Checking Statistics" << endl;
	}
	//-----------------------------------------------
private:
	list <Test *> * tests;

}; // end class Student

#endif