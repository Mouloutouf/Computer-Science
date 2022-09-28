#include <vector>
using namespace std;

class Solution {
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