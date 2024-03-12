#include "stdint.h"

using namespace std;

// Reverse a given 32 bits unsigned integer

// Here we essentially loop, to retrieve the most left bit from the input n, then place it at the most right bit from the output result.
// We progressively increment our position i, and do this until we have reversed the entire number n.

class Solution {
public:

    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i)
        {
            // Get the current bit, by bitshifting n right to the current position i, and using the AND operator to know if its a 1 or a 0
            uint32_t bit = (n >> i) & 1;
            // Bitshift that bit left towards the end minus the current position i, then apply that bit to the result by using the OR operator
            result = result | (bit << (31 - i));
        }
        return result;
    }
};