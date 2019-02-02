#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>

#include "Entity.h"

using namespace std;

class Category : public Entity
{
public:
	static const int maxCategoryIDLength = 10;
	static const int maxDescriptionLength = 40;
	static const int maxProfessorLength = 20;
	//-----------------------------------------------
	Category() : Entity("Categories.txt")
	{
		addColumn("CategoryID", maxCategoryIDLength, true);
		addColumn("Description", maxDescriptionLength);
		addColumn("Professor", maxProfessorLength);
	}
	//-----------------------------------------------
	void setCategoryID(string _CategoryID)
	{
		CategoryID = _CategoryID;
	}
	//-----------------------------------------------
	string getCategoryID()
	{
		return CategoryID;
	}
	//-----------------------------------------------
	void setDescription(string _Description)
	{
		Description = _Description;
	}
	//-----------------------------------------------
	string getDescription()
	{
		return Description;
	}
	//-----------------------------------------------
	void setProfessor(string _Professor)
	{
		Professor = _Professor;
	}
	//-----------------------------------------------
	string getProfessor()
	{
		return Professor;
	}
	//-----------------------------------------------
private:
	string CategoryID;
	string Description;
	string Professor;
};
#endif