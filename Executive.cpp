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
	Event newEvent;
	int eventMonth;
	int eventDay;
	int eventYear;
	int eventHour;
	int eventMinute;
	int eventTT;
	string eventDT;
	string attkey="";
	string eventAttendee;
	int count=1;
	event=new LinkedList<Event>;
	while(namekey!="none")
	{
		while(getline(inFile, eventName, '\n'))
		{
			cin>>eventMonth;
			cin>>eventDay;
			cin>>eventYear;
			cin>>eventHour;
			cin>>eventMinute;
			cin>>eventDT;
			cin>>eventTT;
			cin>>eventAttendee;
			newEvent=new Event(eventName, eventDay, eventMonth, eventYear, eventAttendee, eventHour, eventMinute, eventTT, eventDT);
			cin>>attkey;
			while(eventHour!=3398)
			{
				while(attkey!=none)
				{
					attkey=eventAttendee;
					addEventTime_Attendee(eventHour, eventMinute, eventTT, eventDT, eventAttendee);
				}
				cin>>eventHour;	
				cin>>eventMinute;
				cin>>eventDT;
				cin>>eventTT;
			}
			
		}
		event.insert(count, newEvent);
		count++;
		cin>>nameKey;
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
	int count=1;
	int count2=1;
	int count3=0;
	outFile.open("database.txt");
	while(choice!=3)//creating the selection menu
	{
		cout<<"(1) Admin Mode\n";
		cout<<"(2) Attendee Mode\n";
		cout<<"(3) Quit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		if(choice==1)
		{
			adminMode();
		}
		else if(choice==2)
		{
			availMode();
		}
	}
	while(count<(event->getLength())
	{
		gottenEvent=event->getEntry(count);
		name=gottenEvent->getEventName();
		outFile<<name<<'\n';
		month=gottenEvent->getMonth();
		outFile<<month<<'\n';
		day=gottenEvent->getDay();
		outFile<<day<<'\n';
		year=gottenEvent->getYear();
		outFile<<year<<'\n';
		while(count2<=(gottenEvent->(getEventTimes()->getLength())
		{
			hour=gottenEvent->(getEventTimes()->(getEntry(count2)->getHour()))
			outFile<<hour<<'\n';
			minute=gottenEvent->(getEventTimes()->(getEntry(count2)->getMinute()))
			outFile<<minute<<'\n';
			DT=gottenEvent->(getEventTimes()->(getEntry(count2)->getDayTime()))
			outFile<<DT<<'\n';
			TT=gottenEvent->(getEventTimes()->(getEntry(count2)->getTimeType()))
			outFile<<TT<<'\n';
			while(count3<=(gottenEvent->(getEventTimes()->(getEntry(count2)->getAttendeesSize()))))
			{
				attendee=(gottenEvent->(getEventTimes()->(getEntry(count2)->getAttendee(count3))))
				outFile<<attendee<<'\n';
				count3++;
			}
			outFile<<"none";
			count2++;
		}
		outFile<<3398;
		count++;
	}
	outFile<<"none";
	gottenEvent=event->getEntry(count);
	name=gottenEvent->getEventName();
	outFile<<name<<'\n';
	month=gottenEvent->getMonth();
	outFile<<month<<'\n';
	day=gottenEvent->getDay();
	outFile<<day<<'\n';
	year=gottenEvent->getYear();
	outFile.close();
}
