#pragma once

struct node {
	int value;
	int occurrences;
	node* next;
	node(); // default constructor
	node(int n); // constructor that sets the value
};

class linkedList {
private:
	node* head;
public:
	linkedList(); // default constructor
	void addNode(node n);  // function to add a node
	void removeNode(int index); // function to remove a node with the index
	void print(); // function to print the content of the list
	int sum(); // function that returns the sum of the list
};

// refrence: https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/