#include "Node.hpp"


Node::Node(uint8_t map[SIZE_BOARD][SIZE_BOARD], uint16_t moveCoord, bool maxNode, uint8_t depth, uint8_t player): maxNode(maxNode), depth(depth), playerNum(player)
{
	for (uint8_t i = 0; i < SIZE_BOARD -1; i++)
	{
		memcpy(this->map[i], map[i], SIZE_BOARD * sizeof(uint8_t));
	}

	this->map[moveCoord / SIZE_BOARD][moveCoord % SIZE_BOARD] = playerNum;
	this->_indexChild = 0;
}

Node::~Node()
{	
}

Node*			Node::getNextChild()
{
	return (this->childs[this->_indexChild++]);
}

void 			Node::insertChild(Node *node)
{
	this->childs.push_back(node);
}