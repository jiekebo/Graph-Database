/*
 * Prim.h
 *
 *  Created on: Apr 8, 2012
 *      Author: jiekebo
 */

#ifndef PRIM_H_
#define PRIM_H_

#include <queue>
#include <limits>
#include "../DataStructure/Graph.h"

using namespace std;

class Prim {
public:
	Prim();
	virtual ~Prim();
	Graph mst(Graph graph);
};


#endif /* PRIM_H_ */
