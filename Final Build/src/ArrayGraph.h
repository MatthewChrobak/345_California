#pragma once
#include "ArrayGraphNode.h"
#include <vector>

class ArrayGraph
{
public:
	ArrayGraph();
	~ArrayGraph();

	void addNode(ArrayGraphNode* node);
	ArrayGraphNode* getNode(int index);
	int getNumNodes();

protected:
	std::vector<ArrayGraphNode*> _nodes;
};

