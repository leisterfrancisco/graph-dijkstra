#include <iostream>

using namespace std;

#include "graph.h"
#include "dijkstraAlgorithm.h"

void addNode(Graph *pGraph);
void seeNodes(Graph *pGraph);
void searchNodeInfo(Graph *pGraph);
void addLink(Graph *pGraph);
void seeMatrix(Graph *pGraph);
void dijkstraAlgorithm(Graph *pGraph);

int main(){
	Graph *graph = new Graph();
	cout<<"\033[2J\033[1;1H";
	cout<<"Welcome to the simulation graph\n\n\n\n";
	bool exit = false;
	char input;
	do{
		cout<<"Select the desired option..." <<endl;
		cout<<"1. Add a node" <<endl;
		cout<<"2. Make a link" <<endl;
		cout<<"3. Search for a node" <<endl;
		cout<<"4. See all nodes" <<endl;
		cout<<"5. Watch matrix" <<endl;
		cout<<"6. Dijkstra algorithm" <<endl;
		cout<<"7. Exit" <<endl;

		cin>>input;
		switch(input){
			case '1':
				addNode(graph);
				break;
			case '2':
				addLink(graph);
				break;
			case '3':
				searchNodeInfo(graph);
				break;
			case '4':
				seeNodes(graph);
				break;
			case '5':
				seeMatrix(graph);
				break;
			case '6':
				dijkstraAlgorithm(graph);
				break;
			case '7':
				exit = true;
				break;
		}
		cout<<"\033[2J\033[1;1H";
	} while(!exit);
}

void dijkstraAlgorithm(Graph *pGraph){
	cout<<"\033[2J\033[1;1H";
	if(pGraph->getAmountNodes() != 0){
		string input;
		string nodeName = "";
		string nodeName2 = "";
		bool keep = true;
		int go = 0;
		do{
			switch(go){
				case 0:
					cout<<"\033[2J\033[1;1H";
					cout<<"Showing Dijkstra Algorithm" <<endl;
					cout<<"\n\n\nOrigin node: ";
					go = 2;
					break;
				case 1:
					cout<<"Destination node: ";
					go = 3;
					break;
				case 2:
					if(nodeName != ""){
						cout<<nodeName <<endl;
						go = 1;
					}
					else{
						cin>>input;
						if(pGraph->nodeExist(input)) nodeName = input;
						go = 0;
					}
					break;
				case 3:
					if(nodeName2 != ""){
						cout<<nodeName2 <<endl;
						go = 4;
					}
					else{
						cin>>input;
						if(pGraph->nodeExist(input)) nodeName2 = input;
						go = 0;
					}
					break;
				case 4:
					Dijkstra *dijkstra = new Dijkstra(pGraph->searchNode(nodeName), pGraph->getAmountNodes());
					dijkstra->getPath(pGraph->searchNode(nodeName2));
					keep = false;
			}
		}while(keep);
	}
	else cout<<"There are no links" <<endl;

	char exit;

	cout<<"\n\nType a letter to go back..." <<endl;
	cin>>exit;
}

void seeMatrix(Graph *pGraph){
	cout<<"\033[2J\033[1;1H";

	if(pGraph->getAmountNodes() != 0){
		cout<<"Watching matrix\n\n\n" <<endl;

		pGraph->seeMatrix();
	}
	else cout<<"There are no nodes" <<endl;

	char exit;

	cout<<"\n\nType a letter to go back..." <<endl;
	cin>>exit;
}

void addLink(Graph *pGraph){
	cout<<"\033[2J\033[1;1H";
	if(pGraph->getAmountNodes() > 1){
		string input;
		string nodeName = "";
		string nodeName2 = "";
		int weight = 0;
		short go = 0;
		bool keep = true;

		do{
			switch(go){
				case 0:
					cout<<"\033[2J\033[1;1H";
					cout<<"Adding a link" <<endl;
					cout<<"\n\n\nOrigin node: ";
					go = 2;
					break;
				case 1:
					cout<<"Destination node: ";
					go = 3;
					break;
				case 2:
					if(nodeName != ""){
						cout<<nodeName <<endl;
						go = 1;
					}
					else{
						cin>>input;
						if(pGraph->nodeExist(input))
							nodeName = input;
						go = 0;
					}
					break;
				case 3:
					if(nodeName2 != ""){
						cout<<nodeName2 <<endl;
						go = 4;
					}
					else{
						cin>>input;
						if(pGraph->nodeExist(input)) nodeName2 = input;
						go = 0;
					}
					break;
				case 4:
					cout<<"Weight: ";
					cin>>weight;
					go = 5;
					break;
				case 5:
					pGraph->makeLink(nodeName, nodeName2, weight);
					keep = false;
				default:
					break;
			}
		}while(keep);
	}
	else cout<<"There are not enough nodes" <<endl;

	cout<<"\nType a letter to go back..." <<endl;

	char exit;
	cin>>exit;

	return;
}

void searchNodeInfo(Graph *pGraph){
	string input;
	cout<<"\033[2J\033[1;1H";

	if(pGraph->getAmountNodes() != 0){
		cout<<"Looking for a node" <<endl;
		cout<<"\n\n\nType the node name..." <<endl;
		cout<<"Name: ";
		cin>>input;
		pGraph->searchNodeInfo(input);
	}
	else cout<<"There are no nodes" <<endl;

	cout<<"\nType a letter to go back..." <<endl;

	char exit;
	cin>>exit;

	return;
}

void seeNodes(Graph *pGraph){
	cout<<"\033[2J\033[1;1H";

	if(pGraph->getAmountNodes() != 0){
		cout<<"Seeing nodes" <<endl;
		pGraph->seeNodes();
	}
	else cout<<"There are no nodes" <<endl;

	cout<<"\nType a letter to go back..." <<endl;

	char exit;
	cin>>exit;

	return;
}

void addNode(Graph *pGraph){
	string input;
	cout<<"\033[2J\033[1;1H";
	cout<<"Adding a node" <<endl;
	cout<<"\n\n\nType the node name..." <<endl;
	cout<<"Name: ";
	cin>>input;
	pGraph->addNode(new Node(input));

	cout<<"\nType a letter to go back..." <<endl;

	char exit;
	cin>>exit;

	return;
}