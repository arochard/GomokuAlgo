#include "Node.hpp"
#include "HashTT.hpp"

static uint16_t max(uint16_t a, uint16_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static uint16_t	min(uint16_t a, uint16_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

uint16_t	 	alphaBetaWithMemory(Node *node, uint16_t alpha, uint16_t beta, uint8_t depth)
{
	uint16_t 	val;
	uint16_t 	a;
	uint16_t 	b;
	Node 		*child;
	hashEntry	tt;

	if ((tt = checkHashTable(node)) != NULL)
	{
		if (tt.lowerBound >= beta)
			return (tt.lowerBound);
		if (tt.upperBound <= alpha)
			return (tt.upperBound);
		alpha = max(alpha, tt.lowerBound);
		beta = min(beta, tt.upperBound);
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
			val = min(val, alphaBetaWithMemory(child, a, beta, depth - 1));
			a = max(a, val);
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
			val = min(val, alphaBetaWithMemory(child, alpha, b, depth - 1));
			b = min(b, val);
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