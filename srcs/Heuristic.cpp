#include "main.hpp"
#include "Node.hpp"

static uint16_t	checkVertical(Node *node, uint8_t col, uint8_t row)
{
	uint8_t 	k = 0;
	char 		plStone = node->stone;
	char 		curStone = node->map[col][row];

			
}

static uint16_t	checkHorizontal(Node *node, uint8_t col, uint8_t row)
{
	
}

static uint16_t	checkDiagonal(Node *node, uint8_t col, uint8_t row)
{
	
}

uint16_t		evalHeuristic(Node *node)
{
	uint16_t	result = 0;

	for (uint8_t col = 0; col < SIZE_BOARD; col++)
	{
		for (uint8_t row = 0; row < SIZE_BOARD; row++)
		{
			if (node->map[col][row] != '-')
			{
				result += checkVertical(node, col, row);
				result += checkHorizontal(node, col, row);
				result += checkDiagonal(node, col, row);
			}
		}
	}
	return (result);
}