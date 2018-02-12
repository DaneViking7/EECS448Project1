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
	delete events;
}

void Executive::adminMode()
{
	int size = events->getLength();
	string user;
	cout<<"Enter your name: ";
	cin>>user;
	cout<<"\n";
	try
	{
		int choice;
		while(choice != 0)
		{
			for(int i = 1; i <= size; i++) //lists out all of the events
			{
				Event temp = events->getEntry(i);
				cout<<"Event "<<(i)<<": "<<temp.getEventName()<<", "<<temp.getEventDate()<<endl;
			}
			cout<<"\nEnter an event number to check its status, -1 to add an event, or enter 0 to exit: ";
			cin>>choice;
			while(cin.fail() || choice < -1 || choice > size)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Enter a valid option: ";
				cin>>choice;
			}
			if(choice > 0) //user picked an event, prints out the times and attendees for the event
			{
				cout<<"\n"<<events->getEntry(choice).getEventName()<<"\n"<<events->getEntry(choice).getEventDate()<<"\n";
				LinkedList<Time>* times = events->getEntry(choice).getEventTimes();
				for(int j = 1; j <= times->getLength(); j++)
				{
					attSize = times->getEntry(j).getAttendeesSize();
					cout<<"\n"<<times->getEntry(j).getTime();
					for(int k = 0; k < attSize; k++)
					{
						cout<<"\n\t"<<times->getEntry(j).getAttendee(k);
					}
				}
				cout<<"\n";
			}
			else if(choice == -1) //user chose to make a new event
			{
				string eName;
				int eDay;
				int eMonth;
				int eYear;
				int eHour;
				int eMinute;
				int eTimeType;
				string eDayTime;
				char done;
				cout<<"Enter an event name: ";
				cin>>eName;
				cout<<"Enter the event month: ";
				cin>>eMonth;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eMonth;
				}
				cout<<"Enter the event day: ";
				cin>>eDay;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eDay;
				}
				cout<<"Enter the event year: ";
				cin>>eYear;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eYear;
				}
				cout<<"Would you like to keep track of the time of your event using the 12 or 24 hour clock (12/24): ";
				cin>>eTimeType;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eTimeType;
				}
				cout<<"Enter the hour of the day for your event: ";
				cin>>eHour;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eHour;
				}
				cout<<"Enter the minute of the day for your event (0, 20, 40): ";
				cin>>eMinute;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eMinute;
				}
				cout<<"On the 12 hour clock, is this time am or pm (am/pm): ";
				cin>>eDayTime;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>eDayTime;
				}
				Event temp(eName, eDay, eMonth, eYear, user, eHour, eMinute, eTimeType, eDayTime);
				events->insert(1, temp);
				cout<<"Would you like to add another time for your event? (y/n): ";
				cin>>done;
				while(cin.fail() || (att != y && att != n))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>done;
				}
				while(done != 'y')
				{
					cout<<"Would you like to keep track of the time of your event using the 12 or 24 hour clock (12/24): ";
					cin>>eTimeType;
					while(cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>eTimeType;
					}
					cout<<"Enter the hour of the day for your event: ";
					cin>>eHour;
					while(cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>eHour;
					}
					cout<<"Enter the minute of the day for your event (0, 20, 40): ";
					cin>>eMinute;
					while(cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>eMinute;
					}
					cout<<"On the 12 hour clock, is this time am or pm (am/pm): ";
					cin>>eDayTime;
					while(cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>eDayTime;
					}
					Event temp(eName, eDay, eMonth, eYear, user, eHour, eMinute, eTimeType, eDayTime);
					events->insert(1, temp);
					cout<<"Would you like to add another time for your event? (y/n): ";
					cin>>done;
					while(cin.fail() || (att != y && att != n))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>done;
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
