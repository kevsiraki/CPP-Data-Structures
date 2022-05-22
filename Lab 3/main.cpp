//Kevin Siraki - Lab Group 1.11 with Erick Gulyan and Nathan Arakel
//CS/IS 211
//Lab 3

#include <iostream>
#include <string>
#include "LinkedBag.h"
using namespace std;

template<class ItemType>
void displayBag(LinkedBag<ItemType>& bag) { //basically just modified the one from the author to have no STDs LOL 
    vector<ItemType> bagItems = bag.toVector();
    int numberOfEntries = (int) bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
        cout << bagItems[i] << " ";
    cout << endl;
}  



int main() {
	//just to prove it works on all types of bags...
	
	//int string and double bags
    LinkedBag<int> intBag1,intBag2;
    LinkedBag<string> stringBag1,stringBag2;
    LinkedBag<double> doubleBag1,doubleBag2;
    
    //int bags.
    //first int bag:
    intBag1.add(1);
    intBag1.add(5);
    intBag1.add(2);
    intBag1.add(1);
    intBag1.add(3);
    //second int bag:
    intBag2.add(11);
    intBag2.add(3);
    intBag2.add(3);
    intBag2.add(32);
    intBag2.add(3);
    intBag2.add(434);
    intBag2.add(66);
    
    //string bags
    //first string bag
    stringBag1.add("hi");
    stringBag1.add("there");
    stringBag1.add("professor");
    //second string bag
    stringBag2.add("hi");
    stringBag2.add("kevin");
    stringBag2.add("siraki");
    stringBag2.add("!!!!!!!!");
    
    //double bags
    //first double bag
    doubleBag1.add(1.1);
    doubleBag1.add(1.2);
    doubleBag1.add(1.1);
    doubleBag1.add(1.32);
    doubleBag1.add(1.111);
	//second double bag    
    doubleBag2.add(1.441);
    doubleBag2.add(1.1);
    doubleBag2.add(1.111);
    doubleBag2.add(122.1);
    
    //display the initial bags...
    cout<<"intBag1: ";
    displayBag(intBag1);
    cout<<"intBag2: ";
    displayBag(intBag2);
    cout<<"stringBag1: ";
    displayBag(stringBag1);
    cout<<"stringBag2: ";
    displayBag(stringBag2);
    cout<<"doubleBag1: ";
    displayBag(doubleBag1);
    cout<<"doubleBag2: ";
    displayBag(doubleBag2);
    cout<<endl;
    
    //testing 
    //union and intersection of ints no remove or clear
    LinkedBag<int> unionInt12(intBag1.Union(intBag2));
    LinkedBag<int> intersectInt12(intBag1.intersect(intBag2));
    cout<<"Union of intBag1 and intBag2: ";
    displayBag(unionInt12);
    cout<<"Intersection of intBag1 and intBag2: ";
    displayBag(intersectInt12);
    cout<<endl;
    
    //union and intersection of ints with remove
    cout << "Same as above but with 3 removed from intBag1: "<<endl;
	intBag1.remove(3);
	LinkedBag<int> removeUnionInt12(intBag1.Union(intBag2));
	LinkedBag<int> removeIntersectIntBag12(intBag1.intersect(intBag2));
	cout<<"Union of intBag1 and intBag2: ";
	displayBag(removeUnionInt12);
	cout<<"Intersection of intBag1 and intBag2: ";
	displayBag(removeIntersectIntBag12);
	cout<<endl;
	
	//union and intersection of ints with clear
	cout << "Same as above but intBag1 cleared: " << endl;
	intBag1.clear();
	LinkedBag<int> clearUnionInt12(intBag1.Union(intBag2));
	LinkedBag<int> clearIntersectIntBag12(intBag1.intersect(intBag2));
	cout<<"Union of intBag1 and intBag2: ";
	displayBag(clearUnionInt12);
	cout<<"Intersection of intBag1 and intBag2: ";
	displayBag(clearIntersectIntBag12);
	cout<<endl;
	
	//union and intersection of strings:
	LinkedBag<string> unionString12(stringBag1.Union(stringBag2));
    LinkedBag<string> intersectString12(stringBag1.intersect(stringBag2));
    cout<<"Union of stringBag1 and stringBag2: ";
    displayBag(unionString12);
    cout<<"Intersection of stringBag1 and stringBag2: ";
    displayBag(intersectString12);
    cout<<endl;
    
    //union and intersection of doubles:
	LinkedBag<double> unionDouble12(doubleBag1.Union(doubleBag2));
    LinkedBag<double> intersectDouble12(doubleBag1.intersect(doubleBag2));
    cout<<"Union of doubleBag1 and doubleBag2: ";
    displayBag(unionDouble12);
    cout<<"Intersection of doubleBag1 and doubleBag2: ";
    displayBag(intersectDouble12);
    cout<<endl;
    
    system("pause");
    return 0;
}  











