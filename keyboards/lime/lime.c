#include "lime.h"

#ifdef SWAP_HANDS_ENABLE

__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] =
    // The LAYOUT macro could work for this, but it was harder to figure out the
    // identity using it.

    // This is the identity layout.
/*
{ \
    { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} }, \
    { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} }, \
    { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} }, \
    { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} }, \
    { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} }, \
    { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} }, \
    \
    { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} }, \
    { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} }, \
    { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} }, \
    { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} }, \
    { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} }, \
    { {0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10} }, \
};
*/

    // This is the mirror, q <-> p, w <-> o, etc...
{ \
 { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} }, \
 { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} }, \
 { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} }, \
 { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} }, \
 { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} }, \
 { {0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10} }, \
                                                     \
 { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} }, \
 { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} }, \
 { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} }, \
 { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} }, \
 { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} }, \
 { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} }, \
};

#endif
