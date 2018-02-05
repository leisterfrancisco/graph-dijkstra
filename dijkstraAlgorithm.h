#ifndef DIJKSTRAALGORITHM
#define DIJKSTRAALGORITHM

#include <iostream>

#include "rowMatrix.h"
#include "node.h"
#include "link.h"

using namespace std;

class Dijkstra{
private:
	RowMatrix **dijkstraMatrix;
	Node *node;
	int amountNodes;

	void addNode_dijkstraMatrix(Node *pBefore, Node *pNode, int pWeight){
		for(int i = 0; i < amountNodes; i++){
			if(dijkstraMatrix[i] == NULL){
				dijkstraMatrix[i] = new RowMatrix(pNode);
				dijkstraMatrix[i]->setWeight(pWeight);
				dijkstraMatrix[i]->setBefore(pBefore);
				break;
			}
		}
	}

	bool isIn_dijkstraMatrix(Node *pNode){
		for(int i = 0; i < amountNodes; i++)
			if(dijkstraMatrix[i] == NULL) return false;
			else if(dijkstraMatrix[i]->getNode() == pNode) return true;
		return false;
	}

	RowMatrix* getRow(Node *pNode){
		for(int i = 0; i < amountNodes; i++)
			if(dijkstraMatrix[i]->getNode() == pNode) return dijkstraMatrix[i];
		return NULL;
	}

public:
	Dijkstra(Node *pNode, int pAmountNodes){
		this->node = pNode;
		this->amountNodes = pAmountNodes;
		dijkstraMatrix = (RowMatrix**) malloc ((amountNodes + 1) * sizeof(RowMatrix*));
		for(int i = 0; i < (amountNodes + 1); i++)
			dijkstraMatrix[i] = NULL;
		dijkstraMatrix[0] = new RowMatrix(node);
		dijkstraAlgorithm();
	}

	void dijkstraAlgorithm(){
		int linkAmount;
		Link **links;
		RowMatrix *momentRowMatrix;

		for(int i = 0; dijkstraMatrix[i] != NULL; i++){
			if(!dijkstraMatrix[i]->isKnown()){
				linkAmount = dijkstraMatrix[i]->getNode()->getLinkAmount();
				links = dijkstraMatrix[i]->getNode()->getLinks();
				for(int j = 0; j < linkAmount; j++){
					if(isIn_dijkstraMatrix(links[j]->getNode())){
						momentRowMatrix = getRow(links[j]->getNode());
						if(( dijkstraMatrix[i]->getWeight() + links[j]->getWeight() ) < momentRowMatrix->getWeight()){
							momentRowMatrix->setWeight(dijkstraMatrix[i]->getWeight() + links[j]->getWeight());
							momentRowMatrix->setBefore(dijkstraMatrix[i]->getNode());
						}
					}
					else{
						addNode_dijkstraMatrix(dijkstraMatrix[i]->getNode(), links[j]->getNode(), dijkstraMatrix[i]->getWeight() + links[j]->getWeight());
					}
				}
				dijkstraMatrix[i]->setKnown();
			}
		}
	}

	void getPath(Node *pNode){
		string path[amountNodes];
		for(int i = 0; i < amountNodes; i++)
			path[i] = "";
		if(isIn_dijkstraMatrix(pNode)){
			RowMatrix *row = getRow(pNode);
			row = getRow(row->getBefore());
			while(row->getBefore() != NULL){
				for(int i = 0; i < amountNodes; i++){
					if(path[i] == ""){
						path[i] = row->getNode()->getName();
						break;
					}
				}
				row = getRow(row->getBefore());
			}
			cout<<"Path: ";
			for(int i = 0; i < amountNodes; i++){
				if(path[i] == ""){
					for(int j = (i - 1); j != -1; j--)
						cout<<path[j] <<" -> ";
					break;
				}
			}
		}
		else cout<<"\nThere is no path" <<endl;
	}
};

#endif //DIJKSTRAALGORITHM