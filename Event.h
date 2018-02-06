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

class Event
{
public:
  /** @brief default constructor

    @pre none
    @post initializes member variables to temporary values
    @return none*/
  Event();

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
  void setEventName(std::string aEventName);

  /** @brief sets/changes the day of an Event

   @pre none
   @post  The Event's day has been set/changed
   @return  none */
  void setEventDay(int aDay);

  /** @brief sets/changes the month of an Event

   @pre none
   @post  The Event's month has been set/changed
   @return  none */
  void setEventMonth(int aMonth);

  /** @brief sets/changes the year of an Event

   @pre none
   @post  The Event's year has been set/changed
   @return  none */
  void setEventYear(int aYear);

  /** @brief sets/changes the name of a specific attendee of an Event

   @pre none
   @post  The attendee's name has been set/changed
   @return  none */
  void setEventAttendeeName(std::string aAttendeeName);

  /** @brief sets/changes the hour of an Event

   @pre none
   @post  The Event's hour has been set/changed
   @return  none */
  void setEventHour(int aHour);

  /** @brief sets/changes the minute of an Event

   @pre none
   @post  The Event's minute has been set/changed
   @return  none */
  void setEventMinute(int aMinute);

  /** @brief sets/changes the time of an Event to 12 or 24 hour time

   @pre none
   @post  The Event's time type has been set/changed to 12 or 24 hour time
   @return  none */
  void setEventTimeType(int aTimeType);

  /** @brief sets/changes the time of an Event to AM or PM

   @pre none
   @post  The Event's time of day has been set/changed AM or PM
   @return  none */
  void setEventDayTime(int aDayTime);

  /** @brief gets the name of the Event

   @pre the exact Date of the Event must be known
   @post gets the name of the Event
   @return a string representing the name of the Event*/
  std::string getEventName(std::string aDate);

  /** @brief gets the date of the Event

   @pre the exact Name of the Event must be known
   @post gets the date of the Event
   @return a string representing the date of the Event*/
  std::string getEventDate(std::string aEventName);

  /** @brief gets the time of the Event

   @pre the exact Name of the Event must be known
   @post gets the time of the Event
   @return a string representing the time of the Event*/
  std::string getEventTime(std::string aEventName);

private:
  /** @brief determines whether a given year is a leap year

   @pre the year must be a valid, 4-digit year
   @post tells whether a given year is a leap year
   @return a bool, true if the year is a leap year, false otherwise*/
  bool isLeapYear(int aYear);

  /** @brief sets/changes the date of an Event

   @pre none
   @post  The Event's date has been set/changed
   @return  string representing the date in the form MM/DD/YYYY */
  std::string setEventDate(int aMonth, int aDay, int aYear);


  std::string mEventName; //!< The name of the Event
  int mDay; //!< The day of the event
  int mMonth; //!< The month of the event
  int mYear; //!< The year of the event
  std::string mDate; //!< the full Date of the event in the form MM/DD/YYYY
  LinkedList<Time>* mTimeList; //!< the list of the times plus attendees

};
#endif
