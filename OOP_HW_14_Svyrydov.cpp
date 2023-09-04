// Implement a stack:
//
// Create the specified stack(s).
// Print the stack(s) – display the values of the elements on the screen.
// Perform the actions specified in the task.
// Display the results on the screen.
// Create two stacks of numbers. Compare the stacks. If the stacks are identical, perform an inversion of one of them; 
// otherwise, create a new stack with the negative elements from the two previous stacks. 
// Display the stacks beforeand after the transformation on the screen.
//

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    // Create a stack with an initial value of 1
    Stack* stack = new Stack(1);

    // Add elements to the stack
    stack = addToStack(stack, 2);
    stack = addToStack(stack, 3);
    stack = addToStack(stack, 4);
    stack = addToStack(stack, 5);
    stack = addToStack(stack, 6);

    // Display the contents of the stack
    cout << "Stack contents: ";
    display(stack);

    // Read and display the last element of the stack
    cout << "\n\nRead last element: " << readLast(stack);

    // Display the updated stack after reading the last element
    cout << "\n\nStack contents after reading last element: ";
    display(stack);

    // Read and remove elements from the stack
    cout << "\n\nRead and remove: ";
    cout << readAndRemove(stack);
    cout << "\n\nStack contents after reading and removing: ";
    display(stack);

    cout << "\n\nRead and remove: ";
    cout << readAndRemove(stack);
    cout << "\nStack contents after reading and removing: ";
    display(stack);

    cout << "\n\nRead and remove: ";
    cout << readAndRemove(stack);
    cout << "\n\nStack contents after reading and removing: ";
    display(stack);

    // Create and populate two stacks
    Stack* stack1 = nullptr;
    for (int i = 0; i < 10; i++)
    {
        stack1 = addToStack(stack1, i);
    }

    cout << "\n\nStack 1 contents: ";
    display(stack1);

    Stack* stack2 = nullptr;
    for (int i = 0; i < 10; i++)
    {
        stack2 = addToStack(stack2, i);
    }

    cout << "\n\nStack 2 contents: ";
    display(stack2);

    // Compare stack1 and stack2, and store the result in stack3
    Stack* stack3 = compare(stack1, stack2);

    cout << "\n\nStack 3 contents after comparison: ";
    display(stack3);

    // Add new elements to stack1 and stack2
    cout << "\n\nAdding new elements to stack 1: -6, -8, 6, -5";
    stack1 = addToStack(stack1, -6);
    stack1 = addToStack(stack1, -8);
    stack1 = addToStack(stack1, 6);
    stack1 = addToStack(stack1, -5);

    cout << "\n\nStack 1 contents after adding new elements: ";
    display(stack1);

    cout << "\n\nAdding new elements to stack 2: -1, -4, 2, -3";
    stack2 = addToStack(stack2, -1);
    stack2 = addToStack(stack2, -4);
    stack2 = addToStack(stack2, 2);
    stack2 = addToStack(stack2, -3);

    cout << "\n\nStack 2 contents after adding new elements: ";
    display(stack2);

    // Compare the modified stack1 and stack2, and store the result in stack4
    Stack* stack4 = compare(stack1, stack2);

    cout << "\n\nNew stack (stack4) contents after comparison: ";
    display(stack4);

    cout << "\n\n\n";
}
