#ifndef __NODE__
# define __NODE__

# define INF 10000

#include "main.hpp"

class Node
{
	// private:
		// 	uint16_t 			_indexChild;

	public:
		uint8_t 			depth;
		uint16_t			lowerBound;
		uint16_t			upperBound;
		bool 				maxNode;
		char 				stone;
		char[SIZE_BOARD][SIZE_BOARD] map;
		std::vector<Node*> 	childs;

		Node*				getFirstChild();
		Node*				getNextChild();

		void 				insertChild();
		Node();
		~Node();
	
};


#endif