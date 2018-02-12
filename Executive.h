/*----------------------------------------------------------------------------------------
File Name: Executive.h
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the header file for the Executive class.
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "LinkedList.h"
#include "Event.h"

class Executive
{
public:
  /** @brief constructor
    @pre none
    @post sets up executive class, then calls on run()
    @return none**/
  Executive();

  /** @brief destructor
    @pre none
    @post none
    @return none**/
  ~Executive();

  /**
    @pre none
    @post Allows for the creation of an event. Also allows the user to check the attendees of the events.
    @return none**/
  void adminMode();

  /**
    @pre none
    @post Allows the user to see a list of events that have been created. If they select an event they can add their availability for each time slot.
    @return none**/
  void availMode();

  /**
    @pre none
    @post
    @return none**/
  void run();

private:

  LinkedList<Event>* events; //!< stores the events that have been created**/

}; //end Executive.h
#endif
