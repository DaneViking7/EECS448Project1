/*----------------------------------------------------------------------------------------
File Name: Time.h
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the header file for the Time class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include <list>

class Time
{
	public:
		/*
    		@pre type is a valid string
		@post sets time type to either 12 or 24 based on whether 12HourTime or 24HourTime is presented
    		@return none */	
		void setTimeType(std::string type);
		/*
    		@pre hour is a valid int
    		@post sets m_hour to hour
    		@return none */
		void setHour(int hour);
		/*
    		@pre minute is a valid int
    		@post sets m_minute to minute
    		@return none */
		void setMinute(int minute);
		/*
    		@pre hour and minute are valid ints and AmPm is a valid string
    		@post sets m_12HourTime
    		@return none */
		void set12HourTime(int hour, int minute, std::string AmPm);
		/*
    		@pre hour and minute are valid ints
    		@post sets m_24HourTime
    		@return none */
		void set24HourTime(int hour, int minute);
		/*
    		@pre none
    		@postnone
    		@return m_12HourTime if m_timeType == 12, m_24HourTIme if m_timeType == 24*/
		std::string getTime;
		/*
    		@pre attendee is a valid string
    		@post pushes attendee to the back of m_attendees
    		@return none none */
		void addAttendees(std::string attendee);
		/*
    		@pre none
    		@post none
    		@return the list of attendees */
		std::string getAttendeesList;
	private:
                std::list<std::string> m_attendees;
                std::string m_12HourTime;
                std::string m_24HourTime;
                int m_hour;
                int m_minute;
                int m_timeType;
};
#endif
