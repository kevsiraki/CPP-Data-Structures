/*
Kevin Siraki, Nathan Arakel,and Erick Gulyan (Group 1.11)
Lab 2
CS 211
*/
#include <iostream>
#include <string>
using namespace std;

int recursivePower(int, int);
template <class T>
T maxArray(T arr[],int len);
template <class T, class F>
bool binarySearch(T arr[], int left, int right, F toFind);
int reverseDigits(int);

int main() {
	const int SIZE = 5;
	//random arrays for maxArray
	int intArray[SIZE] = {1,200,3,4,5};
	double doubleArray[SIZE] = {1.1,2.2,33.3,4.4,5.5};
	string stringArray[SIZE] = {"This","is","a","test","array"};
	//presorted arrays for binary search
	int sortedIntArray[SIZE] = {1,2,3,4,5};
	double sortedDoubleArray[SIZE] = {1.1,2.2,3.3,4.4,5.5};
	string sortedStringArray[SIZE] = {"aa","bb","cc","dd","ee"};
	//random sequences of digits for reverseDigits
	int randomDigitsOne = 12345;
	int randomdigitsTwo = 10111213;
	int randomDigitsThree = 420716;
	int randomDigitsFour = 456780;
	//testing 4 random base/powers for recursivePower
	cout<<"Testing recursivePower 5^2: "<<recursivePower(5,2)<<endl;
	cout<<"Testing recursivePower 10^3: "<<recursivePower(10,3)<<endl;
	cout<<"Testing recursivePower 6^6: "<<recursivePower(6,6)<<endl;
	cout<<"Testing recursivePower 2^6: "<<recursivePower(2,6)<<endl<<endl;
	//testing 3 types of arrays for maxArray
	cout<<"Testing maxArray on ints: "<<maxArray(intArray,SIZE)<<endl;
	cout<<"Testing maxArray on doubles: "<<maxArray(doubleArray,SIZE)<<endl;
	cout<<"Testing maxArray on string: "<<maxArray(stringArray,SIZE)<<endl<<endl;
	//testing 3 types for binarySearch
	cout<<"Testing binarySearch on ints: "<<binarySearch(sortedIntArray, 0, SIZE-1, 40)<<endl;
	cout<<"Testing binarySearch on doubles: "<<binarySearch(sortedDoubleArray, 0, SIZE-1, 2.2)<<endl;
	cout<<"Testing binarySearch on strings: "<<binarySearch(sortedStringArray, 0, SIZE-1, "aa")<<endl<<endl;
	//testing 4 sequences of digits for randomDigits
	cout<<"Testing reverseDigits on "<<randomDigitsOne<<": ";
	reverseDigits(randomDigitsOne);
	cout<<endl;
	cout<<"Testing reverseDigits on "<<randomdigitsTwo<<": ";
	reverseDigits(randomdigitsTwo);
	cout<<endl;
	cout<<"Testing reverseDigits on "<<randomDigitsThree<<": ";
	reverseDigits(randomDigitsThree);
	cout<<endl;
	cout<<"Testing reverseDigits on "<<randomDigitsFour<<": ";
	reverseDigits(randomDigitsFour);
	cout<<endl;
	return 0;
}

//1
//precondition: must have 2 integer parameter, one that is the base and one that is the exponent. all passed by value.
//we also assume that a is a real number and that n>=0
//if n is 1 we return a.
//postconditions: must return an integer.
int recursivePower(int a,int n) {	
	if(n==1) 
		return a;
	else if(n==0) 
		return 1;
	else 
		return a*recursivePower(a,n-1);
}

//2
//precondition: must take in an array of anny type and the length of the array (int) as parameters. all passed by value except the array.
//if len is 1 we return the 0th index of the array.
//post condition: returns an integer corresponding to the maximum value of the array.
template <class T>
T maxArray(T arr[],int len) {
	if(len==1) 
		return arr[0];
	else {
		T max = maxArray(arr,len-1);
		if( arr[len-1] > max) 
			return arr[len-1];
		else 
			return max;
	}
}

//3
//precondition: must take in a sorted array of any type, the leftmost index (0) of the array, the rightmost index of the array (size-1), and a value of any type to find. all passed by value except the array.
//if the index on the right of the array is greater than or equal to the index on the left of the array, we set the middle variable to the middle of the array.
//if the middle element is what we are looking for, return true.
//if the middle element is greater than what we are looking for, we call the function again.
//or else, false.
//postcondition: returns a boolean value. true(1) if the item is found and false(0) if it is not.
template <class T, class F>
bool binarySearch(T arr[], int left, int right, F toFind) { 
    if (right >= left) { 
        int middle = left + (right - left) / 2; 
        if (arr[middle] == toFind) 
            return true; 
        if (arr[middle] > toFind) 
            return binarySearch(arr, left, middle - 1, toFind); 
        return binarySearch(arr, middle + 1, right, toFind); 
    } 
    return false; 
} 

//4
//precondition: takes in one integer parameter by value
//if toReverse is 0, we return toReverse.
//postcondition: returns an integer (Reverses the parameter), prints the first digit.
int reverseDigits(int toReverse) {
	if(toReverse==0) 
        return toReverse;
    else {
    	cout<<toReverse%10;
        return reverseDigits(toReverse/10); 
    }
}
