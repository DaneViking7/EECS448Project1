/*----------------------------------------------------------------------------------------
File Name: Time.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Time class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "Time.h"

void Time::setTimeType(std::string type)
{
	if(type == "12HourTime")
	{
		m_timeType = 12;
	}
	else if(type == "24HourTime")
	{
		m_timeType = 24;
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
			if(hour <=12 && hour >=1)
			{
				validHour = true;
			}
		}
		else if(m_timeType == 24)
		{
			if(hour <=24 && hour >=1)
			{
				validHour = true;
			}
		}
		hour = newHour;
	}
	m_hour = hour;
}
