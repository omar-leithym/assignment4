#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

// reference: https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/

void insertAfter(int firstValue, int secondValue, vector<int> &vec, int size) { //insertAfter function
	for (int i = 0; i < size; i++) { // loops through the vector
		if (vec[i] == firstValue) { // if the value is the same as the first value, change it to the second one
			vec[i] = secondValue;
		}
	}
}

linkedList makeList(vector<int> &vec, int size) { //makeList function
	linkedList list; // declare a linkedList
	for (int i = 0; i < size - 1; i++) { // bubble sorts the vector to make it in ascending order
		for (int j = i; j < size; j++) {
			if (vec[i] > vec[j]) {
				swap(vec[i], vec[j]);
			}
		}
	}
	int* arr = new int[size * 2]; // declaring an int array double the size of the vector
	int min = vec[0]; // the minimum is set to the first element of the vector
	arr[0] = min; // the first element of the array is the minimum
	int counter = 0; // initializing counter and elements to 0 
	int elements = 0;
	for (int i = 0; i < size; i++) { // loops through the size of the vector
		if (vec[i] == min) { // if the value is equal to the minimum, counter increments +1
			counter++;
		}
		else { // else its a new value 
			arr[elements] = min; // adds the previous value of min to the array
			arr[elements + 1] = counter; // adds the counter to the array which is the number of times this value was seen in the vector
			min = vec[i]; // minimum is equal to the new value in the vector
			counter = 1; // counter resets to one
			elements = elements + 2; // a new 
		}
	}
	arr[elements] = min; // the position in the array is equal to min
	arr[elements + 1] = counter; // the position right after is how many times it showed up
	elements = elements + 2; // increments elements + 2
	for (int i = 0; i < elements; i = i + 2) { // loops through the array i+2
		node n; // declares a node
		n.value = arr[i]; // the node's value is equal to the first position
		n.occurrences = arr[i + 1]; // the node's occurrences is equal to the second position
		list.addNode(n); // adds the node to the list
	}
	delete[] arr;
	return list;
}

int main() {
	int size; // declaring size
	cout << "Please enter the size of the vector: "; // asking the user to enter the size of the vector
	cin >> size; 
	vector<int> vec;
	vec.reserve(size); // creates a new vector and sets the capacity to the size
	int num;
	for (int i = 0; i < size; i++) {
		cout << "please enter the value for number " << i + 1<<": "; // loops through the vector and asks the user to input the values
		cin >> num;
		vec.insert(vec.begin() + i, num); // inserts the values
	}
	int first, second; 
	cout << "Please enter the first value: "; // declaring the first and second value and asks the user to input them
	cin >> first;
	cout << "Please enter the second value: ";
	cin >> second;
	insertAfter(first, second, vec, size); // runs the vector through the function
	linkedList list = makeList(vec, size); // uses the function to make a linkedList with the vector
	list.print(); // prints the content of the list
	cout << "The sum is: " << list.sum(); // prints the sum of the list
}