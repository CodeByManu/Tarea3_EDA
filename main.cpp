#include <iostream>
#include <algorithm>
#include "code/hfiles.hpp"

using namespace std;
using namespace trees;

int main(){
    string input;
    string ans = "0";
    string variable;
    string valor;
    string buffer;

    float printAns;
    int index;
    int pos;
    int qix;

    map<string, string> variables;
    queue<string> infix;
    stack<string> postfix;
    stack<string> xiftsop;
    ABB tree;
    ABB oldTree;
    oldTree.insert("-1");

    cout << "====== CALCULADORA INTERACTIVA ======" << endl;

    while(1){
        qix = 0;

        cout << "$ ";
        getline(cin, input);
        
        if (input == "tree") {
            tree = postfixToTree(xiftsop);
            while (!xiftsop.empty()) xiftsop.pop();
            tree = ABB();
            continue;
        }
        else if (input == "FIN") {break;}
        else if (input.size() == 0) continue;
        else if ((index = input.find("=")) != string::npos) {
            variable = input.substr(0, index - 1);
            valor = input.substr(index + 2);
            variables[variable] = valor;
            continue;
        }
        while (!xiftsop.empty()) xiftsop.pop();
        
        while ((pos = input.find("ans")) != string::npos) {
            input.replace(pos, 3, ans);
            pos = input.find("ans", pos + ans.length());
        }

        while ((pos = input.find(" ", qix)) != string::npos) {
            buffer = input.substr(qix, pos - qix);
            infix.push(buffer);
            qix = pos + 1;
        }
        infix.push(input.substr(qix));

        postfix = infixToPostfix(infix);

        while (!postfix.empty()) {
            xiftsop.push(postfix.top());
            postfix.pop();
        }

        ans = solver(xiftsop, variables);
        printAns = stof(ans);
        cout.precision(5);
        cout << "$ " << printAns<< endl;
        


        // while (!xiftsop.empty()) {
        //     cout << xiftsop.top() << endl;
        //     xiftsop.pop();
        // }

        // while (!postfix.empty()) postfix.pop();
        while (!infix.empty()) infix.pop();
    }

    return 0;
}