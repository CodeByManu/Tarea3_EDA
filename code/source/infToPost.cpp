#include <math.h>
#include "infToPost.hpp"

bool isOperator(std::string c) {
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^") {
        return true;
    }
    return false;
}

bool isNumber(std::string s) {
    bool decimal = false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '.') {
            if (decimal) {
                return false;
            }
            decimal = true;
        }
        else if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isVar(std::string c){
    for (int i = 0; i < c.length(); i ++){
        if (c[i] >= 'a' && c[i] <= 'z') {
            return true;
        }
        else if (c[i] >= 'A' && c[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

bool isOperand(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

int getPrecedence(std::string c) {
    if (c == "^") {
        return 3;
    }
    if (c == "*" || c == "/") {
        return 2;
    }
    if (c == "+" || c == "-") {
        return 1;
    }
    return -1;
}

std::stack<std::string> infixToPostfixStack(std::queue<std::string> infix) {
    std::stack<std::string> s;
    std::stack<std::string> postfix;
    while(!infix.empty()) {
        std::string c = infix.front();
        if (isNumber(c)) {
            postfix.push(c);
        } else if (isVar(c)) {
            postfix.push(c);
        } else if (isOperator(c)) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix.push(s.top());
                s.pop();
            }
            s.push(c);
        } else if (c == "(") {
            s.push(c);
        } else if (c == ")") {
            while (!s.empty() && s.top() != "(") {
                postfix.push(s.top());
                s.pop();
            }
            s.pop();
        }
        infix.pop();
    }
    while (!s.empty()) {
        postfix.push(s.top());
        s.pop();
    }
    return postfix;
}

std::string solver(std::stack<std::string> postfix, std::map<std::string, std::string> variables){
    std::stack<std::string> original;
    std::stack<std::string> xiftsop;
    float operando1;
    float operando2;
    
    while(!postfix.empty()) {
        xiftsop.push(postfix.top());
        postfix.pop();
    }

    while (!xiftsop.empty()) {
        if (isNumber(xiftsop.top())) original.push(xiftsop.top());

        else if (isVar(xiftsop.top())) original.push(variables[xiftsop.top()]);

        else {
            operando2 = std::stof(original.top());
            original.pop();
            operando1 = std::stof(original.top());
            original.pop();

            if (xiftsop.top() == "+") original.push(std::to_string(operando1 + operando2));
            else if (xiftsop.top() == "-") original.push(std::to_string(operando1 - operando2));
            else if (xiftsop.top() == "*") original.push(std::to_string(operando1 * operando2));
            else if (xiftsop.top() == "/") original.push(std::to_string(operando1 / operando2));
            else if (xiftsop.top() == "^") original.push(std::to_string(pow(operando1, operando2)));
        }
        xiftsop.pop();
    }
    return original.top();
}
