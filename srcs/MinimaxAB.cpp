#include "Node.hpp"
#include "HashTT.hpp"

/*int16_t	 		alphaBetaWithMemory(Node *node, int16_t alpha, int16_t beta, uint8_t depth)
{
	int16_t 	val;
	int16_t 	a;
	int16_t 	b;
	Node 		*child;
	HashEntry	*res;
	HashEntry 	tt;

	if ((res = checkHashTable(node)) != NULL)
	{
		if (res->lowerBound >= beta)
			return (res->lowerBound);
		if (res->upperBound <= alpha)
			return (res->upperBound);
		alpha = std::max(alpha, res->lowerBound);
		beta = std::min(beta, res->upperBound);
	}

	if (!depth)
		val = evalHeuristic(node);
	else if (node.maxNode == TRUE)
	{
		val = SHRT_MIN;
		a = alpha;
		child = getNextChild();
		while(val < beta && child != NULL)
		{
			val = std::min(val, alphaBetaWithMemory(child, a, beta, depth - 1));
			a = std::max(a, val);
			child = getNextChild();
		}
	}
	else
	{
		val = SHRT_MAX;
		b = beta;
		child = getNextChild();
		while(val > alpha && child != NULL)
		{
			val = std::min(val, alphaBetaWithMemory(child, alpha, b, depth - 1));
			b = std::min(b, val);
			child = getNextChild();
		}
	}

	tt.lowerBound = SHRT_MIN;
	tt.upperBound = SHRT_MAX;
	if (val <= alpha)
	{
		tt.upperBound = val;
		createNewEntry(node->map, tt);
	}
	if (val > alpha && val < beta)
	{
		tt.lowerBound = val;
		tt.upperBound = val;
		createNewEntry(node->map, tt);
		createNewEntry(node->map, tt);
	}
	if (val >= beta)
	{
		tt.lowerBound = val;
		createNewEntry(node->map, tt);
	}
	return (val);
}*/