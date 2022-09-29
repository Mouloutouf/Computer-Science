#include <vector>
using namespace std;

// The below solution does not work.
// It's an attempt at Binary Search but is too complex.
// The condition for the while loop is cumbersome, since I did not know how to check if both pointers were at the same position.

class BadSolution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int mid = nums.size() / 2;
        int left = 0;
        int right = nums.size() - 1;
        while (nums[mid] != target){
            if (nums[mid] > target){
                right = mid;
                mid -= (right - left) / 2;
            }
            else{
                left = mid;
                mid += (right - left) / 2;
            }
            if (left == right)
                return -1;
        }
        return mid;
    }
};

// This is the solution. And the main one.
// This is how you perform a Binary Search.
// You loop through the array using two pointers, one at front, the other at back, and keep processing until a pointer bypass another, or the value is found.
// At each check, you calculate a mid point using both pointers, and check whether the value at that mid point is the target. If it is return it.
// If it is not, then either it is greater than target, in which case you reset the left pointer, since you need to check greater values, which are on the right
// Or it is smaller than target, in which case you reset the right pointer to look for smaller values, on the left.
// And that's it.

class BinarySearchSolution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right){
            mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};

// Here we take into account integer overflow, when calculating the mid value.
// We calculate the delta between right and left, divide that, and add it to left. Instead of adding both values and divide them.
// This is because the two values may be very large, and adding them might cause an overflow. By taking only one of the value (left) and adding a delta
// we can be sure there will be no overflow. And the result is the same.

class EdgeBinarySearchSolution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right){
            mid = ((right - left) / 2) + left;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

