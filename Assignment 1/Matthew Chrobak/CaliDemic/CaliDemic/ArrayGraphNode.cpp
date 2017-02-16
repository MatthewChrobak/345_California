#include "ArrayGraphNode.h"
#include <vector>

#ifdef DEBUG
#include <assert.h>
#endif


ArrayGraphNode::ArrayGraphNode()
{

}


ArrayGraphNode::~ArrayGraphNode()
{

}


void ArrayGraphNode::addAdjacentNode(int nodeId)
{
#ifdef DEBUG
	for (int i = 0; i < this->_adjacentNodeIds.size(); i++) {
		assert(this->_adjacentNodeIds.at(i) != nodeId);
	}
#endif
	this->_adjacentNodeIds.push_back(nodeId);
}

std::vector<int> ArrayGraphNode::getAdjacentNodes()
{
	return this->_adjacentNodeIds;
}