/*
 * Graph.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: jiekebo
 */

#include "Graph.h"

Graph::Graph() {
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

Node* Graph::createNode(string title) {
	Node* node = new Node;
	node->title = title;
	node->relationStore = new RelationStore;
	Properties properties;
	node->properties = properties;

	string id = generateId();

	Pair* ptr = new Pair(id, node);
	graph.insert(*ptr);

	return node;
}

void Graph::createRelation(string type, int weight, Node* node1, Node* node2) {
	Relation* relation = new Relation;
	relation->weight = weight;
	relation->type = type;
	relation->toNode = node2;
	node1->relationStore->adjacencyList.push_back(relation);
}

//TODO: get by uuid instead
Node* Graph::getNode(string key) {
	/*map<uuid_t, Node*>::iterator it = graph.find(key);
	 if(it != graph.end()) {
	 return it->second;
	 } else {
	 return NULL;
	 }*/
	return NULL;
}

map<string, Node*>::iterator Graph::graphIterator() {
	return graph.begin();
}

void Graph::toString() {
	map<string, Node*>::iterator it = graph.begin();
	for (int i = 0; i < graph.size(); i++) {
		Node* node = it->second;
		cout << "Key: " << it->first << "  Value: " << node->title << endl;
		showRelations(node);
		it++;
	}
}

void Graph::showRelations(Node* node) {
	list<Relation*> adjacencyList = node->relationStore->adjacencyList;
	list<Relation*>::iterator it = adjacencyList.begin();
	for(int i = 0; i < adjacencyList.size(); i++) {
		cout << "   " << node->title << "---" << (*it)->type << "---" << (*it)->toNode->title << endl;
		it++;
	}
}

void Graph::writeGraph(string filePath) {
	/*fstream binfile("test.bin", ios::in|ios::out|ios::binary|ios::ate);*/

	cout << "node pointer: " << sizeof(graph) << endl;
	cout << "node itself: " << sizeof(&graph) << endl;

	//ifstream::pos_type size = binfile.tellg();
	ofstream binfile("test.bin", ios::binary);

	string temp = graph.begin()->second->title;
	cout << temp << endl;

	binfile.write(temp.data(), sizeof(temp));
	binfile.close();

	ofstream myfile;
	myfile.open("test.txt");
	if (myfile.is_open()) {
		myfile << "<graph>" << endl;
		map<string, Node*>::iterator it = graph.begin();
		for(int i = 0; i < graph.size(); i++) {
			Node* node = it->second;
			list<Relation*> adjacencyList = node->relationStore->adjacencyList;
			myfile << "\t<node key='" << it->first << "' value='" << node->title << "'>" << endl;

			list<Relation*>::iterator rit = adjacencyList.begin();
			for(int j = 0; j < adjacencyList.size(); j++) {
				myfile << "\t\t<relation type='" << (*rit)->type << "'>" << (*rit)->toNode->title << "</relation>" << endl;
				rit++;
			}
			myfile << "\t</node>" << endl;
			it++;
		}
		myfile << "</graph>" << endl;
	}
}

void Graph::readGraph(string filePath) {

}

string Graph::generateId() {
	uuid_t uuid;
	uuid_generate_random(uuid);
	char s[37];
	uuid_unparse(uuid, s);
	return s;
}

size_t Graph::graphSize() {
	return graph.size();
}
