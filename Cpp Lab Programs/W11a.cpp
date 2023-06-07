// 14.Write a program to convert an infix expression to a postfix expression using stacks in STL.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}

string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix, postfix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}