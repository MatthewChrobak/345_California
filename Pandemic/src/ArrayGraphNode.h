#pragma once
#include <vector>

class ArrayGraphNode
{
public:
	ArrayGraphNode();
	~ArrayGraphNode();

	void addAdjacentNode(int nodeId);
	bool areAdjacent(int index);
	std::vector<int> getAdjacentNodes();

protected:
	std::vector<int> _adjacentNodeIds;
};

