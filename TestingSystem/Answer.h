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
	// prompts for new record data and saves it, but doesn't load it into memory
	void saveAnswers(string _AnswerID, string _UserID, string _QuestionID, string _Variant, string _IsCorrect, string _AnswerText)
	{
		cout << "Saving answer..." << endl;

		fstream file(getFileName(), ios::out | ios::app | ios::ate);

		string line = "";
		setAnswerID(_AnswerID);
		line += this->AnswerID;
		setUserID(_UserID);
		line += this->UserID;
		setQuestionID(_QuestionID);
		line += this->QuestionID;
		setVariant(_Variant);
		line += this->Variant;
		setIsCorrect(_IsCorrect);
		line += this->IsCorrect;
		setAnswers(_AnswerText);
		line += this->AnswerText;

		line += "\n";

		file << line;
		file.close();
		cout << "Answer saved" << endl << line << endl;
	}
	//-----------------------------------------------
	string chosenAnswer(string variant, vector<string> answers)
	{
		string currentVariant;
		string result = "";
		padRight(variant, maxVariantLength);

		for (int i = 0; i < (int)(answers.size()); i++)
		{
			currentVariant = getValue(answers[i], "Variant");

			if (currentVariant.compare(variant) == 0)
			{
				result = answers[i];
			}
		}
		return result;
	}
	// ---------------------------------------
	void setAnswerID(string AnswerID)
	{
		this->AnswerID = AnswerID;
		padRight(this->AnswerID, maxAnswerIDLength);
	}
	//-----------------------------------------------
	void setUserID(string UserID)
	{
		this->UserID = UserID;
		padRight(this->UserID, maxUserIDLength);
	}
	//-----------------------------------------------
	void setQuestionID(string QuestionID)
	{
		this->QuestionID = QuestionID;
		padRight(this->QuestionID, maxQuestionIDLength);
	}
	//-----------------------------------------------
	void setAnswers(string Answers)
	{
		this->AnswerText = Answers;
		padRight(this->AnswerText, maxAnswerLength);
	}
	//-----------------------------------------------
	void setIsCorrect(string IsCorrect)
	{
		this->IsCorrect = IsCorrect;
		padRight(this->IsCorrect, maxIsCorrectLength);
	}
	//-----------------------------------------------
	void setVariant(string Variant)
	{
		this->Variant = Variant;
		padRight(this->Variant, maxVariantLength);
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
	bool readAnswers(string testID, vector<string> & questionStrings) {
		bool result = false;
		readRecords(testID, "TestID", questionStrings);
	}
	//-----------------------------------------------

};

#endif