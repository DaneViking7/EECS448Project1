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
		/** @brief default constructor
	    @pre none
	    @post initializes member variables to temporary values
	    @return none**/
		Time();
		/** @brief copy constructor
	    @pre none
	    @post initializes member variables to the values of the passed in Time object
	    @return none**/
		Time(const Time& aTime);
		/** @brief destructor
			@pre none
			@post none
			@return none**/
		~Time();
		/** @brief operator = overload
	    @pre none
	    @post initializes member variables of the Time object on the lhs of the = to those of of the object on the rhs
	    @return none**/
		Time operator=(const Time& aTime);
		/**
    		@pre type is a valid int
		@post sets time type to either 12 or 24
    		@return none **/
		void setTimeType(int type);
		/**
    		@pre hour is a valid int
    		@post sets m_hour to hour
    		@return none **/
		void setHour(int hour);
		/**
    		@pre minute is a valid int
    		@post sets m_minute to minute
    		@return none **/
		void setMinute(int minute);
		/**
                @pre daytime is a valid string
                @post sets m_daytime to daytime
                @return none **/
		void setDayTime(std::string daytime); //didn't know how else to call AM/PM
		/**
    		@pre none
		@post none
    		@return m_timeType **/
		int getTimeType();
		/**
    		@pre none
    		@post none
    		@return m_hour **/
		int getHour();
		/**
    		@pre none
    		@post none
    		@return m_minute **/
		int getMinute();
		/**
                @pre none
                @post none
                @return m_daytime **/
		std::string getDayTime(); //didn't know how else to call AM/PM
		/**
    		@pre none
    		@post sets m_time
    		@return none **/
		void setTime();
		/**
    		@pre none
    		@postnone
    		@return m_time**/
		std::string getTime();
		/**
    		@pre attendee is a valid string
    		@post pushes attendee to the back of m_attendees
    		@return none none **/
		void addAttendees(std::string attendee);
		/**
    		@pre i is a valid int
    		@post none
    		@return the attendee at m_attendees[i] **/
		std::string getAttendee(int i);
		/**
                @pre none
                @post none
                @return m_attendees.size() **/
		int getAttendeesSize();
	private:
                std::vector<std::string> m_attendees; //!< vector to hold list of attendees per time slot
                std::string m_time; //!< holds time as string
                int m_hour; //!< holds individual hour
                int m_minute; //!< holds individual minute
                int m_timeType; //!<holds individual timetype
		std::string m_daytime; //!<holds daytime type
};
#endif
