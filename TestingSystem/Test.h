#ifndef TEST_H
#define TEST_H

#include "Entity.h"

class Test : public Entity
{
private:

	string TestID;
	string UserID;
	string CategoryID;
	string SubjectID;
	string Grade;
	string TotalQuestions;
	string CorrectAnswers;

public:
	static const int maxTestIDLength = 10;
	static const int maxUserIDLength = 10;
	static const int maxGradeLength = 10;
	static const int maxCategoryIDLength = 10;
	static const int maxSubjectIDLength = 10;
	static const int maxTotalQuestionsLength = 10;
	static const int maxCorrectAnswersLength = 10;
	//-----------------------------------------------
	Test() :Entity("Test.txt")
	{
		addColumn("TestID", maxTestIDLength, true);
		addColumn("UserID", maxUserIDLength);
		addColumn("CategoryID", maxCategoryIDLength);
		addColumn("SubjectID", maxSubjectIDLength);
		addColumn("Grade", maxGradeLength);
		addColumn("TotalQuestions", maxTotalQuestionsLength);
		addColumn("TorrectAnswers", maxCorrectAnswersLength);
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
	void setTotalQuestions(string TotalQuestions)
	{
		this->TotalQuestions = TotalQuestions;
	}
	//-----------------------------------------------
	void setCorrectAnswers(string CorrectAnswers)
	{
		this->CorrectAnswers = CorrectAnswers;
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
	string getTotalQuestions()
	{
		return TotalQuestions;
	}
	//-----------------------------------------------
	string getCorrectAnswers()
	{
		return CorrectAnswers;
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