#ifndef __NODE__
# define __NODE__

class Node
{
	private:


	public:
		int 		lowerBound;
		int 		upperBound;
		bool 		maxNode;
		std::vector<Node*> childs;

		Node();
		~Node();
	
};


#endif