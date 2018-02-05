#ifndef NODO_H
#define NODO_H

#include <string>
#include "link.h"

using namespace std;

class Node{
private:
	string name;
	Link **nextNode;
	int linkAmount;

public:
	Node(string pName){
		name = pName;
		nextNode = NULL;
		linkAmount = 0;
	}

	Link** getLinks(){
		return nextNode;
	}

	string getName(){
		return name;
	}

	int getLinkAmount(){
		return linkAmount;
	}

	void addLink(Node *pNode, int pWeight){
		if(nextNode == NULL){
			nextNode = (Link**) malloc (1 * sizeof(Link*));
			nextNode[linkAmount++] = new Link(pNode, pWeight);
		}
		else{
			Link **nextMomentNode = nextNode;
			nextNode = (Link**) malloc ( (linkAmount + 1) * sizeof(Link*));
			for(int i = 0; i < linkAmount; i++){
				nextNode[i] = nextMomentNode[i];
			}
			nextNode[linkAmount++] = new Link(pNode, pWeight);
		}
	}
};
#endif //NODO_H