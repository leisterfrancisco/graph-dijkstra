#ifndef ROWMATRIX_H
#define ROWMATRIX_H

#include <iostream>

#include "node.h"
#include "link.h"

using namespace std;

class RowMatrix{
private:
	Node *node;
	bool known;
	int weight;
	Node *before;
public:
	RowMatrix(Node *pNode){
		node = pNode;
		known = false;
		weight = 0;
		before = NULL;
	}

	Node* getNode(){
		return node;
	}

	bool isKnown(){
		if(known) return true;
		else return false;
	}

	int getWeight(){
		return weight;
	}

	Node* getBefore(){
		return before;
	}

	void setKnown(){
		known = true;
	}

	void setWeight(int pWeight){
		this->weight = pWeight;
	}

	void setBefore(Node *pBefore){
		this->before = pBefore;
	}
};

#endif //ROWMATRIX_H