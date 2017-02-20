#ifndef __MAIN__
# define __MAIN__

enum 	TypeVal
{
	EXACT_VALUE,
	LOWER_BOUND,
	UPPER_BOUND
};

typedef struct 		s_hash_entry
{
	TypeVal 		type;
	uint8_t			depth;
	uint32_t 		score;
}					hashEntry;

#endif