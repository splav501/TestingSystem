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
			���������� ����� ����� �� ��������� 12 �������� �������, 
			����������� � ���������� �������� �����.
		*/
		return true;
	}
	//-----------------------------------------------
	void showTestResult()
	{
		/*
		����� ����� ����� ����� ����� ��������� ������������, 
		���������� ��������� ���������� ��������, ������� ���������� ������� � ���������� ������.
		*/
	}
	//-----------------------------------------------
private:
	
	string testID; // aDerg42315gbd

}; // end class Test

#endif