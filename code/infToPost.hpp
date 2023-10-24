#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c);
bool isOperand(char c);
int getPrecedence(char c);
std::string infixToPostfix(std::string infix);