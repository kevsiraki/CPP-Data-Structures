//Group 1.11: Kevin Siraki, Erick Gulyan, Nathan Arakel
//Lab 5

#include <iostream>
#include "LinkedList.h"

template<class ItemType>
void displayList(const LinkedList<ItemType>& List)
{
	cout << endl;
	for (int i = 1; i <= List.getLength(); i++)
		cout << List.getEntry(i) << " ";
	cout << endl << endl;
}

int main() {
	LinkedList<int> intList;
	LinkedList<double> doubleList;
	LinkedList<string> stringList;
	
	for(int i=1;i<=5;i++) {
		intList.insert(i,i);
		doubleList.insert(i,i+0.1);
	}
	
	stringList.insert(1, "hello");
	stringList.insert(2, "world");
	stringList.insert(3, "largest is");
	stringList.insert(4, "z");
	stringList.insert(5, "get it");
	stringList.insert(5, ";)");

	cout << "intList: ";
	displayList(intList);
	cout << "doubleList: ";
	displayList(doubleList);
	cout << "stringList: ";
	displayList(stringList);
	
	//contains
	if (intList.contains(6))
		cout << "yes";
	else
		cout << "no";
	cout << endl;


	if (doubleList.contains(2.1))
		cout << "yes";
	else
		cout << "no";
	cout << endl;


	if (stringList.contains("get it"))
		cout << "yes";
	else
		cout << "no";
	cout << endl<<endl;
	
	//largest
	cout << "Largest int: " << intList.findLargest() << endl;
	cout << "Largest double: " << doubleList.findLargest() << endl;
	cout << "Largest (alphabetically) string: " << stringList.findLargest() << endl;
	cout << endl<<endl;
	
	//getlast (tail)
	cout << "Last int: " << intList.getLast() << endl;
	cout << "Last double: " << doubleList.getLast() << endl;
	cout << "Last string : " << stringList.getLast() << endl;
	cout << endl;
	
	
	return 0;
}
