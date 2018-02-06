/*----------------------------------------------------------------------------------------
File Name: LinkedList.h
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the header file for the Linked List class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include <string>
#include <iostream>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
	public:

/*
 * Preconditions: A call to the constructor for this object is made with no parameters.
 *
 * Postconditions: Creates a LinkedList item with itemCount = 0 and headptr pointing to a nullptr.
 *
 * Returns: N/A
 *
 */
  	 	LinkedList();

/*
 * Preconditions: A call to the constructor for this object is made with another LinkedList passed in as the parameters.
 *
 * Postconditions: Creates a LinkedList item that is a copy of the LinkedList passed in as a parameter.
 *
 * Returns: N/A
 *
 */
  	 	LinkedList(const LinkedList<ItemType>& aList);

/*
 * Preconditions: The end of the program is reached.
 *
 * Postconditions: Deletes all of the nodes in the list.
 *
 * Returns: N/A
 *
 */
 	    ~LinkedList();

/*
 * Preconditions: A call to this method is made.
 *
 * Postconditions: true is returned if the LinkedList item is empty and false if it is not
 *
 * Returns: true if the LinkedList item is empty and false if it is not
 *
 */
 	    bool isEmpty() const;

/*
 * Preconditions: A call to this method is made.
 *
 * Postconditions: Returns the value stored in the itemCount private variable
 *
 * Returns: int itemCount
 *
 */
   		int getLength() const;

/*
 * Preconditions: A call to this method is made and the position of the new Node and value the new Node will contain are passed in as parameters.
 *
 * Postconditions: A new Node is created for the LinkedList that contains newEntry as the info value.
 *
 * Returns: N/A
 *
 */
   		void insert(int newPosition, const ItemType& newEntry) throw (PrecondViolatedExcep);

/*
 * Preconditions: A call to this method is made and the position of the Node to be removed is passed in as parameters.
 *
 * Postconditions: Removes the node at the given position from the LinkedList.
 *
 * Returns: N/A
 *
 */
   		void remove(int position) throw (PrecondViolatedExcep);

/*
 * Preconditions: A call to this method is made.
 *
 * Postconditions: Removes every Node from the LinkedList.
 *
 * Returns: N/A
 *
 */
   		void clear();

/*
 * Preconditions: A call to this method is made with the position of the desired Node passed in as parameters.
 *
 * Postconditions: The info stored in the Node at the given position is returned.
 *
 * Returns: The info stored in the Node at the given position
 *
 */
   		ItemType getEntry(int position) throw(PrecondViolatedExcep);

/*
 * Preconditions: A call to this method is made with the position of the desired Node and the new information to be stored in the Node passed in as parameters.
 *
 * Postconditions: The info variable for the Node at the given position is set to newEntry.
 *
 * Returns: N/A
 *
 */
   		void setEntry(int position, const ItemType& newEntry)
                               throw(PrecondViolatedExcep);

/*
 * Preconditions: The = operater is used to instantiate a LinkedList object.
 *
 * Postconditions: The LinkedList object is being set equal to the LinkedList on the right hand side of the = operator.
 *
 * Returns: The LinkedList object on the left hand side of the = operator.
 *
 */
		LinkedList<ItemType>& operator=(LinkedList<ItemType> const &rhs);

	private:

   		Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   		int itemCount;           // Current count of list items

/*
 * Preconditions: Position is the number of the desired node; position >= 1 and position <= itemCount
 *
 * Postconditions: The node is found and a pointer to it is returned.
 *
 * Returns: A pointer to the node at the given position.
 *
 */
   		Node<ItemType>* getNodeAt(int position) const;
};

#include "LinkedList.hpp"
#endif
