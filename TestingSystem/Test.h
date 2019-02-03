#ifndef TEST_H
#define TEST_H

#include "Entity.h"

class Test : public Entity
{
private:

	string TestID;
	string UserID;
	string Grade;
	string Date;

public:
	static const int maxTestIDLength = 20;
	static const int maxUserIDLength = 20;
	static const int maxGradeLength = 20;
	static const int maxDateLength = 10;


	//-----------------------------------------------
	Test() :Entity("Test.txt")
	{
		addColumn("TestID", maxTestIDLength, true);
		addColumn("UserID", maxUserIDLength);
		addColumn("Grade", maxGradeLength);
		addColumn("Date", maxDateLength);
	}
	//-----------------------------------------------
	void setTestID(string testID)
	{
		this->TestID = TestID;
	}
	//-----------------------------------------------
	void setUserID(string UserID)
	{
		this->UserID = UserID;
	}
	//-----------------------------------------------
	void setGrade(string Grade)
	{
		this->Grade = Grade;
	}
	//-----------------------------------------------
	void setDate(string Date)
	{
		this->Date = Date;
	}
	//-----------------------------------------------
	string getTestID()
	{
		return TestID;
	}
	//-----------------------------------------------
	string getUserID()
	{
		return UserID;
	}
	//-----------------------------------------------
	string getGrade()
	{
		return Grade;
	}
	//-----------------------------------------------
	string getDate()
	{
		return Date;
	}







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


}; // end class Test

#endif