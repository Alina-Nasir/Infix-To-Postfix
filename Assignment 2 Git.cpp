// Assignment 2 Git.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include<string>
#include<string.h>

using namespace std;
template <typename T> class Stack {
public:
	static const int size = 50; //declaring size of stack
	T stack[size]; //creating character array
	int top = -1; //declaring top most position -1 for empty stack
	//method to check if the stack is full by comparing top and size
	bool isFull() {
		return top == size - 1;
	}
	//method to check if stack is empty
	bool isEmpty() {
		return top < 0; //no elements added
	}
	//method to place the element in stack
	void Push(T element) {
		if (!isFull()) { //check array
			stack[++top] = element; //incrementing top and adding element
		}
	}
	//method to remove element from top of stack
	void Pop() {
		if (!isEmpty()) {
			top--; //decrementing top
		}
	}
	//method to clear stack
	void clear() {
		top = -1; //reset top to -1
	}
	//method to get top most element
	T peak() {
		return stack[top];
	}

}; //end stack class



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
