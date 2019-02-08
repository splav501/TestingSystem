#pragma once
#ifndef ANSWER_H
#define ANSWER_H

#include "Entity.h"

class Answer : public Entity
{
private:
	// UserID is blank for CORRECT answers
	// UserID is non-blank for STUDENT answers
	string AnswerID;
	string UserID;
	string QuestionID;
	string Variant;
	string IsCorrect;
	string AnswerText;
public:
	static const int maxAnswerIDLength = 10;
	static const int maxUserIDLength = 10;
	static const int maxQuestionIDLength = 10;
	static const int maxVariantLength = 10;
	static const int maxIsCorrectLength = 10;
	static const int maxAnswerLength = 80;
	//-----------------------------------------------
	Answer(string filename) : Entity(filename) // filename can be "CorrectAnswers.txt" or "StudentAnswers.txt"
	{
		addColumn("AnswerID", maxAnswerIDLength, true);
		addColumn("UserID", maxUserIDLength);
		addColumn("QuestionID", maxQuestionIDLength);
		addColumn("Variant", maxVariantLength);
		addColumn("IsCorrect", maxIsCorrectLength);
		addColumn("AnswerText", maxAnswerLength);
	}
	//-----------------------------------------------
	void setAnswerID(string AnswerID)
	{
		this->AnswerID = AnswerID;
	}
	//-----------------------------------------------
	void setQuestionID(string QuestionID)
	{
		this->QuestionID = QuestionID;
	}
	//-----------------------------------------------
	void setAnswers(string Answers)
	{
		this->AnswerText = Answers;
	}
	//-----------------------------------------------
	void setIsCorrect(string IsCorrect)
	{
		this->IsCorrect = IsCorrect;
	}

	//-----------------------------------------------
	string getAnswerID()
	{
		return AnswerID;
	}
	//-----------------------------------------------
	string getQuestionID()
	{
		return QuestionID;
	}
	//-----------------------------------------------
	string getAnswers()
	{
		return AnswerText;
	}
	string getIsCorrect()
	{
		return this->IsCorrect;
	}
	//-----------------------------------------------

};

#endif