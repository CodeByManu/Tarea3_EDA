#include <iostream>
#include "code/infToPost.hpp"

using namespace std;

int main(){
    string formula = "4+1*(7+2)";
    string postfix = infixToPostfix(formula);
    stack<char> original;
    stack<char> reserva;
    string operando1;
    string operando2;
    char operador;

    for(int i = 0; i < postfix.length(); i++){
        original.push(postfix[i]);
    }

    cout << postfix << endl;

    for(int i = 0; i < postfix.length(); i++){
        if (!original.empty()) reserva.push(original.top());
        if (!original.empty()) original.pop();

        if (!original.empty() && !reserva.empty() && isOperand(original.top()) && isOperand(reserva.top())) {
            operando1 = original.top();
            operando2 = reserva.top();
            reserva.pop();
            original.pop();
            operador = reserva.top();
            reserva.pop();

            if (operador == '+') original.push(stoi(operando1) + stoi(operando2));
            if (operador == '-') original.push(stoi(operando1) - stoi(operando2));
            if (operador == '*') original.push(stoi(operando1) * stoi(operando2));
            if (operador == '/') original.push(stoi(operando1) / stoi(operando2));
            if (operador == '^') original.push(pow(stoi(operando1), stoi(operando2)));
            
        }
    }

    // cout << "====== CALCULADORA INTERACTIVA ======" << endl;
    return 0;
}