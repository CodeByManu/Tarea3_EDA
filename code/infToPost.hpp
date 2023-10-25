#include <iostream>
#include <stack>
#include <map>
#include <string>

bool isOperator(char c);
bool isOperand(char c);
bool isNumber(char c);
bool isVar(std::string c);
int getPrecedence(char c);
std::string infixToPostfix(std::string infix);
float solver(std::string postfix, std::map<char, int>);