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
	string Grade;
	string TotalQuestions;
	string CorrectAnswers;

public:
	static const int maxTestIDLength = 10;
	static const int maxUserIDLength = 10;
	static const int maxGradeLength = 10;
	static const int maxTotalQuestionsLength = 10;
	static const int maxCorrectAnswersLength = 10;
	//-----------------------------------------------
	Test() :Entity("Tests.txt")
	{
		addColumn("TestID", maxTestIDLength, true);
		addColumn("UserID", maxUserIDLength);
		addColumn("Grade", maxGradeLength);
		addColumn("TotalQuestions", maxTotalQuestionsLength);
		addColumn("TorrectAnswers", maxCorrectAnswersLength);
	}
	//-----------------------------------------------
	void setTestID(string testID)
	{
		this->TestID = testID;
		padRight(this->TestID, maxTestIDLength);
	}
	//-----------------------------------------------
	void setUserID(string UserID)
	{
		this->UserID = UserID;
		padRight(this->UserID, maxUserIDLength);
	}
	//-----------------------------------------------
	void setGrade(string Grade)
	{
		this->Grade = Grade;
		padRight(this->Grade, maxGradeLength);
	}
	//-----------------------------------------------
	void setTotalQuestions(string TotalQuestions)
	{
		this->TotalQuestions = TotalQuestions;
		padRight(this->TotalQuestions, maxTotalQuestionsLength);
	}
	//-----------------------------------------------
	void setCorrectAnswers(string CorrectAnswers)
	{
		this->CorrectAnswers = CorrectAnswers;
		padRight(this->CorrectAnswers, maxCorrectAnswersLength);
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
		string userID = user->getUserID();

		// запросить идентификатор теста и прочитать его с клавиатуры пользователя
		cin.ignore();
		string testID = promptColumnValue("TestID");

		cout << "User " << userID << " is starting test " << testID << endl;

		// создать пустые векторы для вопросов
		Question * tempQuestion = new Question();
		vector <string> questionRecords;
		tempQuestion->readRecords(testID, "TestID", questionRecords);

		// создать пустые векторы для ответов
		Answer * rightAnswer = new Answer("RightAnswers.txt");

		Answer * studentAnswer = new Answer("StudentAnswers.txt");
		vector <string> answers;

		string questionId, studentVariant, studentAnswerString, answerID, answerText, isCorrect;

		string grade;
		int questionCount = 0; // счетчик вопросов
		int correctAnswerCount = 0;
		string correctAnswerString = "yes";
		padRight(correctAnswerString, maxCorrectAnswersLength);

		// от 0 до конца вектора questionRecords
		for (questionCount; questionCount < (int)(questionRecords.size()); questionCount++)
		{
			questionId = tempQuestion->getValue(questionRecords[questionCount], "QuestionID");
			// clear старые ответы
			answers.clear();
			// прочитать все 4 ответа на этот вопрос
			rightAnswer->readRecords(questionId, "QuestionID", answers);

			// отобразить вопрос на экране
			cout << tempQuestion->getValue(questionRecords[questionCount], "QuestionText") << endl;

			// вывести на экран 4 варианта ответа
			for (int answerIndex = 0; answerIndex < (int)(answers.size()); answerIndex++)
			{
				cout << studentAnswer->getValue(answers[answerIndex], "Variant")
					<< " " << studentAnswer->getValue(answers[answerIndex], "AnswerText") << endl;
			}

			//прочитать ответ студента
			cout << "Enter a, b, c, or d" << endl;
			cin >> studentVariant;

			studentAnswerString = studentAnswer->chosenAnswer(studentVariant, answers);
			answerID = studentAnswer->getValue(studentAnswerString, "AnswerID");
			answerText = studentAnswer->getValue(studentAnswerString, "AnswerText");
			isCorrect = studentAnswer->getValue(studentAnswerString, "IsCorrect");

			if (isCorrect.compare(correctAnswerString) == 0)
				correctAnswerCount++;

			studentAnswer->saveAnswers(answerID, userID, questionId, studentVariant, isCorrect, answerText);
		}

		saveTest(testID, userID, calculateGrade(questionCount, correctAnswerCount), to_string(questionCount), to_string(correctAnswerCount));

		cout << "Finished test. You may continue this test later"
			<< endl << "if you have unanswered questions." << endl;
	}
	//-----------------------------------------------
	string calculateGrade(int totalQuestions, int totalCorrectA)
	{
		double pointsPerQuestion = (double)12 / totalQuestions;
		int result = (int)pointsPerQuestion * totalCorrectA;
		return std::to_string(result);
	}
	//-----------------------------------------------
	void saveTest(string TestID, string UserID, string Grade, string TotalQuestions, string CorrectAnswers)
	{
		cout << "Saving test..." << endl;

		fstream file(getFileName(), ios::out | ios::app | ios::ate);
		string line = "";

		setTestID(TestID);
		line += this->TestID;
		setUserID(UserID);
		line += this->UserID;
		setGrade(Grade);
		line += this->Grade;
		setTotalQuestions(TotalQuestions);
		line += this->TotalQuestions;
		setCorrectAnswers(CorrectAnswers);
		line += this->CorrectAnswers;
		line += "\n";

		file << line;
		file.close();
		cout << "Test saved" << endl << line << endl;
	}
	//-----------------------------------------------
	void continueTest(Person * user)
	{
		cout << "Continuing Test..." << endl;

		string userID = user->getUserID();

		// запросить идентификатор теста и прочитать его с клавиатуры пользователя
		cin.ignore();
		string testID = promptColumnValue("TestID");

		cout << "User " << userID << " is Continuing test " << testID << endl;

		// создать пустые векторы для вопросов
		Question * tempQuestion = new Question();
		vector <string> questionRecords;
		tempQuestion->readRecords(testID, "TestID", questionRecords);

		// создать пустые векторы для ответов
		Answer * rightAnswer = new Answer("RightAnswers.txt");

		Answer * studentAnswer = new Answer("StudentAnswers.txt");
		vector <string> answers;

		string questionId, studentVariant, studentAnswerString, answerID, answerText, isCorrect;

		string grade;
		int questionCount = 0; // счетчик вопросов
		int correctAnswerCount = 0;
		string correctAnswerString = "yes";
		padRight(correctAnswerString, maxCorrectAnswersLength);

		vector<string> existingAnswers;
		vector<string> answerKeys;
		answerKeys.push_back(userID);
		vector<string> answerColumnNames;
		answerColumnNames.push_back("UserID");
		answerColumnNames.push_back("QuestionID");

		// от 0 до конца вектора questionRecords
		for (questionCount; questionCount < (int)(questionRecords.size()); questionCount++)
		{
			questionId = tempQuestion->getValue(questionRecords[questionCount], "QuestionID");

			// добавить ID текущего вопроса в вектор ключей
			
			answerKeys.push_back(questionId);
			existingAnswers.clear();
			studentAnswer->readRecords(answerKeys, answerColumnNames, existingAnswers);
			// удалить ID текущего вопроса из вектора ключей, потому что это изменит следующий повтор цикла
			answerKeys.pop_back();

			// display the question on the screen
			cout << tempQuestion->getValue(questionRecords[questionCount], "QuestionText") << endl;

			if (existingAnswers.size() > 0)
			{
				cout << "This question was already answered. Please, answer the next question." << endl;
				continue;
			}

			// clear old answers
			answers.clear();
			// read all 4 answers for this questions
			rightAnswer->readRecords(questionId, "QuestionID", answers);


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

			if (isCorrect.compare(correctAnswerString) == 0)
				correctAnswerCount++;

			studentAnswer->saveAnswers(answerID, userID, questionId, studentVariant, isCorrect, answerText);

		}

		saveTest(testID, userID, calculateGrade(questionCount, correctAnswerCount), to_string(questionCount), to_string(correctAnswerCount));

		cout << "Finished test. You may continue this test later"
			<< endl << "if you have unanswered questions." << endl;
	}
	//-----------------------------------------------
	void checkStatistics(Person * user)
	{
		cout << "Checking Statistics..." << endl;

		string userID = user->getUserID();

		// ask for test id and read it from user's keyboard input
		cin.ignore();
		string testID = promptColumnValue("TestID");

		cout << "User " << userID << " is checking test results" << testID << endl;

		vector<string> keys;
		keys.push_back(testID);
		keys.push_back(userID);

		vector<string> ColumnNames;
		ColumnNames.push_back("TestID");
		ColumnNames.push_back("UserID");

		vector<string> studentAnswers;
		vector<string> testResults;
		vector<string> questions;

		// read Tests.txt
		this->readRecords(keys, ColumnNames, testResults);

		// read Questions.txt
		Question * question = new Question();
		vector<string> qColNames;
		qColNames.push_back("TestID");
		vector<string> qKeys;
		qKeys.push_back(testID);

		question->readRecords(qKeys, qColNames, questions);

		Answer * studentAnswer = new Answer("StudentAnswers.txt");
		vector<string> aColNames;
		aColNames.push_back("UserID");
		aColNames.push_back("QuestionID");
		vector<string> aKeys;

		// show test result
		this->showColumns();
		cout << testResults[0] << endl << endl;

		for (int i = 0; i < (int)(questions.size()); i++)
		{
			question->showColumns();
			cout << questions[i] << endl;

			aKeys.clear();
			aKeys.push_back(userID);
			aKeys.push_back(question->getValue(questions[i], "QuestionID"));

			studentAnswers.clear();
			studentAnswer->readRecords(aKeys, aColNames, studentAnswers);

			studentAnswer->showColumns();

			if (studentAnswers.size()>0)
			{
				cout << studentAnswers[0] << endl;
			}
			else
			{
				cout << "This question was not answered" << endl;
			}

			cout << endl;
		}

		cout << endl;
	}
	//-----------------------------------------------


}; // end class Test

#endif