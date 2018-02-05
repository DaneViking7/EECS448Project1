//  Adapted from code by Frank M. Carrano and Tim Henry.+
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
/*
 *
 * File Name: LinkedList.hpp
 * Used in program by: Niels Hansen
 * KUID: 2878265
 * Email Address: nahansen@ku.edu
 * Assignment: Lab 5
 * Description: Implementation file for the LinkedList object.
 * Last Changed: 4 October 2017
 *
*/

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
		if(aList.itemCount == 0)
			headPtr = NULL;
		else
		{
			itemCount = aList.itemCount;
			this->clear();
			Node<ItemType>* origPtr, lastPtr;
			origPtr = aList.headPtr;
			lastPtr = new Node<ItemType>(origPtr->info);
			headPtr = lastPtr;
			Node<ItemType>* temp;
			while(origPtr != NULL)
			{
				temp = new Node<ItemType>(origPtr->info);
				lastPtr->next = temp;
				lastPtr = lastPtr->next;
				origPtr = origPtr->next;
			}
		}
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   	if(itemCount ==0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
	
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
} 

template<class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
	throw (PrecondViolatedExcep)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
     
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry); 
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }
	else
		throw PrecondViolatedExcep("Cannot insert element");
}  // end insert

template<class ItemType>
void LinkedList<ItemType>::remove(int position) throw(PrecondViolatedExcep)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }
	else
		throw PrecondViolatedExcep("Cannot remove item");
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) throw(PrecondViolatedExcep)
{
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getData();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   //assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)   throw(PrecondViolatedExcep)
{
	bool ableToEnter = (position >= 1) && (position <= itemCount);
	if (ableToEnter){
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setInfo(newEntry);
	}
	else{
		throw PrecondViolatedExcep("That node does not exist.");
	}
}

template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(LinkedList<ItemType> const &rhs)
{
	if(this != &rhs)
	{
		itemCount = rhs.itemCount;
		if(rhs.itemCount == 0)
			headPtr = NULL;
		else
		{
			itemCount = rhs.itemCount;
			this->clear();
			Node<ItemType>* origPtr, lastPtr;
			origPtr = rhs.headPtr;
			lastPtr = new Node<ItemType>(origPtr->info);
			headPtr = lastPtr;
			Node<ItemType>* temp;
			while(origPtr != NULL)
			{
				temp = new Node<ItemType>(origPtr->info);
				lastPtr->next = temp;
				lastPtr = lastPtr->next;
				origPtr = origPtr->next;
			}
		}
	}
	return *this;
}
