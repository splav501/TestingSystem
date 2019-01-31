#include <string>
#include <iostream>
#include <fstream>

#include "Admin.h"
#include "Student.h"

//-----------------------------------------------
enum MenuOptions
{
	Exit,
	LogIn,
	Register,
	StartTest,
	ContinueTest,
	CheckStatistics,
	Categories,
	Subjects,
	Questions,
	Tests
};
//-----------------------------------------------
bool isAdmin(Person * person)
{
	bool result = false;
	int isAdmin = person->getUserID().compare("admin");
	if (isAdmin == 0 )
		result = true;
	return result;
}
//-----------------------------------------------
bool validMainMenuChoice(int choice, Person * person)
{
	bool valid = false;

	if (choice == MenuOptions::Exit )
		valid = true;

	else
	{

		if ( ! person->isLoggedIn() )
		{
			if (choice == MenuOptions::LogIn || choice == MenuOptions::Register )
				valid = true;
		}
		else
		{
			if ( ! isAdmin(person))
			{
				if (choice == MenuOptions::StartTest || choice == MenuOptions::ContinueTest || choice == MenuOptions::CheckStatistics)
					valid = true;
			}
			else
			{
				if (choice == MenuOptions::Categories || choice == MenuOptions::Questions || choice == MenuOptions::Subjects || choice == MenuOptions::Tests)
					valid = true;
			}
		}
	}
	return valid;
}
//-----------------------------------------------
int showMenu(Person* person)
{
	int choice = 0;
	while (true)
	{

		if ( ! person->isLoggedIn() )
			cout << "1 - Exit" << endl
				 << "2 - Log in" << endl
				 << "3 - Register" << endl;
		else
		{
			cout << "1 - Exit" << endl;
			
			if ( ! isAdmin(person)) 
				cout << "4 - Start Test" << endl
					 << "5 - Resume Test" << endl
					 << "6 - Check Statistics" << endl;
			else
				cout << "7 - Categories" << endl
					 << "8 - Subjects" << endl
					 << "9 - Questions" << endl
					 << "10 - Tests" << endl;
		}

		cin >> choice;

		if (validMainMenuChoice(choice - 1, person))
		{
			cout << "Selected " << choice << endl;
			break;
		}
		else
			cout << "Invalid choice" << endl;
	}

	return choice - 1;
}
//-----------------------------------------------
int main()
{
	int menuChoice = -1;
	Person * currentUser = new Person("");
	vector<string> categories;
	
	Test * currentTest = NULL;
	while (menuChoice != MenuOptions::Exit)
	{
		menuChoice = showMenu(currentUser);
		switch (menuChoice)
		{
			case MenuOptions::Register:

				currentUser->registerPerson();
				break;

			case MenuOptions::LogIn:

				currentUser->login();
				break;

			case MenuOptions::StartTest:

				currentTest = new Test();
				((Student *)currentUser)->startTest();
				break;

			case MenuOptions::ContinueTest:

				((Student *)currentUser)->continueTest();
				break;

			case MenuOptions::CheckStatistics:

				((Student *)currentUser)->checkStatistics();
				break;

			case MenuOptions::Exit:
			default:

				break;
		}
	}
	return 0;
}
//-----------------------------------------------

