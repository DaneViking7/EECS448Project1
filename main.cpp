/*----------------------------------------------------------------------------------------
File Name: main.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the main.cpp file that declares an instance of Executive.
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include <iostream>
#include "Executive.h"
#include <string>

int main(int argc, char* argv[])
{
  //checks to make sure the correct number of arguments were passed through the command line.
  if (argc != 2)
  {
    std::cout<<"Invalid number of arguments.\n"; //if incorrect number of arguements, tell user, exit.
  }
  else
  {
    Executive exec(argv[1]); /*declares and creates object of Executive Class;
        calls constructor that takes the file name stored in argv[1] as a parameter*/
  }

  return(0);
}
