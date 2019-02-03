#ifndef COLUMN_H
#define COLUMN_H

#include <string>
#include <iostream>

using namespace std;

class Column
{
public:
	//-----------------------------------------------
	Column(string nm, int ps, int ln, bool key = false)
	{
		setName(nm);
		setPosition(ps);
		setLength(ln);
		setIsKey(key);
	}
	//-----------------------------------------------
	void setIsKey(bool val)
	{
		isKey = val;
	}
	//-----------------------------------------------
	bool getIsKey()
	{
		return isKey;
	}
	//-----------------------------------------------
	bool setName(string _name)
	{
		bool ok = true;
		name = _name;
		return ok;
	}
	//-----------------------------------------------
	string getName()
	{
		return name;
	}
	//-----------------------------------------------
	bool setPosition(int _position)
	{
		bool ok = true;
		if (_position >= 0)
			position = _position;
		else
			cout << "Cannot set column " << name << " position "<< _position << " [negative]" << endl;
		return ok;
	}
	//-----------------------------------------------
	int getPosition()
	{
		return position;
	}
	//-----------------------------------------------
	bool setLength(int _length)
	{
		bool ok = true;
		if (_length >= 0)
			length = _length;
		else
			cout << "Cannot set column " << name << " length "<< _length << " [negative]" << endl;
		return ok;
	}
	//-----------------------------------------------
	int getLength()
	{
		return length;
	}
	//-----------------------------------------------
	bool setColumn(string _name, int _pos, int _wdth)
	{
		bool ok = true;

		if ( ! setName(_name) )
			ok = false;
		if ( ! setPosition(_pos) )
			ok = false;
		if ( ! setLength(_wdth) )
			ok = false;

		return ok;
	}
	//-----------------------------------------------
private:
	string name;
	int position;
	int length;
	bool isKey;
};
#endif