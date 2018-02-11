/*----------------------------------------------------------------------------------------
File Name: Event.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Event class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "Event.h"

Event::Event(std::string aEventName, int aDay, int aMonth, int aYear, std::string aAttendeeName, int aHour, int aMinute, int aTimeType, std::string aDayTime)
{
  mEventName = aEventName;

  bool validMonth = true;
  bool validYear = true;
  bool validDay = true;

  do
  {
    try
    {
      setEventMonth(aMonth);
      validMonth = true;
    }
    catch(PrecondViolatedExcep& pve)
    {
      validMonth = false;
      std::cerr<<std::endl<<pve.what()<<std::endl;
      std::cerr<<std::endl;
      std::cerr<<"Please enter a valid month: ";
      std::cin>>aMonth;

      while(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number 1-12. Try again: ";
        std::cin >> aMonth;
      }
    }
  } while(validMonth == false);

  do
  {
    try
    {
      setEventYear(aYear);
      validYear = true;
    }
    catch(PrecondViolatedExcep& pve)
    {
      validYear = false;
      std::cerr<<std::endl<<pve.what()<<std::endl;
      std::cerr<<std::endl;
      std::cerr<<"Please enter a valid year: ";
      std::cin>>aYear;

      while(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number greater than or equal to 2018. Try again: ";
        std::cin >> aYear;
      }
    }
  } while(validYear == false);

  do
  {
    try
    {
      setEventDay(aDay);
      validDay = true;
    }
    catch(PrecondViolatedExcep& pve)
    {
      validDay = false;
      std::cerr<<std::endl<<pve.what()<<std::endl;
      std::cerr<<std::endl;
      std::cerr<<"Please enter a valid day: ";
      std::cin>>aDay;

      while(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number 1-31 according to the month. Try again: ";
        std::cin >> aDay;
      }
    }
  } while(validDay == false);

  setEventDate();

  mTimeList = new LinkedList<Time>();

  addEventTime_Attendee(aHour, aMinute, aTimeType, aDayTime, aAttendeeName);
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
  if(!mTimeList->isEmpty())
  {
    delete mTimeList;
  }
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

void Event::changeEventName(std::string aEventName)
{
  mEventName = aEventName;
}

void Event::changeEventDate(int aDay, int aMonth, int aYear)
{
  try
  {
    setEventMonth(aMonth);
  }
  catch(PrecondViolatedExcep& pve)
  {
    std::cerr<<std::endl<<pve.what()<<std::endl;
  }

  try
  {
    setEventYear(aYear);
  }
  catch(PrecondViolatedExcep& pve)
  {
    std::cerr<<std::endl<<pve.what()<<std::endl;
  }

  try
  {
    setEventDay(aDay);
  }
  catch(PrecondViolatedExcep& pve)
  {
    std::cerr<<std::endl<<pve.what()<<std::endl;
  }

  setEventDate();
}

void Event::addEventTime_Attendee(int aHour, int aMinute, int aTimeType, std::string aDayTime, std::string aAttendeeName)
{
  Time tempTimeObj;
  tempTimeObj.setTimeType(aTimeType);
  tempTimeObj.setDayTime(aDayTime);
  tempTimeObj.setHour(aHour);
  tempTimeObj.setMinute(aMinute);
  tempTimeObj.setTime();

  if(mTimeList->isEmpty())
  {
    tempTimeObj.addAttendees(aAttendeeName);

    try
    {
      mTimeList->insert(1, tempTimeObj);
    }
    catch(PrecondViolatedExcep& pve)
    {
      std::cerr<<std::endl<<pve.what()<<std::endl;
    }
  }
  else
  {
    bool doesTimeExist = false;
    int timePosition = 0;

    for(int i = 0; i < mTimeList->getLength(); i++)
    {
      try
      {
        if((mTimeList->getEntry(i)).getTime() == tempTimeObj.getTime())
        {
          doesTimeExist = true;
          timePosition = i;
          break;
        }
        else
        {
          doesTimeExist = false;
        }
      }
      catch(PrecondViolatedExcep& pve)
      {
        std::cerr<<std::endl<<pve.what()<<std::endl;
        break;
      }
    }

    if(doesTimeExist)
    {
      try
      {
        (mTimeList->getEntry(timePosition)).addAttendees(aAttendeeName);
      }
      catch(PrecondViolatedExcep& pve)
      {
        std::cerr<<std::endl<<pve.what()<<std::endl;
      }
    }
    else
    {
      tempTimeObj.addAttendees(aAttendeeName);

      try
      {
        mTimeList->insert(1, tempTimeObj);
      }
      catch(PrecondViolatedExcep& pve)
      {
        std::cerr<<std::endl<<pve.what()<<std::endl;
      }
    }
  }
}

std::string Event::getEventName()
{
  return(mEventName);
}

int Event::getMonth()
{
	return(mMonth);
}

int Event::getDay()
{
	return(mDay);
}

int Event::getYear()
{
	return(mYear);
}
std::string Event::getEventDate()
{
  return(mDate);
}

LinkedList<Time>* Event::getEventTimes()
{
  return(mTimeList);
}

bool Event::isLeapYear()
{
  if((mYear % 400) == 0)
  {
    return(true);
  }
  else if((mYear % 100) == 0)
  {
    return(false);
  }
  else if((mYear % 4) == 0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

void Event::setEventDay(int aDay) throw (PrecondViolatedExcep)
{
  if((mMonth == 1) || (mMonth == 3) || (mMonth == 5) || (mMonth == 7) || (mMonth == 8) || (mMonth == 10) || (mMonth == 12))
  {
    if((aDay < 1) || (aDay > 31) || ((mMonth == 12) && (aDay == 25)) || ((mMonth == 1) && (aDay == 1)) || ((mMonth == 7) && (aDay == 4)))
    {
      throw PrecondViolatedExcep("Invalid Day.");
    }
    else
    {
      mDay = aDay;
    }
  }
  else if((mMonth == 4) || (mMonth == 6) || (mMonth == 9) || (mMonth == 11))
  {
    if((aDay < 1) || (aDay > 30))
    {
      throw PrecondViolatedExcep("Invalid Day.");
    }
    else
    {
      mDay = aDay;
    }
  }
  else if((mMonth == 2) && isLeapYear())
  {
    if((mMonth < 1) || (mMonth > 29))
    {
      throw PrecondViolatedExcep("Invalid Day.");
    }
    else
    {
      mDay = aDay;
    }
  }
  else
  {
    if((mMonth < 1) || (mMonth > 28))
    {
      throw PrecondViolatedExcep("Invalid Day.");
    }
    else
    {
      mDay = aDay;
    }
  }
}

void Event::setEventMonth(int aMonth) throw (PrecondViolatedExcep)
{
  if((aMonth < 1) || (aMonth > 12))
  {
    throw PrecondViolatedExcep("Invalid month.");
  }
  else
  {
    mMonth = aMonth;
  }
}

void Event::setEventYear(int aYear) throw (PrecondViolatedExcep)
{
  if(aYear < 2018)
  {
    throw PrecondViolatedExcep("Invalid year.");
  }
  else
  {
    mYear = aYear;
  }
}

void Event::setEventDate()
{
  std::string tempDay = std::to_string(mDay);
  std::string tempMonth = std::to_string(mMonth);
  std::string tempYear = std::to_string(mYear);

  mDate = tempMonth + '/' + tempDay + '/' + tempYear;
}
