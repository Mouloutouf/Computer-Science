using namespace std;

// Classic Binary Search, I need to guess a number given a range.
// For that the exercice gives us a method to know whether our guess is correct, too high, or too low.
// Then we can just perform a normal binary search and return the value.

class Solution {
public:
    int guess(int num);
    int guessNumber(int n) {
        int left = 1, right = n;
        int mid;
        while (left <= right){
            mid = ((right - left) / 2) + left;
            if (guess(mid) == 0)
                break;
            else if (guess(mid) == -1)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return mid;
    }
};