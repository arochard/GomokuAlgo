#include "main.hpp"
#include "Node.hpp"

std::vector<uint16_t>		findPossibleMove(uint8_t map[SIZE_BOARD][SIZE_BOARD])
{
	std::vector<uint16_t> 	moves;

	for (int8_t l = 0; l < SIZE_BOARD - 1; l++)
	{
		for (int8_t c = 0; c < SIZE_BOARD - 1; c++)
		{
			if (map[l][c] != 0)
			{
				if (map[l - 1][c] == 0 && l != 0)
					moves.push_back(((l - 1) * (SIZE_BOARD)) + c);
				if (map[l + 1][c] == 0 && l != SIZE_BOARD)
					moves.push_back(((l + 1) * (SIZE_BOARD)) + c);
				if (map[l][c - 1] == 0 && c != 0)
					moves.push_back((l * SIZE_BOARD) + (c - 1));
				if (map[l][c + 1] == 0 && c != SIZE_BOARD)
					moves.push_back((l * SIZE_BOARD) + (c + 1));
				//diag
				if (map[l - 1][c - 1] == 0 && l != 0 && c != 0)
					moves.push_back(((l - 1) * SIZE_BOARD) + (c - 1));

				if (map[l + 1][c + 1] == 0 && l != SIZE_BOARD && c != SIZE_BOARD)
					moves.push_back(((l + 1) * SIZE_BOARD) + (c + 1));

				if (map[l - 1][c + 1] == 0 && l != 0 && c != SIZE_BOARD)
					moves.push_back(((l - 1) * SIZE_BOARD) + (c + 1));

				if (map[l + 1][c - 1] == 0 && l != SIZE_BOARD && c != 0)
					moves.push_back(((l + 1) * SIZE_BOARD) + (c - 1));
			}
		}
	}
	return (moves);
}

void 			generateTree(Node *node)
{
	//DEBUG
	for (auto& l : node->map)
	{
		for (auto& c : l)
		{
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}

	if (node->depth < 0)
		return;

	std::vector<uint16_t> moves = findPossibleMove(node->map);
	Node *tmp;
	//DEBUG
	// for (auto& m : moves)
		std::cout << "depth : " << node->depth << std::endl;

	//depth--;

	for(auto& M : moves) //vector of possible moves
	{
		if ((node->depth - 1) % 2 == 1)
			tmp = new Node(node->map, M, false, node->depth - 1, 2);
		else
			tmp = new Node(node->map, M, true, node->depth - 1, 1);

		node->insertChild(tmp);
		generateTree(tmp);
	}
}

int main()
{
	uint8_t	map[SIZE_BOARD][SIZE_BOARD] = 
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	Node *tree = new Node(map, -1, true, 2, 1);
	generateTree(tree);

	return 0;
}