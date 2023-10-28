#include "../hdir/postToTree.hpp"
#include "../hdir/infToPost.hpp"
#include <iostream>

trees::ABB postfixToTree(std::stack<std::string> xiftsop) {
    std::stack<trees::ABBNode*> build;
    std::string data;

    while (!xiftsop.empty()) {
        data = xiftsop.top();
        if (isNumber(data) || isVar(data) || data == "ans") {
            build.push(new trees::ABBNode(data));
        }
        else if (isOperator(data)) {
            trees::ABBNode *root = new trees::ABBNode(data);
            root->setRight(build.top());
            build.pop();
            root->setLeft(build.top());
            build.pop();
            build.push(root);
        }
        xiftsop.pop();
    }
    trees::ABB final(build.top());
    final.updateSize();
    final.traverse();

    return final;
}