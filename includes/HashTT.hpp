#include "main.hpp"

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
		std::unordered_map<uint64_t, HashEntry>	_hashTable;
	
	public:
		HashEntry									*checkHashTable(Node* node);
		void 										createNewEntry(Node* node);

		HashTT();
		~HashTT();
	
};