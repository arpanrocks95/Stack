// CPP Program to convert prefix to postfix
#include <iostream>
#include <stack>
using namespace std;

// funtion to check if character is operator or not
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

// Convert  Postfix expression to infix
string postToInfix(string post_exp) {

    stack<string> s;
    for (int i = 0; post_exp[i] != '\0'; i++) {

        // check if symbol is operator
        if (isOperator(post_exp[i])) {

            // pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // concat the operands and operator
            string temp = "(" + op2 + post_exp[i] + op1 + ")";

            // Push string temp back to stack
            s.push(temp);
        }

            // if symbol is an operand
        else {

            // push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }

// stack contains only the Postfix expression
    return s.top();
}

// Driver Code
int main() {
    string post_exp = "ABC/-AK/L-*";
    cout << "Infix : " << postToInfix(post_exp);
    return 0;
}
