/*----------------------------------------------------------------------------------------
File Name: Node.h
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the header file for the Node class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/

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
