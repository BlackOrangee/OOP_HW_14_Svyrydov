#pragma once
#include <iostream>

using namespace std;

class Stack
{
public:
	int value;     // Value stored in the stack node
	Stack* next;   // Pointer to the next node in the stack (nullptr for the last node)

	Stack();       // Default constructor for creating an empty node
	Stack(int);    // Constructor for creating a node with an initial value
};

Stack* addToStack(Stack*, int);          // Function to add a new node with a value to the stack
int readLast(Stack*);                    // Function to read the value of the last node in the stack
int readAndRemove(Stack*&);              // Function to read and remove the last node in the stack
void display(Stack*);                    // Function to display the values in the stack
Stack* compare(Stack*, Stack*);          // Function to compare and process two stacks
