#include <vector>

using namespace std;

// EXPLANATION

// Given an integer n, return an array of all the numbers from 0 to n where each value i represents the number of 1's in the binary representation of i.
// You should solve this in O(n) time.

// Leetcode says this is an easy problem. They also say this is a bit manipulation exercise.
// But this is only true if you do a standard slow solution (or if you cheat since in C++ you can do it with just a simple method).
// Otherwise, if you want to do the performant solution, and the one that actually takes brain, then this problem is neither easy nor does it uses any bit manipulation techniques.
// This is literally dynamic programming, and the explanation for why this works is not very evident at first.

// The problem that we have at hand is really just counting bits, but how can we do it without making an extra loop to actually count the 1's in the bit representation of i ?
// What we can notice is that the bit representation of numbers evolves in a very linear way. Essentially that means that the representations sort of repeat themselves.
// For instance, all the numbers from 0 to 15 have the exact same representation to the ones from 16 to 31, with a 1 bit difference, being precisely the bit of value 16.
// Essentially the numbers from 16 to 31 are basically the numbers from 0 to 15, but + 16. And this applies to every representation, since each bit basically mean : is this specific number present ?
// That way, we can use this repeating property to solve this problem with a dynamic programming approach, meaning we will reuse our previous results to compute the next ones.
// See picture for a visual explanation of this solution.

// Okay, so now in order to implement this solution, we have to progressively update our result array, and use the previous values from this array to compute the new ones.
// In order to do this, we essentially need to know what is the highest bit currently active, since we can then know the representation of every single number from the current highest bit value
// to the last value before the next highest bit. So for instance, if the highest bit is 16, then for every value from 16 to 31 (essentially the 16 next values),
// we can compute their representation by just taking the previous representations of the numbers from 0 to 15, and just adding 1 for 16.
// By doing this consistently, we are going to be able to compute the representation of all the numbers from 1, to 2, to 4, 8, 16, 32, etc. until there are no more numbers to count.

// This runs in O(n) time and in O(1) space

class Solution {
public:

    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);
        
        // Current highest bit
        int b = 1;

        // go through all the numbers
        for (int i = 1; i <= n; ++i)
        {
            // if the current number is twice as big as the current highest bit, then it is the highest bit, so replace it
            if (b * 2 == i)
                b = i;
            
            // Compute the representation of the current number using 1 (for the highest bit) + the representation of current number - highest bit
            dp[i] = 1 + dp[i - b];
        }
        return dp;
    }
};

// This solution works just like the one above, and uses the built-in C++ function that allows to count bits
// It is a bit of a cheat, but it works.

class OtherSolution {
public:

    vector<int> countBits(int n)
    {
        vector<int> result(n + 1, 0);

        for (int i = 0; i <= n; ++i)
            result[i] = __builtin_popcount(i);

        return result;
    }
};

// This is the standard (but slow) solution where you actually count the bits yourself.
// You can easily know if the last bit of a certain number n is a 1, by doing n & 1.
// You then just need to bitshift that number so you can check all its bits until it gets to zero.
// Do this for every number, then return the result.

// This unfortunately runs in O(nlogn) since we have two loops going on.

class StandardSolution {
public:

    vector<int> countBits(int n)
    {
        vector<int> result(n + 1, 0);

        for (int i = 0; i <= n; ++i)
        {
            // Loop through the bit and bitshift it until it gets to zero
            while (i > 0)
            {
                // increment the result if the last bit of i is indeed a 1
                result[i] += i & 1;
                // Shift i to the right to get to the next bit
                i >>= 1;
            }
        }

        return result;
    }
};