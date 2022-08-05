#include <vector>
#include <algorithm>
using namespace std;

// Given Two Arrays of Integers, such that Array 1 has m Elements and Array 2 has n Elements, and where Array 1 has m + n size (with outstanding values being 0)
// Merge the Two Arrays together such that the new Array is Sorted.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; ++i){
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
    }
};