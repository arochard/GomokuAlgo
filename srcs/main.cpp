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

Node 		*generateTree(uint8_t map[SIZE_BOARD][SIZE_BOARD])
{
	Node 	*root;
	std::vector<uint16_t> moves = findPossibleMove(map);

	//DEBUG
	for (auto& m : moves)
		std::cout << m << " ";

	// if (root == NULL)
	// 	root = Node(map, 0, TRUE, 10, 2);

	// for(auto& M : moves) //vector of possible moves
	// {
		
	// }
	return (root);
}

int main()
{
	uint8_t	map[SIZE_BOARD][SIZE_BOARD] = 
	{
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	Node* 	tree = generateTree(map);

	return 0;
}

// 153 155 172