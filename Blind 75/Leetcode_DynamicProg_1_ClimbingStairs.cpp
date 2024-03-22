using namespace std;

// EXPLANATION

// Given a staircase that has a number n of steps, which you can climb either by going 1 step or 2 steps at a time.
// In how many distinct ways can you climb to the top ?

// This problem actually just requires us to solve the Fibonacci sequence.
// See pictures for problem explanation.

// Essentially, picture 1 shows us that we end up solving the exact same subproblems over and over if we do this recursively.
// This means that we only need to solve a certain problem once, in order to get the amount of ways to get to a certain value, then store those.
// This is what is shown in picture number 2 where we store these values then add them together progressively from the back to the front.
// This whole thing is analog to solving the Fibonacci sequence, where we add a number with its previous value.
// Hence why the solution is extremely straightforward.

// This runs in O(n) time and in O(1) space

class Solution {
public:

    int climbStairs(int n)
    {
        int one = 1;
        int two = 1;

        for (int i = n - 1; i > 0; --i)
        {
            int prev = one;
            one = one + two;
            two = prev;
        }
        return one;
    }
};