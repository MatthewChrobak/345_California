#include "ArrayGraph.h"

#ifdef DEBUG
#include <assert.h>
#endif


ArrayGraph::ArrayGraph(int numNodes)
{
	this->_nodes = new ArrayGraphNode*[numNodes];
	this->_numNodes = numNodes;

	for (int i = 0; i < this->_numNodes; i++) {
		*(this->_nodes + i) = nullptr;
	}
}


ArrayGraph::~ArrayGraph()
{
	for (int i = 0; i < this->_numNodes; i++) {
		if (*(this->_nodes + i) != nullptr) {
			delete *(this->_nodes + i);
		}
	}
}

void ArrayGraph::setNode(int index, ArrayGraphNode* node)
{
#ifdef DEBUG
	assert(index >= 0 && index < this->_numNodes);
#endif
	if (*(this->_nodes + index) != nullptr) {
		delete *(this->_nodes + index);
	}
	*(this->_nodes + index) = node;
}

ArrayGraphNode* ArrayGraph::getNode(int index)
{
#ifdef DEBUG
	assert(index >= 0 && index < this->_numNodes);
#endif
	return *(this->_nodes + index);
}

int ArrayGraph::getNumNodes()
{
	return this->_numNodes;
}