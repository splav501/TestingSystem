#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include "Entity.h"

class Question : public Entity
{
	string QuestionID;
	string TestID;
	string QuestionNumber;
	string QuestionText;

public:
	static const int maxQuestionIDLength = 10;
	static const int maxTestIDLength = 10;
	static const int maxQuestionNumberLength = 10;
	static const int maxQuestionTextLength = 60;
	
	//-----------------------------------------------
	Question() : Entity("Questions.txt")
	{
		addColumn("QuestionID", maxQuestionIDLength, true);
		addColumn("TestID", maxTestIDLength);
		addColumn("QuestionNumber", maxQuestionNumberLength);
		addColumn("QuestionText", maxQuestionTextLength);
	}
		//-----------------------------------------------
		void setQuestionID(string QuestionID)
		{
			this->QuestionID = QuestionID;
		}
		//-----------------------------------------------
		void setTestID(string TestID)
		{
			this->TestID = TestID;
		}//-----------------------------------------------
		void setQuestionNumber(string QuestionNumber)
		{
			this->QuestionNumber = QuestionNumber;
		}
		//-----------------------------------------------
		void setQuestions(string QuestionText)
		{
			this->QuestionText = QuestionText;
		}
		//-----------------------------------------------
		
		string getQuestionID()
		{
			return QuestionID;
		}
		//-----------------------------------------------
		string getTestID()
		{
			return TestID;
		}
		//-----------------------------------------------
		string getQuestionNumber()
		{
			return QuestionNumber;
		}
		//-----------------------------------------------
		string getQuestions()
		{
			return QuestionText;
		}
		//-----------------------------------------------
		bool readQuestions(string testID, vector<string> & questionStrings) {
			bool result = false;
			readRecords(testID, "TestID", questionStrings);
		}
		//-----------------------------------------------
};



#endif