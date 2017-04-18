#include "ArrayGraph.h"

#ifdef DEBUG
#include <assert.h>
#endif


ArrayGraph::ArrayGraph()
{
}

ArrayGraph::~ArrayGraph()
{
    while (this->_nodes.size() > 0) {
        delete this->_nodes[this->_nodes.size() - 1];
        this->_nodes.pop_back();
    }
}

void ArrayGraph::addNode(ArrayGraphNode* node)
{
    this->_nodes.push_back(node);
}

ArrayGraphNode* ArrayGraph::getNode(int index)
{
#ifdef DEBUG
    // Ensure that the index is within the valid bounds.
	assert(index >= 0 && index < this->_nodes.size());
#endif
    return this->_nodes[index];
}

int ArrayGraph::getNumNodes()
{
    return this->_nodes.size();
}