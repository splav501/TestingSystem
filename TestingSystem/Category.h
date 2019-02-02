#ifndef CATEGORY_H
#define CATEGORY_H

#include "Entity.h"


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
	void setCategoryID(string CategoryID)
	{
		this->CategoryID = CategoryID;
	}
	//-----------------------------------------------
	string getCategoryID()
	{
		return CategoryID;
	}
	//-----------------------------------------------
	void setDescription(string Description)
	{
		this->Description = Description;
	}
	//-----------------------------------------------
	string getDescription()
	{
		return Description;
	}
	//-----------------------------------------------
	void setProfessor(string Professor)
	{
		this->Professor = Professor;
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