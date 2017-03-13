#pragma once
#include <vector>

class ArrayGraphNode
{
public:
	ArrayGraphNode();
	~ArrayGraphNode();

	void addAdjacentNode(int nodeId);
	std::vector<int> getAdjacentNodes();

protected:
	std::vector<int> _adjacentNodeIds;
};

