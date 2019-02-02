#ifndef TEST_H
#define TEST_H

#include "Entity.h"

class Test : public Entity
{
public:
	//-----------------------------------------------
	Test () : Entity("Tests.txt")
	{
		
	}
	//-----------------------------------------------
	bool checkTestResult()
	{
		// call function readTestResult() 

		// read student answers

		// read correct answers
		
		// compare student answers with correct answers

		// write test result to Tests.txt

		return true;
	}
	//-----------------------------------------------
private:
	
	string testID;
	string userID;
	string grade;
	string date;

}; // end class Test

#endif