//Kevin Siraki - Lab Group 1.11 with Erick Gulyan and Nathan Arakel
//CS/IS 211
//Lab 3

#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"
#include <string>
#include <algorithm>
#include <iterator> // for iterators 
using namespace std;

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node
	int itemCount;           // Current count of bag items

	// Returns either a pointer to the node containing a given entry
	// or the null pointer if the entry is not in the bag.
	Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
	virtual ~LinkedBag();                       // Destructor should be virtual
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
	//added union and intersect
	LinkedBag<ItemType> Union(const LinkedBag<ItemType>& someBag) const;
	LinkedBag<ItemType> intersect(const LinkedBag<ItemType>& aBag) const;
}; // end LinkedBag



template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
		origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while

		newChainPtr->setNext(nullptr);              // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
	clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while

	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem)
	{
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());

		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	} // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;

		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr

	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->getNext();
	} // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
return getFrequencyOf(anEntry) > 0;
}
*/
/* ALTERNATE 2
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
bool found = false;
Node<ItemType>* curPtr = headPtr;
int i = 0;
while (!found && (curPtr != nullptr) && (i < itemCount))
{
if (anEntry == curPtr-<getItem())
{
found = true;
}
else
{
i++;
curPtr = curPtr->getNext();
}  // end if
}  // end while

return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;

	while (!found && (curPtr != nullptr))
	{
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while

	return curPtr;
} // end getPointerTo

//MODIFIED ADD FUNCTION!
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	// Add to END of chain:   
	Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry);
	if(isEmpty()) {
		itemCount++;
		headPtr = nextNodePtr;
		return true;
	}
	Node<ItemType>* curPtr = headPtr;
	while (curPtr->getNext() != nullptr) 
		curPtr = curPtr->getNext();
	curPtr->setNext(nextNodePtr);

	itemCount++;
	return true;
}  // end add

//FUNCTIONS I ADDED 

//UNION FUNCTION that puts two bags into one
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::Union(const LinkedBag<ItemType>& someBag) const {
	LinkedBag<ItemType> unionBag; //the new bag that will hold both bags
	vector<ItemType> unionBagVector = toVector(); //turn one of the bags into a vector and put it into unionBagVector
	vector<ItemType> someBagVector = someBag.toVector(); //turn one of the bags into vector and put it into the 
	for (int i = 0; i < someBagVector.size(); i++) 
		unionBagVector.push_back(someBagVector[i]); //putting one of the bags into the new union bag vector
	for (int i = 0; i < unionBagVector.size(); i++) 
		unionBag.add(unionBagVector[i]); //add the unionBagVector to the unionBag linked bag.... so as to return a linked bag instead of a vector
	return unionBag; //finally returning the entire linked bag (not as a vector of course)^^^^
} 


//intersect. find elements that are shared between two bags and return a bag with just those elements. 
/* one way, you can uncomment this code and comment out the other intersect to test it, it was an interesting approach I figured out for this problem. 
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::intersect(const LinkedBag<ItemType>& someBag) const {
	LinkedBag<ItemType> intersectionBag; //the new bag where we store the intersecting elements
	
	vector<ItemType> firstBagVector = toVector(); //the bag that this function is called on
	vector<ItemType> someBagVector = someBag.toVector(); //the bag that is passed to this function by const reference
	vector<ItemType> largeVect, smallVect;  //where we store the smaller and large vectors so we can compare THE LARGEST ONE TO the smallest.
	
	typename vector<ItemType>::iterator i; //iterator for the smaller vector
	
	if (firstBagVector.size() > someBagVector.size()) { //find the smaller vector
		largeVect = firstBagVector; 
		smallVect = someBagVector;
	}
	else {
		largeVect = someBagVector;
		smallVect =  firstBagVector;
	}
    for(i=smallVect.begin();i!=smallVect.end();i++) //check over the smaller vector
    	if(find(largeVect.begin(),largeVect.end(),*i)!=largeVect.end()) { //if the element is found between the two vectors and is not at the end of the larger vector
    		intersectionBag.add(*i); //add the item 
    		largeVect.erase(largeVect.begin()+distance(largeVect.begin(),find(largeVect.begin(), largeVect.end(), *i))); //find the number of elements until that item in the larger vector. erase that element from the larger vector (locally) so it does not repeat.
		}
	return intersectionBag; //finally, return the intersection
}
*/
//another way I found to do intersect.. I like this way more becasue there is no need for using import <algorithm> or <iterator>
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::intersect(const LinkedBag<ItemType>& aBag) const {
	 LinkedBag<ItemType> cBag,largeBag;
    vector<ItemType> aBagV = aBag.toVector();
    vector<ItemType> bagV = toVector();
    vector<ItemType> largeVect, smallVect;  
    if (aBagV.size() > bagV.size()) { 
		largeVect = aBagV; 
		smallVect = bagV;
	}
	else {
		largeVect = bagV;
		smallVect =  aBagV;
	}
	for(int i = 0; i<largeVect.size();i++)
        largeBag.add(largeVect[i]);
    for(int i=0;i<smallVect.size();i++) {
    	if(largeBag.contains(smallVect[i])) {
    		cBag.add(smallVect[i]);
    		largeBag.remove(smallVect[i]);
		}
	}
	return cBag;
}




#endif
