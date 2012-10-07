/*
 * Prim.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: jiekebo
 */

#include "Prim.h"

Prim::Prim() {
	// TODO Auto-generated constructor stub

}

Prim::~Prim() {
	// TODO Auto-generated destructor stub
}

Graph Prim::mst(Graph graph) {
	priority_queue<Node, vector<Node>, NodeLessThan> vertices;

	map<string, Node*>::iterator it = graph.graphIterator();

	for(int i = 0; i < graph.graphSize(); i++) {
		Node* node = it->second;
		node->key = numeric_limits<int>::max();
		vertices.push(*node);
	}

	Node* start = graph.getNode(0);
	start->key = 0;
}
