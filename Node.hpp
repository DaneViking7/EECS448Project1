/*----------------------------------------------------------------------------------------
File Name: Node.hpp
Authors: Natalie LaLuzerne, Annika Kuhnke, Niels Hansen, Aldin Tollison
Project Number: 01
Description: This is the implementation file for the Node class
Date Due: 02/12/18
----------------------------------------------------------------------------------------*/

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
