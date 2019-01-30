#ifndef TEST_H
#define TEST_H

#include <fstream>

class Test 
{
public:
	//-----------------------------------------------
	Test () 
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
		// 
		/*
			Оценивание нужно вести на основании 12 балльной системы, 
			привязанной к количеству вопросов теста.
		*/
		return true;
	}
	//-----------------------------------------------
	void showTestResult()
	{
		/*
		После сдачи теста гость видит результат тестирования, 
		количество правильно отвеченных вопросов, процент правильных ответов и полученную оценку.
		*/
	}
	//-----------------------------------------------
private:
	
	string testID; // aDerg42315gbd

}; // end class Test

#endif