#include <algorithm>
#include "code/infToPost.hpp"

using namespace std;

int main(){
    string input;
    string ans = "0";
    float printAns;
    string variable;
    string valor;
    string buffer;
    int index;
    int pos;
    int qix;
    map<string, string> variables;
    queue<string> infix;
    stack<string> postfix;


    cout << "====== CALCULADORA INTERACTIVA ======" << endl;

    while(1){
        qix = 0;

        cout << "$ ";
        getline(cin, input);

        if (input == "tree");
        else if(input == "FIN") break;

        if ((index = input.find("=")) != string::npos) {
            variable = input.substr(0, index - 1);
            valor = input.substr(index + 2);
            variables[variable] = valor;
            continue;
        }
        
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

        postfix = infixToPostfixStack(infix);

        ans = solver(postfix, variables);
        printAns = stof(ans);
        cout.precision(5);
        cout << printAns<< endl;
        
        while (!postfix.empty()) postfix.pop();
        while (!infix.empty()) infix.pop();
    }

    return 0;
}