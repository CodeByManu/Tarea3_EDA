#include <iostream>
#include "code/infToPost.hpp"

using namespace std;

int main(){
    string formula = "(2+1)/(3-1)*3^2";
    string postfix = infixToPostfix(formula);

    cout << postfix << endl;

    cout << solver(postfix);

    // cout << "====== CALCULADORA INTERACTIVA ======" << endl;
    return 0;
}