#pragma once
#include "ArrayGraphNode.h"
#include <vector>

class ArrayGraph
{
public:
	ArrayGraph(int numNodes);
	~ArrayGraph();

	void setNode(int index, ArrayGraphNode* node);
	ArrayGraphNode* getNode(int index);

	int getNumNodes();

protected:
	int _numNodes;
	ArrayGraphNode** _nodes;
};

