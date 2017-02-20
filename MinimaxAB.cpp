#include "Node.hpp"

int 	alphaBetaWithMemory(Node *node, int alpha, int beta, int depth)
{
	int 	val;
	int 	a;
	int 	b;
	Node 	*child;

	if (checkTable(node) == TRUE)
	{
		if (node.lowerBound >= beta)
			return (node.lowerBound);
		if (node.upperBound <= alpha)
			return (node.upperBound);
		alpha = max(alpha, node.lowerBound);
		beta = min(beta, node.upperBound);
	}

	if (!depth)
		val = evaluate(node);
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
		node.upperBound = val;
		storeTable(node.upperBound);
	}
	if (val > alpha && val < beta)
	{
		node.lowerBound = val;
		node.upperBound = val;
		storeTable(node.lowerBound);
		storeTable(node.upperBound);
	}
	if (val >= beta)
	{
		node.lowerBound = val;
		storeTable(node.lowerBound);
	}
	return (val);
}