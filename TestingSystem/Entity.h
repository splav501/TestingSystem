#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "Column.h"

using namespace std;

class Entity
{
public:
	//-----------------------------------------------
	Entity(string fname)
	{
		setFileName(fname);
	}
	//-----------------------------------------------
	string truncate(string s, int len)
	{
		return s.substr(0, min(len, (int)(s.length())));
	}
	//-----------------------------------------------
	void padRight(string &str, const size_t num, const char paddingChar = ' ')
	{
		if (num > str.size())
		{
			str.insert(str.end(), num - str.size(), paddingChar);
		}
	}
	//-----------------------------------------------
	string readByKey(string flname, string key, int keyLength)
	{
		string result = "";
		string currentKey;
		string line;

		ifstream in(flname);


		while (getline(in, line, '\n'))
		{
			currentKey = line.substr(0, keyLength);

			padRight(key, keyLength);

			if (currentKey.compare(key) == 0)
			{
				result = line;
				break;
			}
		}

		in.close();
		return result;
	}
	//-----------------------------------------------
	// read records which match ONE search criterion
	bool readRecords(string key, string columnName, vector<string> & records)
	{
		vector<string> keys;
		keys.push_back(key);
		vector<string> columnNames;
		columnNames.push_back(columnName);

		return readRecords(keys, columnNames, records);
	}
	//-----------------------------------------------
	// read records which match MANY search criteria
	bool readRecords(vector<string> keys, vector<string> columnNames, vector<string> & records)
	{
		if (keys.size() != columnNames.size()) {
			cout << "Number of search leys must match number of search columns" << endl;
			return false;
		}

		string currentKey;
		string line;
		bool found = false;

		bool columnValueMatched = true;

		ifstream in(fileName);

		vector<Column *> searchColumns;

		for (int i = 0; i < (int)(columnNames.size()); i++)
		{
			searchColumns.push_back(this->getColumn(columnNames[i]));
		}


		int keyLength;
		int keyPosition;

		while (getline(in, line, '\n'))
		{
			columnValueMatched = true;

			for (int i = 0; i < (int)(columnNames.size()); i++)
			{
				Column * searchColumn = this->getColumn(columnNames[i]);

				keyLength = searchColumn->getLength();
				keyPosition = searchColumn->getPosition();

				currentKey = line.substr(keyPosition, keyLength);

				padRight(keys[i], keyLength);

				if (currentKey.compare(keys[i]) != 0)
				{
					columnValueMatched = false;     //  this line text does not match our search criteria
				}
			}

			if (columnValueMatched)
			{
				records.push_back(line);
			}
		}

		if (records.size() == 0)
			cout << "Key not found" << endl;
		else
			found = true;

		in.close();
		return found;
	}
	//-----------------------------------------------
	int recordLength()
	{
		int recordLength = 0;
		for (int i = 0; i < ((int)columns.size()); i++)
			recordLength += columns[i]->getLength();

		return recordLength;
	}
	//-----------------------------------------------
	void promptColumnValues(vector<string> & vals)
	{
		cin.ignore();
		for (int i = 0; i < ((int)columns.size()); i++)
			vals.push_back(promptColumnValue(columns[i]->getName()));
	}
	//-----------------------------------------------
	string promptColumnValue(string columnName)
	{
		string input;
		cout << "Enter " << columnName << ": ";
		getline(cin, input, '\n');
		int columnLength = getColumn(columnName)->getLength();
		padRight(input, columnLength);
		return input;
	}
	//-----------------------------------------------
	// prompts for new record data and saves it, but doesn't load it into memory
	void createRecord()
	{
		cout << "Creating..." << endl;

		string line = "";

		vector<string> vals;
		promptColumnValues(vals);

		fstream file(fileName, ios::out | ios::app | ios::ate);

		for (int i = 0; i < ((int)vals.size()); i++)
			line += vals[i];

		line += "\n";

		file << line;
		file.close();
		cout << "Created:" << endl << line << endl;
	}
	//-----------------------------------------------
	int updateRecord(string key, string writeColumnName, string writeValue)
	{
		cout << "Updating..." << endl;

		int result = -1;
		Column * currentColumn;

		for (int i = 0; i < ((int)columns.size()); i++)
		{
			currentColumn = columns[i];

			if (currentColumn->getName().compare(writeColumnName) == 0)
			{
				result = writeByKey(key, keyColumn->getLength(), writeValue, currentColumn->getPosition(), currentColumn->getLength());
				break;
			}
		}
		if (result == -1)
			cout << "Record with key " << key << " in column " << writeColumnName << " not found" << endl;

		cout << "Finished Updating" << endl;

		return result;
	}
	//-----------------------------------------------
	int writeByKey(string key, int keyLength, string writeValue, int columnPosition, int columnLength)
	{
		int result = -1;
		string currentKey;
		string line;

		fstream file(fileName, ios::in | ios::out);

		int recNum = 0;
		int writePosition;

		while (getline(file, line, '\n'))
		{
			currentKey = line.substr(0, keyLength);

			padRight(key, keyLength);

			if (currentKey.compare(key) == 0)
			{
				writePosition = recNum * (2 + recordLength()) + columnPosition;

				file.seekp(writePosition);

				padRight(writeValue, columnLength);
				const char * writeVal = writeValue.c_str();

				file.write(writeVal, columnLength);

				result = recNum;
				break;
			}

			recNum++;
		}

		file.close();
		return result;
	}
	//-----------------------------------------------
	void readAll(vector<string>& collection)
	{
		string line;
		ifstream in(fileName);

		while (getline(in, line, '\n'))
			collection.push_back(line);

		in.close();
	}
	//-----------------------------------------------
	void showVector(vector<string>& vec)
	{
		for (int i = 0; i < (int)(vec.size()); i++)
			cout << vec[i] << endl;
	}
	//-----------------------------------------------
	void displayFile()
	{
		vector<string> lines;
		readAll(lines);
		int size = (int)(lines.size());

		if (size < 1)
			cout << "File " << fileName << " is empty" << endl;
		else
		{
			cout << "---------------------------------------------------------" << endl;
			cout << "Displaying File " << fileName << endl;
			cout << "---------------------------------------------------------" << endl;

			this->showColumns();

			for (int i = 0; i < size; i++)
				cout << lines[i] << endl;

			cout << "---------------------------------------------------------" << endl;
		}
	}
	//-----------------------------------------------
	bool setFileName(string _name)
	{
		bool ok = true;
		fileName = _name;
		return ok;
	}
	//-----------------------------------------------
	string getFileName()
	{
		return fileName;
	}
	//-----------------------------------------------
	bool setKeyColumn(Column * KeyColumn)
	{
		bool ok = true;
		keyColumn = KeyColumn;
		return ok;
	}
	//-----------------------------------------------
	bool setKeyColumn(int KeyColumnIdx)
	{
		bool ok = true;
		keyColumn = columns[KeyColumnIdx];
		return ok;
	}
	//-----------------------------------------------
	bool setKeyColumn(string KeyColumnName)
	{
		bool ok = true;
		keyColumn = getColumn(KeyColumnName);
		return ok;
	}
	//-----------------------------------------------
	Column * getKeyColumn()
	{
		return keyColumn;
	}
	//-----------------------------------------------
	void addColumn(string nm, int ln, bool isKey = false)
	{
		Column * c = new Column(nm, recordLength(), ln, isKey);

		if (isKey)
			setKeyColumn(c);

		columns.push_back(c);
	}
	//-----------------------------------------------
	Column * getColumn(string colName)
	{
		Column * col = NULL;

		for (int i = 0; i < ((int)columns.size()); i++)
		{
			if (columns[i]->getName().compare(colName) == 0)
			{
				col = columns[i];
			}
		}
		return col;
	}
	//-----------------------------------------------
	void showColumns()
	{
		string top = "";

		padRight(top, this->recordLength(), '-');

		cout << top << endl;
		string columnName = "";
		int colLength;
		for (int i = 0; i < ((int)columns.size()); i++)
		{
			columnName = columns[i]->getName();
			colLength = columns[i]->getLength();
			padRight(columnName, colLength);
			cout << truncate(columnName, colLength);
		}
		cout << endl << top << endl;
	}
	//-----------------------------------------------
	bool setValues(string record, vector<string> & vals)
	{
		bool res = true;
		int position = 0;
		int colLength;

		for (int i = 0; i < ((int)columns.size()); i++)
		{
			colLength = columns[i]->getLength();
			vals.push_back(record.substr(position, colLength));
			position += colLength;
		}

		return res;
	}
	//-----------------------------------------------
	string getValue(string record, string columnName)
	{
		Column * col = getColumn(columnName);

		int position = col->getPosition();
		int colLength = col->getLength();

		return record.substr(position, colLength);
	}
	//-----------------------------------------------
	void deleteRecord(string recid)
	{
		cout << "Deleting..." << endl;
	}
	//-----------------------------------------------
	vector<Column *> getColumns()
	{
		return columns;
	}
	//-----------------------------------------------
private:
	string fileName;
	Column * keyColumn;
	vector<Column *> columns;
	//-----------------------------------------------
};
#endif