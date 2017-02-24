#ifndef __MAIN__
# define __MAIN__

//Pattern weight for heuristic evaluation
//Cat 0
# define FIVE 10000 // XXXXX     -> zero step to win
//Cat 1
# define FOUR 200 // _XXXX| or |XXXX_   ->  one step to win
# define BROKEN_FOUR 200 // XX_XX 	  ->  one step to win
# define STRAIGHT_FOUR 500 // _XXXX_  ->  one step to win
//Cat 2
# define THREE 30 //__XXX__ or O_XXX__  -> two steps to win
# define BROKEN_THREE 60 // _X_XX_ or _XX_X_  -> two steps to win
//Cat 3
# define SINGLE 5  // X or _XO or _X_ ect...   -> many steps to win

# define SIZE_BOARD 19

# include <vector>
# include <cstdint>
# include <algorithm>



#endif