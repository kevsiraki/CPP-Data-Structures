//Kevin Siraki - Lab Group 1.11 
//CS/IS 211
//Lab 6

#include <iostream>
#include "LinkedBag.h"
#include <chrono> //for benchmark analysis 
using namespace std;

template<class T> //return the last item in the bag, used for removing the smallest string in the list
T getSmallest(const LinkedBag<T>& someBag) {
	vector<T> bagVect = someBag.toVector();
	return bagVect[bagVect.size() - 1];
}

template<class T> //return the first item in the bag, used for removing the largest string in the list
T getLargest(const LinkedBag<T>& someBag) { 
	vector<T> bagVect = someBag.toVector();
	return bagVect[0];
}

template<class T> //prints the bag
void printBag(const LinkedBag<T>& someBag) {
	vector<T> bagVect = someBag.toVector();
	for (int i = 0; i < bagVect.size(); i++)
		cout << bagVect[i] << " ";
	cout << endl;
}

int main() {
	LinkedBag<string> initialStringBag;
	string stringToBeRemoved, initialString;
	cout << "Enter the initial string: ";
	cin >> initialString;
	initialStringBag.add(initialString);
	cout << "Initial string: " << initialString << ". Enter L to remove the largest string on each iteration, S to remove the smallest string on each iteration, or neither to do it yourself. " << endl;
	char choice;
	cin >> choice;
	switch (choice) {
	case 'l':
	case 'L': { //for some reason, auto was not working in switch statements so I thought to encapsulate each case in curly braces because it seemed c++ had an issue with scope.
		int i = 1;
		auto start = chrono::high_resolution_clock::now();
		while (!initialStringBag.isEmpty()) {
			stringToBeRemoved = getLargest(initialStringBag);
			cout << i<<". Removing: " << stringToBeRemoved<<endl;
			initialStringBag.remove(stringToBeRemoved);
			if (stringToBeRemoved.size() > 1) { //if it isnt a one letter word
				initialStringBag.add(stringToBeRemoved.substr(1)); //removes the first letter of the string, adds remaining string to the bag
				initialStringBag.add(stringToBeRemoved.substr(1)); //removes the first letter of the string, adds remaining string to the bag
				//done twice because getting rid of 1 "head" causes 2 more heads to emerge.
			}
			i++;
		}
		cout << "Hydra is dead!" << endl;
		auto stop = chrono::high_resolution_clock::now();
		auto time = chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
		cout << "Time for removing largest string on each iteration: " << time << " nanoseconds"<<endl;
		break;
	}
	case 's':
	case 'S': {
		int i = 1;
		auto start = chrono::high_resolution_clock::now();
		while (!initialStringBag.isEmpty()) {
			stringToBeRemoved = getSmallest(initialStringBag);
			cout << i << ". Removing: " << stringToBeRemoved << endl;
			initialStringBag.remove(stringToBeRemoved);
			if (stringToBeRemoved.size() > 1) { //if it isnt a one letter word
				initialStringBag.add(stringToBeRemoved.substr(1)); //removes the first letter of the string, adds remaining string to the bag
				initialStringBag.add(stringToBeRemoved.substr(1)); //removes the first letter of the string, adds remaining string to the bag
				//done twice because getting rid of 1 "head" causes 2 more heads to emerge.
			}
			i++;
		}
		cout << "Hydra is dead!" << endl;
		auto stop = chrono::high_resolution_clock::now();
		auto time = chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count(); 
		cout << "Time for removing smallest string on each iteration: " << time << " nanoseconds"<<endl;
		break;
	}
	default: {
		while (!initialStringBag.isEmpty() ) {
			cout << "\nString bag: ";
			printBag(initialStringBag);
			cout << "Enter the string to be removed: ";
			cin >> stringToBeRemoved;
			if (initialStringBag.contains(stringToBeRemoved)) { //to make sure the user doesnt input another string
				initialStringBag.remove(stringToBeRemoved);
				if (stringToBeRemoved.size() > 1) { //if it isnt a one letter word
					initialStringBag.add(stringToBeRemoved.substr(1)); //removes the first letter of the string, adds remaining string to the bag
					initialStringBag.add(stringToBeRemoved.substr(1)); //removes the first letter of the string, adds remaining string to the bag
					//done twice because getting rid of 1 "head" causes 2 more heads to emerge.
				}
			}
			else cout << "Not found"<<endl; //if they entered an invalid string to remove
			
		}
		cout << "Hydra is dead!" << endl;
		break;
	}
	}
	system("PAUSE");
	return 0;
}
//initial string is: test
//Time for removing largest string every time with initial string as test: 1380300 nanoseconds
// Time for removing smallest string on each iteration : 1077100 nanoseconds
//the worst-case big O for hydra was O((2^l)-1), where l is the length of the initial string
//this big-o proved correct when i printed the number of iterations the while loop went through for solving hydra
//the big-o I came up with also made sense because the time complexity seemed to double in growth as the string increased in length
//also, benchmark analysis showed that removing the smaller string first was faster than removing the largest string first
//benchmark analysis does not focus on bigger inputs so I think my big-o is a more accurate representation for the complexity of hydra.
