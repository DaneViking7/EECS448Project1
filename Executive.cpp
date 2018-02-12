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

void Executive::availMode()
{
	int size = events->getLength();
	string user;
	cout<<"Enter your name: ";
	cin>>user;
	cout<<"\n";
	try
	{
		for(int i = 1; i <= size; i++)
		{
			Event temp = events->getEntry(i);
			cout<<"Event "<<(i)<<": "<<temp.getEventName()<<", "<<temp.getEventDate()<<endl;
		}
		int choice;
		while(choice != 0)
		{
			cout<<"\nEnter an event number to indicate availability or enter 0 to exit: ";
			cin>>choice;
			while(cin.fail() || choice < 0 || choice > size)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Enter a valid option: ";
				cin>>choice;
			}
			if(choice != 0)
			{
				cout<<"\n";
				LinkedList<Time>* times = events->getEntry(choice).getEventTimes();
				for(int j = 1; j <= times->getLength(); j++)
				{
					char att;
					cout<<"Can you attend the event at "<<times->getEntry(j).getTime()<<" (y/n): ";
					cin>>att;
					while(cin.fail() || (att != y && att != n))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>att;
					}
					if(att == y)
					{
						events->getEntry(choice).addEventTime_Attendee(times->getEntry(j).getHour(), times->getEntry(j).getMinute(), times->getEntry(j).getTimeType(), times->getEntry(j).getDayTime(), user);
					}
				}
				cout<<"\n";
			}
		}
	}
	catch(PrecondViolatedExcep pve)
	{
		cerr<<pve.what()<<"\n";
	}
}

void Executive::run()
{

}
