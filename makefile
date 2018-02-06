Project1: main.o Executive.o Time.o Event.o
	g++ -std=c++11 -g -Wall main.o Executive.o Time.o Event.o -o Project1
main.o: main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
Time.o: Time.cpp
	g++ -std=c++11 -g -Wall -c Time.cpp
Event.o: Event.cpp
	g++ -std=c++11 -g -Wall -c Event.cpp
clean:
	rm *.o Project1
