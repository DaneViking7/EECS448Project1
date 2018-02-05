/*
 *
 * File Name: Node.hpp
 * Used in program by: Niels Hansen
 * KUID: 2878265
 * Email Address: nahansen@ku.edu
 * Assignment: Lab 5
 * Description: Implementation file for the Node object.
 * Last Changed: 4 October 2017
 *
*/

#include"Node.h"
#include"string"

template<class ItemType>
Node<ItemType>::Node()
{
	next = nullptr;
	info="";
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem)
{
	next = nullptr;
	info = anItem;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
                info(anItem), next(nextNodePtr)
{}

template<class ItemType>
void Node<ItemType>::setInfo(const ItemType& inInfo)
{
	info = inInfo;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nxtPtr)
{
	next = nxtPtr;
}

template<class ItemType>
ItemType Node<ItemType>::getData() const
{
	return info;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}
