/*----------------------------------------------------------------------------------------
File Name: Time.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Time class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "Time.h"

Time::Time() : m_time( " " ), m_hour( 0 ), m_minute( 0 ), m_timeType( 0 ), m_daytime( " " )
{

}

Time::~Time()
{

}

void Time::setTimeType(int type)
{
	if(type == 12 || type == 24)
	{
		m_timeType = type;
	}
	else
	{
		std::cout<<"Invalid time type.\n";
	}
}

void Time::setHour(int hour)
{
	bool validHour;
	if(m_timeType == 12)
	{
		if(hour > 12 || hour < 1)
		{
			validHour = false;
		}
		else
                {
                        validHour = true;
                }
	}
	else if(m_timeType == 24)
	{
		if(hour > 24 || hour < 0)
		{
			validHour = false;
		}
		else
		{
			validHour = true;
		}
	}
	while(!validHour)
	{
		int newHour = hour;
		std::cout<<"An hour cannot have a value of "<<newHour<<"\nPlease select a value between ";
		if(m_timeType == 12)
		{
			std::cout<<"1-12: ";
		}
		else if(m_timeType == 24)
		{
			std::cout<<"0-24: ";
		}
		std::cin>>newHour;
		if(m_timeType == 12)
		{
			if(newHour <=12 && newHour >=1)
			{
				validHour = true;
			}
		}
		else if(m_timeType == 24)
		{
			if(newHour <=24 && newHour >=1)
			{
				validHour = true;
			}
		}
		hour = newHour;
	}
	m_hour = hour;
}

void Time::setMinute(int minute)
{
	bool validMinute;
	if(minute < 0 || minute > 59)
	{
		validMinute = false;
	}
	else
	{
		validMinute = true;
	}
	while(!validMinute)
	{
		int newMinute = minute;
		std::cout<<"A minute cannot have a value of "<<newMinute<<"\nPlease select a value between 0-59: ";
		std::cin>>newMinute;
		if(newMinute >= 0 && newMinute <= 59)
		{
			validMinute = true;
		}
		minute = newMinute;
	}
	m_minute = minute;
}

void Time::setDayTime(std::string daytime)
{
	bool validDaytime;
	if(daytime != "am" || daytime != "pm")
	{
		validDaytime = false;
	}
	else
	{
		validDaytime = true;
	}
	while(!validDaytime)
	{
		std::string newDaytime = daytime;
		std::cout<<"Invalid daytime.\nPlease enter am or pm: ";
		std::cin>>newDaytime;
		if(daytime == "am" || daytime == "pm")
		{
			validDaytime = true;
		}
		daytime = newDaytime;
	}
	m_daytime = daytime;
}

void Time::setTime()
{
	if(m_timeType == 12)
	{
		if(m_minute < 10)
		{
			m_time = m_hour+":0"+m_minute+m_daytime;
		}
		else
		{
			m_time = m_hour+":"+m_minute+m_daytime;
		}
	}
	else if(m_timeType == 24)
	{
		if(m_minute < 10)
                {
                        m_time = m_hour+":0"+m_minute;
                }
                else
                {
                        m_time = m_hour+":"+m_minute;
                }
	}
}

std::string Time::getTime()
{
	return m_time;
}

void Time::addAttendees(std::string attendee)
{
	m_attendees.push_back(attendee);
}

std::string Time::getAttendee(int i) //intended to be in for loop when called looking like: for(int i = 0; i < m_attendees.size(); i++)
{
	return(m_attendees[i]);
}
