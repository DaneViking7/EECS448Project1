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

class Executive
{
public:
  /*constructor
    @pre none
    @post sets up executive class, then calls on run()
    @return none*/
  Executive(std::string fileName);

  /*destructor
    @pre none
    @post none
    @return none*/
  ~Executive();

  /*
    @pre none
    @post
    @return none*/
  void run();

private:
  /*the file reader*/
  std::ifstream inFile;

}; //end Executive.h
#endif
