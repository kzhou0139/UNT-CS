//Kelly Zhou
//ksz0009
//node.cpp

#include "node.h"

Node::Node() {
	data = 0;
}

Node::Node (int d) {
	this->data = d;
	this->next = nullptr;
}

int Node::getData() {
	return data;
}

void Node::setData(int d) {
	data = d;
}
