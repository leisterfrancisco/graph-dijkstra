#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "node.h"
#include "link.h"

using namespace std;

class Graph{
private:
	Node **nodes;
	int amountNodes;

	Link* getNodeLink(Node *pOrigin, Node *pDestination){
		for(int i = 0; i < pOrigin->getLinkAmount(); i++)
			if(pOrigin->getLinks()[i]->getNode() == pDestination) return pOrigin->getLinks()[i];
		return NULL;
	}

public:
	Graph(){
		nodes = NULL;
		amountNodes = 0;
	}

	bool isLinked(){
		for(int i = 0; i < amountNodes; i++){
			if(nodes[i] != NULL){
				if(nodes[i]->getLinks() != NULL) return true;
			}
			else break;
		}
		return false;
	}

	Node* getFirstNode(){
		return nodes[0];
	}

	int getAmountNodes(){
		return amountNodes;
	}

	void seeMatrix(){
		bool has = false;
		cout<<"     ";
		for(int i = 0; i < amountNodes; i++)
			cout<<"| " <<nodes[i]->getName() <<" |";

		for(int i = 0; i < amountNodes; i++){
			cout<<"\n  " <<nodes[i]->getName() <<"  ";
			for(int j = 0; j < amountNodes; j++){
				cout<<"| ";
				if(nodes[i] == nodes[j]){
					cout<<0;
					has = true;
				}
				else{
					for(int k = 0; k < nodes[i]->getLinkAmount(); k++){
						if(nodes[i]->getLinks()[k]->getNode() == nodes[j]){
							cout<<nodes[i]->getLinks()[k]->getWeight();
							has = true;
							break;
						}
					}
				}
				if(!has)	cout<<0;
				else	has = false;
				cout<<" |";
			}
		}

	}

	bool nodeExist(string pName){
		for(int i = 0; i < amountNodes; i++){
			if(nodes[i]->getName() == pName)	return true;
		}
		return false;
	}

	void makeLink(string pNode, string pNode2, int pWeight){
		Node *node = searchNode(pNode);
		Node *node2 = searchNode(pNode2);

		if(node == NULL || node2 == NULL) cout<<"\nNode not exist..." <<endl;
		else if (getNodeLink(node, node2) != NULL){
			getNodeLink(node, node2)->setWeight(pWeight);
			cout<<"Link has been modified correctly..." <<endl;
		}
		else{
			node->addLink(node2, pWeight);
			cout<<"Link has been added correctly..." <<endl;
		}
	}

	Node* searchNode(string pName){
		for(int i = 0; i < amountNodes; i++){
			if(nodes[i]->getName() == pName)	return nodes[i];
		}
		return NULL;
	}

	void addNode(Node* pNode){
		if(!nodeExist(pNode->getName())){
			if(nodes == NULL){
				nodes = (Node**) malloc (1 * sizeof(Node*));
				nodes[amountNodes++] = pNode;
			}
			else{
				Node **momentNodes = nodes;
				nodes = (Node**) malloc ( (amountNodes + 1) * sizeof(Node*));
				for(int i = 0; i < amountNodes; i++)
					nodes[i] = momentNodes[i];

				nodes[amountNodes++] = pNode;
			}
			cout<<"Node has been added" <<endl;
		}
		else cout<<"Node already exist" <<endl;
	}

	void searchNodeInfo(string pName){
		bool searched = false;
		for(int i = 0; i < amountNodes; i++){
			if(nodes[i]->getName() == pName){
				cout<<"\n\nName: " <<nodes[i]->getName() <<endl;
				cout<<"Amount of links: " <<nodes[i]->getLinkAmount() <<endl;
				if(nodes[i]->getLinkAmount() != 0){
					cout<<"\nLinks..." <<endl;
					for(int j = 0; j < nodes[i]->getLinkAmount(); j++){
						cout<<"\nName: " <<nodes[i]->getLinks()[j]->getNode()->getName();
						cout<<"\tWeight: " <<nodes[i]->getLinks()[j]->getWeight() <<endl;
					}
				}
				else	cout<<"No links..." <<endl;
				
				searched = true;
				break;
			}
		}
		if(!searched){
			cout<<"\nNode not exist" <<endl;
		}
	}

	void seeNodes(){
		for(int i = 0; i < amountNodes; i++){
			cout<<"\n\nName: " <<nodes[i]->getName() <<endl;
			cout<<"Amount of links: " <<nodes[i]->getLinkAmount() <<endl;
			if(nodes[i]->getLinkAmount() != 0){
				cout<<"\nLinks..." <<endl;
				for(int j = 0; j < nodes[i]->getLinkAmount(); j++){
					cout<<"\nName: " <<nodes[i]->getLinks()[j]->getNode()->getName();
					cout<<"\tWeight:" <<nodes[i]->getLinks()[j]->getWeight() <<endl;
				}
			}
			else	cout<<"No links..." <<endl;
		}
	}
};

#endif //GRAPH_H