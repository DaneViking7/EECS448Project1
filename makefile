Project1: main.o Executive.o Time.o Event.o PrecondViolatedExcep.o
	g++ -std=c++11 -g -Wall main.o Executive.o Time.o Event.o PrecondViolatedExcep.o -o Project1
main.o: main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp Executive.h Time.h Event.h
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
Time.o: Time.cpp Time.h
	g++ -std=c++11 -g -Wall -c Time.cpp
Event.o: Event.cpp Event.h
	g++ -std=c++11 -g -Wall -c Event.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp
clean:
	rm *.o Project1
