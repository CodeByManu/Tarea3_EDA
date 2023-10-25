#include "infToPost.hpp"

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

bool isNumber(char c) {
    // for (int i = 0; i < c.length(); i ++){
    //     if (!(c[i] >= '0' && c[i] <= '9')) {
    //         return false;
    //     }
    // }
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isVar(std::string c){
    for (int i = 0; i < c.length(); i ++){
        if (!(c[i] >= 'a' && c[i] <= 'z')) {
        return false;
    }
        if (!(c[i] >= 'A' && c[i] <= 'Z')) {
            return false;
        }
    }
    return true;
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

int getPrecedence(char c) {
    if (c == '^') {
        return 3;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

std::string infixToPostfix(std::string infix) {
    std::stack<char> s;
    std::string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix += c;
        } else if (isOperator(c)) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

float solver(std::string postfix, std::map<char, int> variables){

    std::stack<float> original;
    float operando1;
    float operando2;

    for (int i = 0; i < postfix.length(); i++){

        if (isOperand(postfix[i])){
            if (isNumber(postfix[i])) original.push(postfix[i] - '0');
            else original.push(variables[postfix[i]]);
        }

        else {
            operando2 = original.top();
            original.pop();
            operando1 = original.top();
            original.pop();

            if (postfix[i] == '+') original.push(operando1 + operando2);
            else if (postfix[i] == '-') original.push(operando1 - operando2);
            else if (postfix[i] == '*') original.push(operando1 * operando2);
            else if (postfix[i] == '/') original.push(operando1 / operando2);
            else if (postfix[i] == '^') original.push(pow(operando1, operando2));
        }
    }
    return original.top();
}