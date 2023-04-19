#include "linkedlist.h"
#include <iostream>
using namespace std;

node::node() {
	value = 0; // default values
	occurrences = 1;
	next = NULL;
}

node::node(int n) { // sets the vale to the given one
	value = n;
	occurrences = 1;
	next = NULL;
}

linkedList::linkedList() { // default constructor for linkedList sets head to point at NULL
	head = NULL;
}

void linkedList::addNode(node n) {
	node* add = new node(); // declaring a new node and sets its value to the given one
	add->value = n.value;
	add->occurrences = n.occurrences;
	if (!head) { // if head is pointing at NULL, then it points at the added one
		head = add;
	}
	else {
		node* temp = head; //otherwise, it loops through the list until it reaches the end, then sets the next one to the added node
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = add;

	}

}

void linkedList::removeNode(int index) {
	if (!head) { // if head is pointing at NULL, nothing can be deleted, and an error message is shown instead
		cout << "Cannot delete because the list is empty" << endl;
	}
	else if (index == 1) { // if its the first one, then head points to the next one
		head = head->next;
	}
	else {
		node* temp = head; // temp points to head
		node* temp2 = head;
		int counter = 1; // initializes counter to 1
		while (temp->next && counter != index - 1) { // transverses through the list until temp is equal to null or the counter is equal to index -1
			temp = temp->next;
			counter++;
		}
		if (counter == index - 1 && temp->next) { // if the counter is equal to the index-1, temp's next is equal to the next next, skipping over the index
			temp2 = temp;
			temp= temp->next;
			temp2->next = temp->next;
			delete temp;
		}
		else {
			cout << "Index does not exist in the list!" << endl; // else, print an error message that the index does not exist
		}
	}
}

void linkedList::print() {
	if (!head) { // if head is pointing at NULL, the list must be empty
		cout << "Sorry the list is empty." << endl;
	}
	else {
		node* temp = head; // temp points to head
		while (temp != NULL) { // transverses through the list and prints the values and occurences
			cout << "Value: " << temp->value << "| Occurences: " << temp->occurrences << endl;
			temp = temp->next;
		}
	}
}

int linkedList::sum() {
	node* temp = head; // temp points to head
	int sum =0; // initializes sum to 0
	while (temp != NULL) { // tranverses through the list
		sum = sum + temp->value * temp->occurrences; // sum is equal to sum plus the value multiplies by the occurences
		temp = temp->next;
	}
	return sum; // returns back the sum
}

// refrence: https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/