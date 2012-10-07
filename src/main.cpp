/*
 * main.cpp
 *
 *  Created on: Mar 7, 2012
 *      Author: jiekebo
 */

#include <iostream>
#include <sstream>
#include "DataStructure/Graph.h"
#include "GraphAlgorithms/Prim.h"
#include <uuid/uuid.h>

template<class T> inline string to_string(const T& t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

enum {CREATE_NODE,
	  DELETE_NODE,
	  CREATE_RELATION,
	  DELETE_RELATION,
	  SAVE_GRAPH,
	  LOAD_GRAPH,
	  DISPLAY_GRAPH,
	  RUN_PRIM,
	  QUIT,
	  TEST};

Graph graph;
Prim prim;

void createNode() {
	string name;
	
	cin.ignore();
	
	cout << "Please enter node name: ";
	getline(cin,name);
	
	graph.createNode(name);
	cout << "Node created" << endl;
}

void deleteNode() {
	cout << "not implemented" << endl;
}

void createRelation() {
	string relation;
	int node1Title;
	int node2Title;
	
	cin.ignore();

	cout << "Enter relation type: ";
	getline(cin,relation);
	
	cout << "Enter from node title: ";
	cin >> node1Title;
	//getline(cin,node1Title);

	cout << "Enter to node title: ";
	cin >> node2Title;
	//getline(cin, node2Title);

	//TODO: how to do this with uuids?
	//graph.createRelation(relation, graph.getNode(node1Title), graph.getNode(node2Title));
	cout << "Relation created" << endl;
}

void deleteRelation() {
	cout << "not implemented" << endl;
}

void saveGraph() {
	string path;

	cin.ignore();

	cout << "Enter filename: ";
	getline(cin,path);

	graph.writeGraph(path);
	cout << "Graph saved" << endl;
}

void loadGraph() {
	cout << "not implemented" << endl;
}

void displayGraph() {
	cout << endl;
	graph.toString();
	cout << endl;
}

void createWeightedGraph() {

}

void runPrim() {
	Graph mst = prim.mst(graph);
	mst.toString();
}

void printCommands() {
	cout << "1: create node" << endl;
	cout << "2: delete node" << endl;
	cout << "3: create relation" << endl;
	cout << "4: delete relation" << endl;
	cout << "5: save graph" << endl;
	cout << "6: load graph" << endl;
	cout << "7: display graph" << endl;
	cout << "8: run prim" << endl;
	cout << "9: quit" << endl;
	cout << endl;
	cout << "Enter choice: ";
}

bool processMenu(int choice) {
	string name;
	switch(choice-1) {
		case CREATE_NODE: 
			createNode();
			break;
		case DELETE_NODE:
			deleteNode();
			break;
		case CREATE_RELATION:
			createRelation();
			break;
		case DELETE_RELATION:
			deleteRelation();
			break;
		case SAVE_GRAPH:
			saveGraph();
			break;
		case LOAD_GRAPH:
			loadGraph();
			break;
		case DISPLAY_GRAPH:
			displayGraph();
			break;
		case RUN_PRIM:
			runPrim();
			break;
		case QUIT:
			return true;
			break;
		default:
			cout << "Invalid input" << endl;
			cout << endl;
			break;
	}
	return false;
}

int main() {
	bool quit;
	int choice;
	while(true) {
		printCommands();
		cin >> choice;
		quit = processMenu(choice);
		if (quit) {
			break;
		}
	}
}
