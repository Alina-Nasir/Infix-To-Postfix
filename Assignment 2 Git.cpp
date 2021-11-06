

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

//method to parse a string and store its content in string vector
vector<string> mystrtok(string str, char delim) {
	vector<string> tokens; //initializing string vector
	string temp = ""; //initializing empty string to temporarily store elements
	for (int i = 0; i < str.length(); i++) { //iterating through string
		if (str[i] == delim) { //if seperator is found
			tokens.push_back(temp); //the previous temporary string is stored in vector
			temp = ""; //initializing it again for next element
		}
		else
			temp += str[i]; //storing element of string in temp
	}
	tokens.push_back(temp); //storing last element in vector
	return tokens;
}//end method mystrtok
//method to get precedence of operator
int getPrecedence(string oper) {
	if (oper == "+" || oper == "-") { //addition and subtraction have lowest
		return 1;
	}
	else if (oper == "*" || oper == "/") {
		return 2; //multiplication and division have higher
	}
	else if (oper == "^") {
		return 3; //exponent has highest
	}
	else {
		return 0;
	}
}//end method getPrecedence
//method to convert infix expression to postfix
string infixToPostfix(string exp) {
	Stack<string> st; //initializing string stack
	string output; //initializing output string
	vector<string> exptok = mystrtok(exp, ' '); //parsing string based on spaces
	for (int i = 0; i < exptok.size(); i++) {
		if (exptok[i] == "(" || exptok[i] == "{" || exptok[i] == "[") { //opening bracket found
			st.Push(exptok[i]); //pushing it in stack
		}
		else if (exptok[i] == ")" || exptok[i] == "}" || exptok[i] == "]") { //closing bracket found
			if (exptok[i] == ")") { //matching opening and closing parenthesis
				while (st.peak() != "(") { //adding elements from stack to output until opening bracket is found
					output = output + " " + st.peak();
					st.Pop(); //removing from stack
				}
			}
			else if (exptok[i] == "}") { //matching opening and closing brackets
				while (st.peak() != "{") { //adding elements from stack to output until opening bracket is found
					output = output + " " + st.peak();
					st.Pop(); //removing from stack
				}
			}
			else if (exptok[i] == "]") { //matching opening and closing square brackets
				while (st.peak() != "[") { //adding elements from stack to output until opening bracket is found
					output = output + " " + st.peak();
					st.Pop(); //removing from stack
				}
			}
			st.Pop(); //removing opening bracket
		}
		//check for operators 
		else if (exptok[i] == "+" || exptok[i] == "-" || exptok[i] == "*" || exptok[i] == "/" || exptok[i] == "^") {
			while (!st.isEmpty() && getPrecedence(exptok[i]) <= getPrecedence(st.peak())) { //comparing precedence of incoming and operator in stack
				output = output + " " + st.peak(); //adding top of stack to output
				st.Pop(); //removing top of stack until the operator precedence of operator in stack is less
			}
			st.Push(exptok[i]); //adding operand to stack in the end
		}
		else {
			output = output + " " + exptok[i]; //adding numbers to output
		}

	} //end for loop
	while (!st.isEmpty()) { //removing all elements in stack
		output = output + " " + st.peak(); //adding them in output
		st.Pop();
	}
	return output;
}//end method infixToPostfix
// method to evaluate Postfix operation
int evaluatePostfix(string postfix) {
	vector<string> expression = mystrtok(postfix, ' '); //parsing postfix expression
	Stack <int>st; //create stack of integer class
	for (int i = 0; i < expression.size(); i++) {
		char* c = const_cast<char*>(expression[i].c_str()); //converting string to charachter array
		int count = strlen(c); //counting number of elements in array
		if (count == 2) { //two digit number
			if (isdigit(c[0]) && isdigit(c[1])) { //checking if they are digits
				int num1 = atoi(c); //converting char to integer
				st.Push(num1); //adding integer to stack
			}
		}
		else if (count == 1) {  //checking one digit number
			if (isdigit(c[0])) { //checking if it is a digit
				int q = atoi(c); //converting to integer
				st.Push(q); //push into stack

			}

			else { //operator found and operands are present in stack
				if (!st.isEmpty()) {
					int int1 = st.peak(); //storing top of stack
					st.Pop(); //pop the stack
					int int2 = st.peak(); //storing second number
					st.Pop(); //pop the stack
					switch (c[0])
					{ //apply operator to the numbers in stack
					case '+': st.Push(int2 + int1); break; //adding two numbers of stack and push result
					case '-': st.Push(int2 - int1); break; //subtracting two numbers of stack and push result
					case '*': st.Push(int2 * int1); break; //multiplying two numbers of stack and push result
					case '/': st.Push(int2 / int1); break; //dividing two numbers of stack and push result
					case '^':st.Push(int2 ^ int1); break; //exponent of two numbers of stack and push result
					default:
						break;
					}
				}

			}

		}




	}
	int result = st.peak(); //store top in result
	return result; //return result
	st.Pop();

}
int main()
{
	string user;
	cout << "Enter the expression with spaces between each operator and operand: " << endl; //prompt user
	getline(cin, user); //get input
	cout << "The expression after conversion from infix to postfix is: " << endl;
	cout << infixToPostfix(user) << endl; //display user
	cout << "Expression after evaluation: " << endl; //evaluate expression
	cout << evaluatePostfix(infixToPostfix(user)) << endl; //

}//end main method


