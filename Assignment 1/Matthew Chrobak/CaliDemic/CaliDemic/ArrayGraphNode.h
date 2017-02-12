#pragma once
#include <vector>

class ArrayGraphNode
{
public:
	ArrayGraphNode();
	~ArrayGraphNode();

	void addAdjacentNode(int nodeId);

protected:
	std::vector<int> _adjacentNodeIds;
};

