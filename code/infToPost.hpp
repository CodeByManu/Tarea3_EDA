#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <math.h>

bool isOperator(char c);
bool isOperand(char c);
bool isNumber(char c);
bool isVar(std::string c);
int getPrecedence(char c);
// std::string infixToPostfix(std::string infix);
std::stack<std::string> infixToPostfixStack(std::queue<std::string> infix);
std::string solver(std::stack<std::string> postfix, std::map<std::string, std::string>);
void bTree();