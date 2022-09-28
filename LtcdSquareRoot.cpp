using namespace std;

// Linear Search Solution.
// Check each integer and their square and return the closest one to the target.

class Solution {
public:
    int mySqrt(int x) {
        int root = 0;
        for (int i = 0; i < x; ++i){
            int sq = i * i;
            if (sq > x)
                break;
            root = i;
        }
        return root;
    }
};

// Binary Search Solution
// Here we know the square root of our value is in the range 1 -> value, so we can just perform a binary search in this range.
// The particularity here is that we do not search for the exact value, but the smallest closest value.
// Therefore, whenever we find a value that is smaller than our target, we save it.
// In the end we return that saved value.
// The reason we do not check for the exact value (though we could in principle) is because of overflow.
// If the input value is very large, then the mid value might be very large too, and multiplying it by itself can cause an overflow. 

class Solution {
public:
    int mySqrt(int x){
        if (x == 0 || x == 1)
            return x;
        int left = 1, right = x;
        int mid;
        int root;
        while (left <= right){
            mid = ((right - left) / 2) + left;
            if (mid <= x / mid){
                root = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return root;
    }
};