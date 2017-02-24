#include "Node.hpp"
#include "HashTT.hpp"

int16_t	 		alphaBetaWithMemory(Node *node, int16_t alpha, int16_t beta, int8_t depth)
{
	int16_t 	val;
	int16_t 	a;
	int16_t 	b;
	Node 		*child;
	hashEntry	tt;

	if ((tt = checkHashTable(node)) != NULL)
	{
		if (tt.lowerBound >= beta)
			return (tt.lowerBound);
		if (tt.upperBound <= alpha)
			return (tt.upperBound);
		alpha = std::max(alpha, tt.lowerBound);
		beta = std::min(beta, tt.upperBound);
	}

	if (!depth)
		val = evalHeuristic(node);
	else if (node.maxNode == TRUE)
	{
		val = -INF;
		a = alpha;
		child = getFirstChild();
		while(val < beta && child != NULL)
		{
			val = std::min(val, alphaBetaWithMemory(child, a, beta, depth - 1));
			a = std::max(a, val);
			child = getNextChild();
		}
	}
	else
	{
		val = INF;
		b = beta;
		child = getFirstChild();
		while(val > alpha && child != NULL)
		{
			val = std::min(val, alphaBetaWithMemory(child, alpha, b, depth - 1));
			b = std::min(b, val);
			child = getNextChild();
		}
	}

	if (val <= alpha)
	{
		tt.upperBound = val;
		createNewEntry(tt);
	}
	if (val > alpha && val < beta)
	{
		tt.lowerBound = val;
		tt.upperBound = val;
		createNewEntry(node.lowerBound);
		createNewEntry(node.upperBound);
	}
	if (val >= beta)
	{
		node.lowerBound = val;
		createNewEntry(node.lowerBound);
	}
	return (val);
}