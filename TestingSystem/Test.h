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
	void readStudentAnswers()
	{
		// read answers from file StudentAnswers.txt
	}
	//-----------------------------------------------
	void readCorrectAnswers()
	{
		// read answers from file StudentAnswers.txt
	}
	//-----------------------------------------------
	void saveTestResult() // create new OR update existing
	{
		// write answers to file StudentAnswers.txt
	}
	//-----------------------------------------------
	bool checkTestResult()
	{
		// call function readTestResult() 
		return true;
	}
	//-----------------------------------------------
	void showTestResult()
	{
	}
	//-----------------------------------------------
private:
	
	string testID;

}; // end class Test

#endif