/*
 * abbNode.cpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#include "../hdir/abbNode.hpp"

namespace trees {

ABBNode::ABBNode():
		ptrLeft(nullptr), data("-1"), ptrRight(nullptr) {
	// TODO Auto-generated constructor stub
}

ABBNode::ABBNode(std::string val):
		ptrLeft(nullptr), data(val), ptrRight(nullptr){

}

void ABBNode::setLeft(ABBNode* node){
	ptrLeft = node;
}

void ABBNode::setRight(ABBNode* node){
	ptrRight = node;
}

void ABBNode::setData(std::string val){
	data = val;
}

void ABBNode::setSize(int s){
	size = s;
}

ABBNode* ABBNode::getLeft(){
	return ptrLeft;
}

ABBNode* ABBNode::getRight(){
	return ptrRight;
}

std::string ABBNode::getData(){
	return data;
}

int ABBNode::getSize(){
	return size;
}

ABBNode::~ABBNode() {
	if (ptrLeft != nullptr){
		delete ptrLeft;
	}
	if (ptrRight != nullptr){
		delete ptrRight;
	}
}

} /* namespace trees */