	/*
 * Graph.h
 *
 *  Created on: Mar 10, 2012
 *      Author: jiekebo
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <uuid/uuid.h>
#include "Properties.h"
using namespace std;

typedef struct Node;
typedef pair<string, Node*> Pair;

typedef struct Relation {
	string type;
	int weight;
	Node* toNode;
};

typedef struct RelationStore {
	list<Relation*> adjacencyList;
};

typedef struct PropertyStore {

};

typedef struct Node {
	string title;
	int key;
	RelationStore* relationStore;
	Properties properties;
};

struct NodeLessThan : public binary_function<Node,Node,bool> {
	bool operator() (Node const& n1, Node const& n2) const {
		return n1.key < n2.key;
	}
};


class Graph {
public:
	Graph();
	virtual ~Graph();
	Node* createNode(string title);
	void createRelation(string type, int weight, Node* node1, Node* node2);
	Node* getNode(string key);
	map<string, Node*>::iterator graphIterator();
	void toString();
	void showRelations(Node* node);
	void writeGraph(string filePath);
	void readGraph(string filePath);
	size_t graphSize();
private:
	map<string, Node*> graph;
	string generateId();
};

#endif /* GRAPH_H_ */
