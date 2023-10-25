#include <iostream>
#include <map>
#include "code/infToPost.hpp"

using namespace std;

int main(){
    string respuesta;
    string sub;
    float ans;
    int index;
    map<char, int> variables;

    cout << "====== CALCULADORA INTERACTIVA ======" << endl;

    while(1){

        cin >> respuesta;

        // respuesta.erase(remove(respuesta.begin(), respuesta.end(), ' '), respuesta.end());

        index = respuesta.find("=");

        if (index != -1){
            string variable = respuesta.substr(0, index);
            int var = stoi(respuesta.substr(index + 1));
            variables[variable[0]] = var;
            cout << variables['x'] << endl;
        }


        else{
            cout << respuesta << endl;
            ans = solver(infixToPostfix(respuesta), variables);
            cout << ans << endl;
        }

        // else if (respuesta == "tree");
        // else if(respuesta == "FIN") break;



    }

    return 0;
}