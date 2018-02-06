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
#include <vector>

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
                @pre daytime is a valid string
                @post sets m_daytime to daytime
                @return none */
		void setDayTime(std::string daytime); //didn't know how else to call AM/PM
		/*
    		@pre none
    		@post sets m_time
    		@return none */
		void setTime();
		/*
    		@pre none
    		@postnone
    		@return m_time*/
		std::string getTime();
		/*
    		@pre attendee is a valid string
    		@post pushes attendee to the back of m_attendees
    		@return none none */
		void addAttendees(std::string attendee);
		/*
    		@pre i is a valid int
    		@post none
    		@return the attendee at m_attendees[i] */
		std::string getAttendee(int i);
		/*
                @pre none
                @post 
                @return m_attendees.size() */
		int getAttendeesSize();
	private:
                std::vector<std::string> m_attendees;
                std::string m_time;
                int m_hour;
                int m_minute;
                int m_timeType;
		std::string m_daytime;
};
#endif
