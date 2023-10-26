#include <algorithm>
#include "code/infToPost.hpp"

using namespace std;

int main(){
    string input;
    string sub;
    float ans = 0;
    int index;
    int pos;
    map<char, int> variables;

    cout << "====== CALCULADORA INTERACTIVA ======" << endl;

    while(1){
        cout << "$ ";
        getline(cin, input);

        if (input == "tree");
        else if(input == "FIN") break;

        
        while ((pos = input.find("ans")) != string::npos) {
            input.replace(pos, 3, to_string(ans));
            pos = input.find("ans", pos + to_string(ans).length());
        }


        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        
        cout << input << endl;

        if ((input.find("=") != string::npos)){
            string variable = input.substr(0, index);
            cout << "test" << endl;
            int var = stoi(input.substr(index + 1));
            variables[variable[0]] = var;
        }


        else{
            ans = solver(infixToPostfix(input), variables);
            cout << ans << endl;
        }




    }

    return 0;
}