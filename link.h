#ifndef LINK_H
#define LINK_H

#include "node.h"
class Node;

class Link{
private:
	Node *node;
	int weight;

public:
	Link(Node *pNode, int pWeight){
		this->node = pNode;
		this->weight = pWeight;
	}

	void setWeight(int pWeight){
		this->weight = pWeight;
	}

	Node* getNode(){
		return node;
	}

	int getWeight(){
		return weight;
	}
};
#endif //LINK_H