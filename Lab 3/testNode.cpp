#include "Node.h"
#include <iostream>
using namespace std;

int main() {
	Node<int>* head = nullptr; //initializing the head of the empty list.
	
	Node<int>* next = new Node<int>(7); //creating a head for the list. in this case i made a list of ints.
	head = next;						//by saying head=next, i basically am setting the data in head to 7.
	
	next = new Node<int>(8); 			//now i need to add more nodes. here i just made next into a new node that will contain 8. 
	Node<int>* curPtr = head;			//pay attention to this part.. i create another node ptr called curPtr and set it equal to head. this way i can start from the head ptr and keep adding links to the end.
	while (curPtr->getNext() != nullptr) { //while the currentPtr's (head in this case)... next node is not nullptr...
		curPtr = curPtr->getNext();			//set curPtr to the next node in the list (8 in our case to keep shit simple).
	}
	curPtr->setNext(next);					//setting curPtr's next member variable WHICH CONTAINS AN ADDRESS TO NEXT to the next address of next (which is the address of 8).
	
	next = new Node<int>(9);				//I do the same thing to add 9 to the list.
	while (curPtr->getNext() != nullptr) {
		curPtr = curPtr->getNext();
	}
	curPtr->setNext(next);
	
	next = new Node<int>(10);				//I do the same thing to add 10 to the list.
	while (curPtr->getNext() != nullptr) {
		curPtr = curPtr->getNext();
	}
	curPtr->setNext(next);
	
	next = new Node<int>(69);				//I do the same thing to add 69 to the list.
	while (curPtr->getNext() != nullptr) {
		curPtr = curPtr->getNext();
	}
	curPtr->setNext(next);
	
	curPtr=head;							//now I want to print the entire list. First, I need to set curPtr back to head because it is still on next. You can also change this to not use curPtr but it makes it easy to read.
	while(curPtr != nullptr) {				//while our curPtr is not null (on this first iteration it is on head so it obviously isnt)...she showed this in class with an itemCount variable but this list is so simple it would be useless.
		cout<< curPtr->getItem()<<endl;		//print the current item
		curPtr = curPtr->getNext();			//set curPtr to the next item
	}
	
	return 0;
}

/*in the  while loop above, this is exactly what happens step by step. :

1. curPtr is at the head. the head's contents (0 nodes away from the head) are printed. curPtr now points 1 ahead of the head.
2. the element 1 nodes away from the head is printed. curPtr now points 2 ahead of the head.
3. the element 2 nodes away from the head is printed. curPtr now points 3 ahead of the head.
4. the element 3 nodes away from the head is printed. curPtr now points 4 ahead of the head.
5. curPtr will now be nullptr as we are 4 nodes away from the head while the indices were 0 1 2 3. The loop terminates.

JOGUMES?????????????????
*/
