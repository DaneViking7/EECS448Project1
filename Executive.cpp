/*----------------------------------------------------------------------------------------
File Name: Executive.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Executive class.
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "Executive.h"

Executive::Executive()
{
	ifstream inFile; 
	inFile.open(database.txt);
	if(!inFile.is_open())
	{
		ofstream outFile("database.txt");
	}
	inFile>>;
	rosta=new Collection<Roster>(num);
	char space=' ';
	string cName, tempTotal;
	int myCount=0;
	int nStudents;
	stringstream object;
	object.clear();
	object.str("");
	if(myCount==0)
	{
		getline(inFile, cName, '\n');
	}
	while(getline(inFile, cName, space))
	{
		getline(inFile, tempTotal, space);
		object.str(tempTotal);
		object>>nStudents;
		object.clear();
		object.str("");
		int* studentIDs=new int[nStudents];
		for(int h=0; h<nStudents; h++)
		{
			if(h<(nStudents-1))
			{
				string tempID;
				getline(inFile, tempID, space);
				object.str(tempID);
				object>>studentIDs[h];
				object.clear();
				object.str("");
			}
			else
			{
				string tempID;
				getline(inFile, tempID);
				object.str(tempID);
				object>>studentIDs[h];
				object.clear();
				object.str("");
			}
		}
		Roster obj(cName, nStudents, studentIDs);
		rosta->appendItem(obj);
		myCount++;
		delete[] studentIDs;
	}
	int size=num;
	while(size<myCount)
	{
		size=size * 2;
	}
	while(myCount<size)
	{
		string cName = "";
		int nStudents = 2;
		int* studentIDs=new int[nStudents];
		for(int j=0; j<nStudents; j++)
		{
			studentIDs[j] = 0;
		}
		Roster ros(cName, nStudents, studentIDs);
		rosta->appendItem(ros);
		myCount++; 
		delete[] studentIDs;
	}
	inFile.close();
}

Executive::~Executive()
{

}

void Executive::run()
{

}
