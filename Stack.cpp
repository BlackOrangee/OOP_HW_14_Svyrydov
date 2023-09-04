#include "Stack.h"

// Constructor for an empty stack node
Stack::Stack()
{
	value = 0;
	next = nullptr;
}

// Constructor for a stack node with a given value
Stack::Stack(int value)
{
	this->value = value;
	next = nullptr;
}

// Function to add a new node with a value to the stack
Stack* addToStack(Stack* stack, int value)
{
	Stack* n = new Stack(value);

	// If the stack is empty, set the new node as the stack
	if (stack == nullptr)
	{
		stack = n;
		return stack;
	}

	// Set the new node's 'next' pointer to the current stack
	n->next = stack;

	return n; // Return the new stack with the added node
}

// Function to read the value of the top node in the stack
int readLast(Stack* stack)
{
	return stack->value;
}

// Function to read and remove the top node from the stack
int readAndRemove(Stack*& stack)
{
	int value = stack->value;
	stack = stack->next; // Move the stack pointer to the next node
	return value; // Return the value of the removed node
}

void display(Stack* stack)
{
	Stack* slider = stack;
	cout << "\n";
	while (slider != nullptr)
	{
		cout << slider->value << " "; // Display the value of the current node
		slider = slider->next; // Move to the next node
	}
}

Stack* compare(Stack* stack1, Stack* stack2)
{
	bool compare = false;
	Stack* memStack1 = nullptr;
	Stack* memStack2 = nullptr;

	// Compare the two stacks element by element
	while (stack1 != nullptr && stack2 != nullptr)
	{
		if (stack1->value != stack2->value)
		{
			compare = false;
			break;
		}
		compare = true;

		// Save the values of the compared nodes in memory stacks
		memStack1 = addToStack(memStack1, readAndRemove(stack1));
		memStack2 = addToStack(memStack2, readAndRemove(stack2));
	}

	if (compare)
	{
		return memStack1; // Return one of the identical stacks
	}

	// Restore the original stacks from memory
	while (memStack1 != nullptr)
	{
		stack1 = addToStack(stack1, readAndRemove(memStack1));
	}

	while (memStack2 != nullptr)
	{
		stack2 = addToStack(stack2, readAndRemove(memStack2));
	}

	Stack* newStack = nullptr;

	// Create a new stack containing negative values from both original stacks
	while (stack1 != nullptr)
	{
		if (stack1->value < 0)
		{
			newStack = addToStack(newStack, readAndRemove(stack1));
		}
		else
		{
			readAndRemove(stack1); // Remove non-negative value from stack1
		}
	}

	while (stack2 != nullptr)
	{
		if (stack2->value < 0)
		{
			newStack = addToStack(newStack, readAndRemove(stack2));
		}
		else
		{
			readAndRemove(stack2); // Remove non-negative value from stack2
		}
	}
	return newStack; // Return the stack containing negative values from both original stacks
}
