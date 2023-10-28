#include <string>
#include <stack>
#include <queue>
#include <map>

bool isOperator(std::string c);
bool isNumber(std::string c);
bool isVar(std::string c);
bool isOperand(char c);
int getPrecedence(std::string c);
std::stack<std::string> infixToPostfix(std::queue<std::string> infix);
std::string solver(std::stack<std::string> postfix, std::map<std::string, std::string>);