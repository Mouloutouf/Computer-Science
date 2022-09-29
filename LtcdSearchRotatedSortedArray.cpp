#include <vector>
using namespace std;

// Here the solution is a Binary Search but a bit more complex as you need to search through two sorted portions instead of one.
// and therefore, you need to know, at any time, if you are in one portion or another, in order to adjust your right and left pointers and explore the array.
// This is possible because we know the start value of the leftmost portion, and the end value of the rightmost portion. And we can use that.
// Since we rotate the array only once, we know that the leftmost portion contains the bigger values, and the rightmost the smaller values. We can also use that.
// Also, the end value of the leftmost portion is the greatest value of the array, and the start value of the rightmost portion is the smallest value of the array.

// First Step :
// After starting the binary search we have to check where is the mid value located. Is it in the right portion or the left portion.
// To do that you just have to check if your mid value is superior to the left value (or inferior to the right value, same thing).
// For example if I have an array [0,1,2,4,5,6,7,9], and I rotate it like this [5,6,7,9,0,1,2,4].
// Then if my mid value is in the left portion, it will necessarily be greater (or equal) to the left point, if it is in the right, it will necessarily be smaller.
// Same here with [0,2,4,6,8] rotated as [8,0,2,4,6].
// Second Step :
// After that, we need to know which way to search, there are three possibilities from the portion we are in.
// First Possibility : The target value is inside our portion and is close to the portion edge. If we are in the left portion, we have to go left, if we are right, go right.
// Example, for [6,8,9,0,2,5], if we are in the left portion and our target is 6 (closer to the left edge), then we need to search towards the left.
// If we are in the right portion, and our target is 5 (closer to the right edge), then we need to search towards the right.
// This is represented by the else statement in the code.
// For the two other possibilites, we need to go the opposite way.
// Second Possibility : The target value is furthest from the portion edge and therefore is in our portion. If we are left, go right. If we are right, go left.
// Third Possibility : The target value is not in our portion. We have to go the opposite direction too.
// Both second and third possibilities imply the same search, so they are represented in the same if statement in code.

// By using all the information we have from the rotation, we can extract rules that we can exploit, and so we can then easily deduce where the target is.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right){
            mid = ((right - left) / 2) + left;
            if (nums[mid] == target)
                return mid;
            // Left portion of array
            if (nums[mid] >= nums[left]){
                if (nums[mid] < target || nums[left] > target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            // right portion of array
            else{
                if (nums[mid] > target || nums[right] < target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};