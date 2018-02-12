/*----------------------------------------------------------------------------------------
File Name: Executive.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Executive class.
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include "Executive.h"
using namespace std;

Executive::Executive()
{
	ifstream inFile; 
	inFile.open("database.txt");
	if(!inFile.is_open())
	{
		ofstream outFile("database.txt");
		inFile.open("database.txt");
	}
	string eventName;
	string namekey="";
	int eventMonth;
	int eventDay;
	int eventYear;
	int eventHour;
	int eventMinute;
	int eventTT;
	string eventDT;
	string attkey="";
	string eventAttendee;
	events=new LinkedList<Event>;
	while(getline(inFile, eventName, '\n'))
	{
		inFile>>eventMonth;
		inFile>>eventDay;
		inFile>>eventYear;
		inFile>>eventHour;
		inFile>>eventMinute;
		inFile>>eventDT;
		inFile>>eventTT;
		inFile>>eventAttendee;
	    Event newEvent(eventName, eventDay, eventMonth, eventYear, eventAttendee, eventHour, eventMinute, eventTT, eventDT);
		inFile>>attkey;
		while(eventHour!=3398)
		{
			while(attkey!="none")
			{
				eventAttendee = attkey;
				newEvent.addEventTime_Attendee(eventHour, eventMinute, eventTT, eventDT, eventAttendee);
				inFile>>attkey;
			}
			inFile>>eventHour;
			if(eventHour!=3398)
			{
				inFile>>eventMinute;
				inFile>>eventDT;
				inFile>>eventTT;
				inFile>>eventAttendee;
				newEvent.addEventTime_Attendee(eventHour, eventMinute, eventTT, eventDT, eventAttendee);
				inFile>>attkey;
			}
		}
		events->insert(1, newEvent);
		getline(inFile, eventName, '\n');
	}
	inFile.close();
}

Executive::~Executive()
{
	if(!events->isEmpty())
  {
    delete events;
  }
}

void Executive::adminMode()
{
	string user;
	cout<<"Enter your name: ";
	cin.ignore();
	getline(cin, user);
	try
	{
		int choice = -2;
		while(choice != 0)
		{
			cout<<"========================================================================\n";
			int size = events->getLength();
			if(size == 0)
				cout<<"No events currently.\n";
			for(int i = 1; i <= size; i++) //lists out all of the events
			{
				Event temp = events->getEntry(i);
				cout<<"Event "<<(i)<<": "<<temp.getEventName()<<", "<<temp.getEventDate()<<endl;
			}
			cout<<"========================================================================\n";
			cout<<"Enter an event number to check its status, -1 to add an event, or 0 to exit: ";
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
					int attSize = times->getEntry(j).getAttendeesSize();
					cout<<"\n\t"<<times->getEntry(j).getTime();
					for(int k = 0; k < attSize; k++)
					{
						cout<<"\n\t\t"<<times->getEntry(j).getAttendee(k);
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
				cin.ignore();
				getline(cin, eName);
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
				while(cin.fail() || (eTimeType != 12 && eTimeType != 24))
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
				cin.ignore();
				getline(cin, eDayTime);
				Event temp(eName, eDay, eMonth, eYear, user, eHour, eMinute, eTimeType, eDayTime);
				cout<<"Would you like to add another time for your event? (y/n): ";
				cin>>done;
				while(cin.fail() || (done != 'y' && done != 'n'))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Enter a valid option: ";
					cin>>done;
				}
				while(done != 'n')
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
					temp.addEventTime_Attendee(eHour, eMinute, eTimeType, eDayTime, user);
					cout<<"Would you like to add another time for your event? (y/n): ";
					cin>>done;
					while(cin.fail() || (done != 'y' && done != 'n'))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>done;
					}
				}
				events->insert(1, temp);
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
	cin.ignore();
	getline(cin, user);
	try
	{
		int choice = -2;
		while(choice != 0)
		{
			cout<<"========================================================================\n";
			if(size == 0)
				cout<<"No events currently.\n";
			for(int i = 1; i <= size; i++)
			{
				Event temp = events->getEntry(i);
				cout<<"Event "<<(i)<<": "<<temp.getEventName()<<", "<<temp.getEventDate()<<endl;
			}
			cout<<"========================================================================\n";
			cout<<"Enter an event number to indicate availability or enter 0 to exit: ";
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
					while(cin.fail() || (att != 'y' && att != 'n'))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Enter a valid option: ";
						cin>>att;
					}
					if(att == 'y')
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
	int choice=0;
	string name;
	int month;
	int day;
	int year;
	int hour;
	int minute;
	string DT;
	int TT;
	string attendee;
	ofstream outFile;
	outFile.open("database.txt");
	while(choice!=3)//creating the selection menu
	{
		cout<<"(1) Admin Mode\n";
		cout<<"(2) Attendee Mode\n";
		cout<<"(3) Quit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		while(cin.fail() || choice > 3 || choice < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Enter a valid option: ";
			cin>>choice;
		}
		if(choice==1)
		{
			adminMode();
		}
		else if(choice==2)
		{
			availMode();
		}
	}
	for(int i = 1; i<=(events->getLength()); i++)
	{
		name=events->getEntry(i).getEventName();
		outFile<<name<<'\n';
		month=events->getEntry(i).getMonth();
		outFile<<month<<'\n';
		day=events->getEntry(i).getDay();
		outFile<<day<<'\n';
		year=events->getEntry(i).getYear();
		outFile<<year<<'\n';
		LinkedList<Time>* times = events->getEntry(i).getEventTimes();
		for(int j = 1; j<=(times->getLength()); j++)
		{
			hour=times->getEntry(j).getHour();
			outFile<<hour<<'\n';
			minute=times->getEntry(j).getMinute();
			outFile<<minute<<'\n';
			DT=times->getEntry(j).getDayTime();
			outFile<<DT<<'\n';
			TT=times->getEntry(j).getTimeType();
			outFile<<TT<<'\n';
			for(int k = 0; k<(times->getEntry(j).getAttendeesSize()); k++)
			{
				attendee=(times->getEntry(j).getAttendee(k));
				outFile<<attendee<<'\n';
			}
			outFile<<"none\n";
		}
		outFile<<3398<<"\n";
	}
	outFile.close();
}
