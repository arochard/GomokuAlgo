#ifndef __NODE__
# define __NODE__

# define INF 10000

# include <cstdint>

class Node
{
	private:
		uint32_t 			_indexChild;

	public:
		uint8_t 			depth;
		uint32_t			lowerBound;
		uint32_t			upperBound;
		bool 				maxNode;
		std::vector<Node*> 	childs;

		Node*				getFirstChild();
		Node*				getNextChild();

		void 				insertChild();
		Node();
		~Node();
	
};


#endif