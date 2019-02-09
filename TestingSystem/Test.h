#ifndef TEST_H
#define TEST_H

#include "Entity.h"

#include "Admin.h"
#include "Student.h"
#include "Category.h"
#include "Subject.h"
#include "Question.h"
#include "Answer.h"

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
	void startTest(Person * user)
	{
		string studentID = user->getUserID();

		// ask for test id and read it from user's keyboard input
		cin.ignore();
		string testID = promptColumnValue("TestID");

		cout << "User " << studentID << " is starting test " << testID << endl;

		// create a blank vectors for questions
		Question * tempQuestion = new Question();
		vector <string> questionRecords;
		tempQuestion->readRecords(testID, "TestID", questionRecords);

		// create a blank vectors for answers
		Answer * rightAnswer = new Answer("RightAnswers.txt");

		Answer * studentAnswer = new Answer("StudentAnswers.txt");
		vector <string> answers;

		string questionId, studentVariant, studentAnswerString, answerID, answerText, isCorrect;

		// from 0 to end of vector questionRecords
		for (int i = 0; i < (int)(questionRecords.size()); i++)
		{
			questionId = tempQuestion->getValue( questionRecords[i], "QuestionID");
			// clear old answers
			answers.clear();
			// read all 4 answers for this questions
			rightAnswer->readRecords(questionId, "QuestionID", answers);
		
			// display the question on the screen
			cout << tempQuestion->getValue(questionRecords[i], "QuestionText") << endl;

			// display 4 vartiants of the answer on the screen
			for (int answerIndex = 0; answerIndex < (int)(answers.size()); answerIndex++)
			{
				cout << studentAnswer->getValue(answers[answerIndex], "Variant")
					<< " " << studentAnswer->getValue(answers[answerIndex], "AnswerText") << endl;
			}
			

			// read student answer
			cout << "Enter a, b, c, or d" << endl;
			cin >> studentVariant;

			studentAnswerString = studentAnswer->chosenAnswer(studentVariant, answers);
			answerID = studentAnswer->getValue(studentAnswerString, "AnswerID");
			answerText = studentAnswer->getValue(studentAnswerString, "AnswerText");
			isCorrect = studentAnswer->getValue(studentAnswerString, "IsCorrect");

			studentAnswer->saveAnswers(answerID, studentID, questionId, studentVariant, isCorrect, answerText);
		}

		cout << "Finished test. You may continue this test later" 
			<< endl << "if you have unanswered questions." << endl;
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