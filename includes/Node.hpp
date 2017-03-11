#ifndef __NODE__
# define __NODE__

# include "main.hpp"

class Node
{
	private:
	 	uint16_t 			_indexChild;

	public:
		int					depth;
		// int16_t				lowerBound;
		// int16_t				upperBound;
		bool 				maxNode;
		uint8_t 			playerNum;
		uint8_t  			map[SIZE_BOARD][SIZE_BOARD];
		std::vector<Node*> 	childs;

		Node*				getNextChild();
		void 				insertChild(Node* node);

		Node(uint8_t map[SIZE_BOARD][SIZE_BOARD], int16_t moveCoord, bool maxNode, int depth, uint8_t player);
		~Node();
	
};


#endif