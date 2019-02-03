#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

#include "Entity.h"

class Subject : public Entity
{
private:
	string SubjectID;
	string Description;
	string CategoryID;
	
public:
	static const int maxSubjectIDLength = 10;
	static const int maxCategoryIDLength = 10;
	static const int maxDescriptionLength = 40;
	//-----------------------------------------------
	Subject() : Entity("Subjects.txt")
	{
		addColumn("SubjectID", maxSubjectIDLength, true);
		addColumn("CategoryID", maxCategoryIDLength);
		addColumn("Description", maxDescriptionLength);
	}
	//-----------------------------------------------
	void setCategoryID(string CategoryID)
	{
		this->CategoryID = CategoryID;
	}
	//-----------------------------------------------
	void setSubjectID(string SubjectID)
	{
		this->SubjectID = SubjectID;
	}
	//-----------------------------------------------
	void setDescription(string Description)
	{
		this->Description = Description;
	}
	//-----------------------------------------------
	string getSubjectID()
	{
		return SubjectID;
	}
	//-----------------------------------------------
	string getDescription() 
	{
		return Description;
	}
	//-----------------------------------------------
	string getCategoryID()
	{
		return this->CategoryID;
	}
	//-----------------------------------------------
};

#endif