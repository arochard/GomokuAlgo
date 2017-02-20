#include "main.hpp"
#include "Node.hpp"
#include "sparsepp.hpp"

spp::sparse_hash_map<uint64_t, hashEntry>* 		createHashTable()
{
	spp::sparse_hash_map<uint64_t, hashEntry>	hashTable;
	
	return (&hashTable);
}

uint64_t 									getHashKey(Node* node)
{

}

bool 										checkTable(Node* node)
{

}