/*----------------------------------------------------------------------------------------
File Name: Event.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Event class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "Event.h"

Event::Event()
{
  mEventName = " ";
  mDay = 0;
  mMonth = 0;
  mYear = 0;
  mDate = " ";
  mTimeList = nullptr;
}

Event::Event(std::string aEventName, int aDay, int aMonth, int aYear, std::string aAttendeeName, int aHour, int aMinute, int aTimeType, std::string aDayTime)
{
  mEventName = aEventName;
  mDay = aDay;
  mMonth = aMonth;
  mYear = aYear;
  mDate = setEventDate(aMonth, aDay, aYear);

  Time tempTimeObj;
  tempTimeObj.setHour(aHour);
  tempTimeObj.setMinute(aMinute);
  tempTimeObj.setTimeType(aTimeType);
  tempTimeObj.setDayTime(aDayTime);
  tempTimeObj.setTime();

  //mTimeList = nullptr;
}

Event::Event(const Event& aEvent)
{
  mEventName = aEvent.mEventName;
  mDay = aEvent.mDay;
  mMonth = aEvent.mMonth;
  mYear = aEvent.mYear;
  mDate = aEvent.mDate;
  mTimeList = aEvent.mTimeList;
}

Event::~Event()
{

}

Event Event::operator=(const Event& aEvent)
{
  mEventName = aEvent.mEventName;
  mDay = aEvent.mDay;
  mMonth = aEvent.mMonth;
  mYear = aEvent.mYear;
  mDate = aEvent.mDate;
  mTimeList = aEvent.mTimeList;

  return(*this);
}

void Event::setEventName(std::string aEventName)
{

}

void Event::setEventDay(int aDay)
{

}

void Event::setEventMonth(int aMonth)
{

}

void Event::setEventYear(int aYear)
{

}

void Event::setEventAttendeeName(std::string aAttendeeName)
{

}

void Event::setEventHour(int aHour)
{

}

void Event::setEventMinute(int aMinute)
{

}

void Event::setEventTimeType(int aTimeType)
{

}

void Event::setEventDayTime(int aDayTime)
{

}

std::string Event::getEventName(std::string aDate)
{
  return(0); //debug
}

std::string Event::getEventDate(std::string aEventName)
{
  return(0); //debug
}

std::string Event::getEventTime(std::string)
{
  return(0); //debug
}

bool Event::isLeapYear(int aYear)
{
  return(0); //debug
}

std::string Event::setEventDate(int aMonth, int aDay, int aYear)
{
  return(0); //debug
}
