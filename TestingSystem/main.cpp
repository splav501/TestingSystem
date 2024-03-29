#include "Test.h"

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
	Tests,
	Users,
	CorrectAnswers,
	StudentAnswers
};
//-----------------------------------------------
enum fileMaintenanceMenuOptions // CRUD  C-create R-read U-update D-delete
{
	ExitfileMaintenance,
	Create,
	Read,
	Update,
	Delete,
	List
};
//-----------------------------------------------
bool isAdmin(Person * person)
{
	string tmpusr = "admin";
	person->padRight(tmpusr, person->getColumn("UserID")->getLength());
	bool result = false;
	int isAdmin = person->getUserID().compare(tmpusr);
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
			switch (choice)
					case MenuOptions::LogIn:
					case MenuOptions::Register:

				valid = true;
		}
		else
		{
			if ( ! isAdmin(person))
			
				switch (choice)
					case MenuOptions::StartTest:
					case MenuOptions::ContinueTest:
					case MenuOptions::CheckStatistics:

					valid = true;
			
			else
			
				switch (choice)
					case MenuOptions::Categories:
					case MenuOptions::Questions:
					case MenuOptions::Subjects:
					case MenuOptions::Tests:
					case MenuOptions::Users:
					case MenuOptions::CorrectAnswers:
					case MenuOptions::StudentAnswers:
						valid = true;
			
		}
	}
	return valid;
}
//-----------------------------------------------
int showfileMaintenanceMenu(string flname)
{
	int choice = 0;
	bool choiceOK = false;
	while (! choiceOK) 
	{
		cout << endl
			 << "1 - Exit" << endl
			 << "2 - Create [new      record  in " << flname << "]" << endl
			 << "3 - Read   [existing record  in " << flname << "]" << endl
			 << "4 - Update [existing record  in " << flname << "]" << endl
			 << "5 - Delete [existing record  in " << flname << "]" << endl
			 << "6 - List   [all      records in " << flname << "]" << endl;

		cin >> choice;
		choice -= 1; //���� �� ������ ����, ������� �������� ���������� 1

		if (choice == MenuOptions::Exit)
		{
			choiceOK = true;
			break;
		}

		switch (choice)
		{
			case fileMaintenanceMenuOptions::ExitfileMaintenance:
			case fileMaintenanceMenuOptions::Create:
			case fileMaintenanceMenuOptions::Read:
			case fileMaintenanceMenuOptions::Update:
			case fileMaintenanceMenuOptions::Delete:
			case fileMaintenanceMenuOptions::List:
				choiceOK = true;
				break;
			default:
				choiceOK = false;
				break;
		}
	}
	return choice;
}
//-----------------------------------------------
int showMenu(Person* person)
{
	int choice = 0;
	while (true)
	{
		cout << endl;
		if ( ! person->isLoggedIn() )
			cout << "1 - Exit" << endl
				 << "2 - Log in" << endl
				 << "3 - Register" << endl;
		else
		{
			cout << "1 - Exit" << endl;
			
			if ( ! isAdmin(person)) 
				cout << "4 - Start Test" << endl
					 << "5 - Continue Test" << endl
					 << "6 - Check Statistics" << endl;
			else
				cout << "7 - Categories" << endl
					 << "8 - Subjects" << endl
					 << "9 - Questions" << endl
					 << "10- Tests" << endl
					 << "11- Users" << endl
					 << "12- Correct Answers" << endl
					 << "13- Student Answers" << endl;
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
void fileMaintenance(Entity * entity)
{
	int fileMaintenanceChoice = -1;
	string id;
	string colName;
	string newVal;
	
	Column * keyCol = entity->getKeyColumn();
	string keyDescription = "" ;

	if (keyCol)
		keyDescription = keyCol->getName();
	else
		keyDescription = "ID";
	vector<string> readResults;

	while (fileMaintenanceChoice != fileMaintenanceMenuOptions::ExitfileMaintenance)
	{
		readResults.clear();

		fileMaintenanceChoice = showfileMaintenanceMenu(entity->getFileName());

		switch (fileMaintenanceChoice)
		{
		case fileMaintenanceMenuOptions::Create:
			
			entity->createRecord(); // ����������� ����� ������ ������ � ��������� ��, �� �� ��������� �� � ������
			break;

		case fileMaintenanceMenuOptions::Read:
			
			cout << "Identify the record to display:" << endl;
			
			cin.ignore();
			id = entity->promptColumnValue(keyDescription);
			
			entity->readRecords(id, entity->getKeyColumn()->getName(), readResults);
			
			entity->showVector(readResults);

			break;

		case fileMaintenanceMenuOptions::Update:
			
			cout << "Identify the record to update:" << endl;

			cin.ignore();
			id = entity->promptColumnValue(keyDescription);

			entity->showColumns();

			entity->readRecords(id, entity->getKeyColumn()->getName(), readResults);
			
			entity->showVector(readResults);

			cout << endl << "Enter column name where data will be updated" << endl;
			cin >> colName;

			if (! entity->getColumn(colName))
			{
				cout << "Invalid column name " << colName << endl;
				break;
			}

			cout << "Provide new value:" << endl;

			cin.ignore();
			newVal = entity->promptColumnValue(colName);

			entity->updateRecord(id, colName, newVal);

			break;

		case fileMaintenanceMenuOptions::Delete:

			cin.ignore();
			id = entity->promptColumnValue(keyDescription);

			entity->deleteRecord(id);

			break;

		case fileMaintenanceMenuOptions::List:
			
			entity->displayFile();
			break;
		
		default:
			break;
		}
	}
}
//----------------------------------------------
int main()
{
	setlocale(LC_ALL,"Russian");
	
	int menuChoice = -1;
	Person * currentUser = new Person();
	
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
				currentTest->startTest(currentUser);
				break;

			case MenuOptions::ContinueTest:

				if ( currentTest == NULL)
					currentTest = new Test();

				currentTest->continueTest(currentUser);
				break;

			case MenuOptions::CheckStatistics:

				if (currentTest == NULL)
					currentTest = new Test();

				currentTest->checkStatistics(currentUser);
				break;

			case MenuOptions::Categories:
				fileMaintenance(new Category());
				break;

			case MenuOptions::Questions:
                fileMaintenance(new Question());
			    break;

			case MenuOptions::Subjects:
                fileMaintenance(new Subject());
			    break;

			case MenuOptions::Tests:
                fileMaintenance(new Test());
			    break;

			case MenuOptions::Users:
				fileMaintenance(new Person());
			    break;
			case MenuOptions::CorrectAnswers:
				fileMaintenance(new Answer("RightAnswers.txt"));
				break;

			case MenuOptions::StudentAnswers:
				fileMaintenance(new Answer("StudentAnswers.txt"));
				break;

			case MenuOptions::Exit:
			default:

				break;
		}
	}
	return 0;
}
//-----------------------------------------------

