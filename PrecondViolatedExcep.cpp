/*----------------------------------------------------------------------------------------
File Name: PrecondViolatedExcep.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the PrecondViolatedExcep class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.
