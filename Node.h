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

/**
 @pre Call to the Node constructor is made with no parameters.
 @post A Node item is created with the next private variable pointing to a nullptr and the info variable set to empty.
 @return N/A **/
		Node();

/**
 @pre Call to the Node constructor is made with ItemType as a parameter.
 @post A Node item is created with the next private variable pointing to a nullptr and the info variable set to anItem.
 @return N/A
 **/
		Node(const ItemType& anItem);

/**
 @pre Call to the Node constructor is made with an item of ItemType and a pointer to the next node as the parameters.
 @post A node item is created with the next private variable pointing to the provided pointer and the info variable set to anItem.
 @return N/A
 **/
		Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

/**
 @pre Call to this method is made and an ItemType is passed in as a parameter.
 @post Sets the info private variable to inInfo.
 @return N/A
 **/
		void setInfo(const ItemType& inInfo);

/**
 @pre Call to this method is made and a pointer to another Node object is passed in as a parameter.
 @post Sets the next private variable to nxtPtr.
 @return N/A
 **/
		void setNext(Node<ItemType>* nxtPtr);

/**
 @pre Call to this method is made.
 @post Returns the value stored in the info private variable.
 @return ItemType info
 **/
		ItemType getData() const;

/**
 @pre call to this method is made.
 @post Returns the value stored in the next private variable.
 @return Node<ItemType>* next
 **/
		Node<ItemType>* getNext() const;

	private:

		ItemType info;; //!< holds the node's information

		Node<ItemType>* next; //!< points to next node
};
#include "Node.hpp"
#endif
