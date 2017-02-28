#include "main.hpp"
#include "sparsepp.hpp"

class 	HashEntry
{
	public:
		uint8_t			depth;
		uint16_t 		value;
		uint16_t		lowerBound;
		uint16_t		upperBound;

		HashEntry(){};
		~HashEntry(){};
};

class HashTT
{
	private:
		spp::sparse_hash_map<uint64_t, hashEntry>	_hashTable;
	
	public:
		hashEntry									checkHashTable(Node* node);
		void 										createNewEntry(Node* node);

		HashTT();
		~HashTT();
	
};