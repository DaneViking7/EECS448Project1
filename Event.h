/*----------------------------------------------------------------------------------------
File Name: Event.h
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the header file for the Event class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include "Time.h"
#include "LinkedList.h"
#include <iostream>
#include <limits>
#include "PrecondViolatedExcep.h"
#include <stdexcept>

class Event
{
public:
  /** @brief constructor which takes an Event name, a day, a month, a year, an attendee name,
    an hour, a minute, a time type (12hr or 24 hr) and a day time (AM/PM)

   @pre none
   @post creates a new event and sets all the member variables to their respective parameters
   @return none */
  Event(std::string aEventName, int aDay, int aMonth, int aYear, std::string aAttendeeName, int aHour, int aMinute, int aTimeType, std::string aDayTime);

  /** @brief copy constructor

   @pre Another event must exist
   @post a copy of an Event has been made at construction time
   @return none */
  Event(const Event& aEvent);

  /** @brief destructor

    @pre none
    @post cleans up all allocated heap memory
    @return none*/
  ~Event();

  /** @brief operator overload which allows assignment operator use between Events

     @pre none
     @post two Events are equal to each other
     @return an Event which is a duplicate of an already existing Event*/
  Event operator=(const Event& aEvent);

  /** @brief sets/changes the name of an Event

   @pre none
   @post  The Event's name has been set/changed
   @return  none */
  void changeEventName(std::string aEventName);

  /** @brief sets/changes the date of an Event

   @pre none
   @post  The Event's date has been set/changed
   @return  none */
  void changeEventDate(int aDay, int aMonth, int aYear);

  /** @brief adds a new time of an Event and adds an attendee to that time

   @pre none
   @post  A new Event's time has been created and an attendee has been added
   @return  none */
  void addEventTime_Attendee(int aHour, int aMinute, int aTimeType, std::string aDayTime, std::string aAttendeeName);

  /** @brief gets the name of the Event

   @pre none
   @post gets the name of the Event
   @return a string representing the name of the Event*/
  std::string getEventName();

  /** @brief gets the date of the Event

   @pre none
   @post gets the date of the Event
   @return a string representing the date of the Event*/
  std::string getEventDate();

  /** @brief gets the time of the Event

   @pre none
   @post gets the availability times of the Event, and subsequently all of
    the people who can attend at each time.
   @return a pointer to a LinkedList with the availability times of the
    Event and the people who can attend at each time*/
  LinkedList<Time>* getEventTimes();

	/** @brief adds an attendee to an event time
	@pre none
	@post adds an attendee to a time slot
	@return none
	**/
	void addAttendee(Time t, string name);

private:
  /** @brief determines whether a given year is a leap year

   @pre the year must be a valid, 4-digit year
   @post tells whether a given year is a leap year
   @return a bool, true if the year is a leap year, false otherwise*/
  bool isLeapYear();

  /** @brief checks to make sure the day is valid

   @pre IMPORTANT: the Event month and year must be already set
   @post  The Event's day has been set/changed
   @return  none */
  void setEventDay(int aDay) throw (PrecondViolatedExcep);

  /** @brief checks to make sure the month is valid

   @pre none
   @post  The Event's month has been set/changed
   @return  none */
  void setEventMonth(int aMonth) throw (PrecondViolatedExcep);

  /** @brief checks to make sure the year is valid

   @pre none
   @post  The Event's year has been set/changed
   @return  none */
  void setEventYear(int aYear) throw (PrecondViolatedExcep);

  /** @brief sets/changes the date of an Event

   @pre none
   @post  The Event's date has been set/changed
   @return  string representing the date in the form MM/DD/YYYY */
  void setEventDate();

  std::string mEventName; //!< The name of the Event
  int mDay; //!< The day of the event
  int mMonth; //!< The month of the event
  int mYear; //!< The year of the event
  std::string mDate; //!< the full Date of the event in the form MM/DD/YYYY
  LinkedList<Time>* mTimeList; //!< the list of the times plus attendees

};
#endif
