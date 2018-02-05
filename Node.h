/*
 *
 * File Name: Node.h
 * Used in program by: Niels Hansen
 * KUID: 2878265
 * Email Address: nahansen@ku.edu
 * Assignment: Lab 5
 * Description: Header file for the Node object. This is the object that the LinkedList object stores. They contain a piece of info of a given type and a pointer to the next Node in the list.
 * Last Changed: 4 October 2017
 *
*/

#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

template<class ItemType>
class Node
{
	public:

/*
 * Preconditions: Call to the Node constructor is made with no parameters.
 *
 * Postconditions: A Node item is created with the next private variable pointing to a nullptr and the info variable set to empty.
 *
 * Returns: N/A
 *
 */	
		Node(); 

/*
 * Preconditions: Call to the Node constructor is made with ItemType as a parameter.
 *
 * Postconditions: A Node item is created with the next private variable pointing to a nullptr and the info variable set to anItem.
 *
 * Returns: N/A
 *
 */	
		Node(const ItemType& anItem);

/*
 * Preconditions: Call to the Node constructor is made with an item of ItemType and a pointer to the next node as the parameters.
 *
 * Postconditions: A node item is created with the next private variable pointing to the provided pointer and the info variable set to anItem.
 *
 * Returns: N/A
 *
 */	
		Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

/*
 * Preconditions: Call to this method is made and an ItemType is passed in as a parameter.
 *
 * Postconditions: Sets the info private variable to inInfo.
 *
 * Returns: N/A
 *
 */	
		void setInfo(const ItemType& inInfo);

/*
 * Preconditions: Call to this method is made and a pointer to another Node object is passed in as a parameter.
 *
 * Postconditions: Sets the next private variable to nxtPtr.
 *
 * Returns: N/A
 *
 */	
		void setNext(Node<ItemType>* nxtPtr);

/*
 * Preconditions: Call to this method is made.
 *
 * Postconditions: Returns the value stored in the info private variable.
 *
 * Returns: ItemType info
 *
 */	
		ItemType getData() const;

/*
 * Preconditions: call to this method is made.
 *
 * Postconditions: Returns the value stored in the next private variable.
 *
 * Returns: Node<ItemType>* next
 *
 */	
		Node<ItemType>* getNext() const;

	private:

		ItemType info;; //holds the node's information

		Node<ItemType>* next; //points to next node
};
#include "Node.hpp"
#endif
