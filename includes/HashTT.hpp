#include "main.hpp"

class 	HashEntry
{
	public:
		uint8_t			depth;
		int16_t 		value;
		int16_t			lowerBound;
		int16_t			upperBound;

		HashEntry(){};
		~HashEntry(){};
};

class HashTT
{
	private:
		std::unordered_map<uint64_t, HashEntry>	_hashTable;
	
	public:
		HashEntry									*checkHashTable(Node* node);
		void 										createNewEntry(HashEntry tt);

		HashTT();
		~HashTT();
	
};