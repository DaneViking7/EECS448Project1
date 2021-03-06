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

Time::Time(const Time& aTime)
{
	m_time = aTime.m_time;
	m_hour = aTime.m_hour;
	m_minute = aTime.m_minute;
	m_timeType = aTime.m_timeType;
	m_daytime = aTime.m_daytime;
	m_attendees = aTime.m_attendees;
}

Time::~Time()
{

}

Time Time::operator=(const Time& aTime)
{
	m_time = aTime.m_time;
	m_hour = aTime.m_hour;
	m_minute = aTime.m_minute;
	m_timeType = aTime.m_timeType;
	m_daytime = aTime.m_daytime;
	m_attendees = aTime.m_attendees;
	return(*this);
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
		if(hour > 12 || hour < 1 || (m_daytime=="am" && (hour==12 || hour<=4)) || (m_daytime=="pm" && hour==12 ))
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
		if(hour > 24 || hour<=4 || hour==12)
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
			if(newHour <=12 && newHour >=1 && !(m_daytime=="am" && (hour==12 || hour<=4)) && !(m_daytime=="pm" && hour==12 ))
			{
				validHour = true;
			}
		}
		else if(m_timeType == 24)
		{
			if(newHour <=24 && newHour >=5 && newHour != 12)
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
	if(minute != 0 && minute != 20 && minute != 40)
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
		std::cout<<"A minute cannot have a value of "<<newMinute<<"\nPlease select 0, 20, or 40: ";
		std::cin>>newMinute;
		if(newMinute == 0 || newMinute == 20 || newMinute == 40)
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
	if(daytime != "am" && daytime != "pm")
	{
		validDaytime = false;
	}
	else
	{
		validDaytime = true;
	}
	while(!validDaytime)
	{
		std::string newDaytime;
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

int Time::getTimeType()
{
	return m_timeType;
}

int Time::getHour()
{
	return m_hour;
}

int Time::getMinute()
{
	return m_minute;
}

std::string Time::getDayTime()
{
	return m_daytime;
}

void Time::setTime()
{
	std::string tempHour = std::to_string(m_hour);
	std::string tempMin = std::to_string(m_minute);
	if(m_timeType == 12)
	{
		if(m_minute < 10)
		{
			m_time = tempHour+":0"+tempMin+m_daytime;
		}
		else
		{
			m_time = tempHour+":"+tempMin+m_daytime;
		}
	}
	else if(m_timeType == 24)
	{
		if(m_minute < 10)
                {
                        m_time = tempHour+":0"+tempMin;
                }
                else
                {
                        m_time = tempHour+":"+tempMin;
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

std::string Time::getAttendee(int i)
{
	return(m_attendees[i]);
}

int Time::getAttendeesSize()
{
	return (m_attendees.size());
}
