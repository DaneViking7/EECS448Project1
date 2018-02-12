/*----------------------------------------------------------------------------------------
File Name: PrecondViolatedExcep.h
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the header file for the PrecondViolatedExcep class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
  /** @brief constructor which takes an std::string error message from a throw as a parameter
  @pre an exception must be thrown
  @post takes in the exxception thrown and prints a message to the screen saying
    that an exception was caught. Then handles the exception and moves on.
  @return none**/
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep
#endif
