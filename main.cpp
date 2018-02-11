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
using namespace std;

int main(int argc, char* argv[])
{
  
	Executive myExecutive;/*declares and creates object of Executive Class;
        calls constructor that takes the file name stored in argv[1] as a parameter*/
	myExecutive.run();
	return(0);
}
