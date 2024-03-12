#include "stdint.h"

using namespace std;

// EXPLANATION

// Given an unsigned integer n, return the amount of 1 bits of its binary representation.

// In order to do this, we need to loop to check if the first bit is a 0 or a 1, then shift everything to the right, in order to check the next bit
// We do this until we have shifted all the bits, e.g. the number n has been reduced to a single binary value.

// This code runs in O(1).

class Solution {
public:

    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n > 0)
        {
            // Check if first bit is 0 or 1, e.g it is pair or impair
            result += n % 2 == 1;

            // Bitshift to the right
            n = n >> 1;
        }
        return result;
    }
};

// This other solution uses some crazy ass bit manipulation technique to only count the ones and skip all zeroes.
// It is still an overkill solution since the above code runs in O(1), so this code is not going to actually get better than O(1)
// even though it technically does less iterations than the above code.

// What we do here is we subtract 1 from n at every iteration and then use the logical AND operator to only get the remaining identical bits.
// That way, we end up getting only zeroes in n after exactly x iterations, where x is the amount of 1 bits in the number n.

class OtherSolution {
public:

    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n > 0)
        {
            n &= (n - 1);
            result++;
        }
        return result;
    }
};