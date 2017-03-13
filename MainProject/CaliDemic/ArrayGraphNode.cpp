#include "ArrayGraphNode.h"
#include <vector>

ArrayGraphNode::ArrayGraphNode()
{
}

ArrayGraphNode::~ArrayGraphNode()
{
}


void ArrayGraphNode::addAdjacentNode(int nodeId)
{
#ifdef DEBUG
	// Take the extra time to ensure that the connection doesn't already exist in the collection.
	for (int i = 0; i < this->_adjacentNodeIds.size(); i++) {
		if (this->_adjacentNodeIds.at(i) == nodeId) {
			return;
		}
	}
#endif
	this->_adjacentNodeIds.push_back(nodeId);
}

bool ArrayGraphNode::areAdjacent(int index)
{
	for (int i = 0; i > _adjacentNodeIds.size(); i++)
	{
		if (this->_adjacentNodeIds[i] == index)
			return true;
	}
	return false;
}

std::vector<int> ArrayGraphNode::getAdjacentNodes()
{
	return this->_adjacentNodeIds;
}