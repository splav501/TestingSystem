#include <string>
#include <iostream>
#include <fstream>

#include "Admin.h"
#include "Student.h"
//-----------------------------------------------
enum  MenuOptions
{
	LogIn,
	Register,
	TakeTest,
	ResumeTest,
	CheckStatistics,
	Exit
};
//-----------------------------------------------
void readSubjects()
{
	ifstream inputFile; 
	inputFile.open("Subjects.txt", ios::in);
}
//-----------------------------------------------
bool validMainMenuChoice(string choice)
{
	bool valid = false;
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
		valid = true;

	return valid;
}
//-----------------------------------------------
int showMenu()
{
	string choice = "";

	while (!validMainMenuChoice(choice))
	{
		cout << "1 - Log in" << endl
			<< "2 - Register" << endl
			<< "3 - Take Test" << endl
			<< "4 - Resume Test" << endl
			<< "5 - Check Statistics" << endl
			<< "6 - Exit" << endl;

		cin >> choice;

		if (validMainMenuChoice(choice))

			break;

		else
			cout << "Invalid choice" << endl;

	}

	return atoi(choice.c_str());
}
//-----------------------------------------------
int main()
{
	int menuChoice = 0;
	Person * currentuser = NULL;
	Test * currentTest = NULL;
	do
	{
		menuChoice = showMenu();
		switch (menuChoice)
		{
			case MenuOptions::Register:
				break;
			case MenuOptions::LogIn:
				break;
			case MenuOptions::TakeTest:
				currentuser = new Student("George");
				currentTest = new Test();
				break;
			case MenuOptions::ResumeTest:
				break;
			case MenuOptions::CheckStatistics:
				break;

			case MenuOptions::Exit:
			default:
				break;
		}
	} while (menuChoice != MenuOptions::Exit);
	return 0;
}
//-----------------------------------------------

