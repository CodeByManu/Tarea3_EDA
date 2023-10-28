#include "../hdir/postToTree.hpp"
#include "../hdir/infToPost.hpp"
#include <iostream>

trees::ABB postfixToTree(std::stack<std::string> xiftsop) {
    std::stack<std::string> build;
    std::map<std::string, trees::ABBNode*> prevOp;
    std::string data;

    while (!xiftsop.empty()) {
        data = xiftsop.top();
        if (isNumber(data) || isVar(data) || data == "ans") {
            build.push(data);
        }
        else if (isOperator(data)) {
            trees::ABBNode *root = new trees::ABBNode(data);
            if (prevOp.find(build.top()) != prevOp.end()) {
                // std::cout << data << " || " << prevOp[build.top()]->getData() << std::endl;
                root->setRight(prevOp[build.top()]);
            }
            else {
                trees::ABBNode *left = new trees::ABBNode(build.top());
                root->setRight(left);
            }
// std::cout << build.top() << std::endl;
            build.pop();
// std::cout << build.top() << std::endl;
            if (prevOp.find(build.top()) != prevOp.end()) {
                // std::cout << "key found right" << std::endl;
                root->setLeft(prevOp[build.top()]);
            }
            else {
                trees::ABBNode *right = new trees::ABBNode(build.top());
                root->setLeft(right);
            }
            build.pop();
            if (prevOp.size() > 0) prevOp.clear();
            prevOp[data] = root;
// std::cout << root->getData() << " L: "<< prevOp[build.top()]->getLeft()->getData() << " R: " << prevOp[build.top()]->getRight()->getData() << std::endl;
            build.push(data);
            // trees::ABB test(root);
            // test.updateSize();
            // test.traverse();
        }
        xiftsop.pop();
    }
    trees::ABB final(prevOp.begin()->second);
    final.updateSize();
    final.traverse();

    return final;
}