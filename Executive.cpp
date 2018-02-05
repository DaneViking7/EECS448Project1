/*----------------------------------------------------------------------------------------
File Name: Executive.cpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Executive class.
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/
#include "Executive.h"

Executive::Executive(std::string fileName)
{
  char validFile = 'Y';

  inFile.open(fileName);

  if (inFile.good() && inFile.is_open()) //check to see if file is good
  {
    run(); //call method run()
    inFile.close();
  }
  else //file was not good...
  {
    do
    {
      std::cout<<"\nFile does not exist.\n";
      std::cout<<"Enter a valid file name: ";
      std::cin>>fileName;

      inFile.open(fileName);

      if (inFile.good() && inFile.is_open()) //check to see if file is good
      {
        run(); //call method run()
        inFile.close();
        validFile = 'Y';
      }
      else
      {
        validFile = 'N';
      }

    } while(validFile == 'N'); //loop until valid file is provided
  }
}

Executive::~Executive()
{

}

void Executive::run()
{

}
