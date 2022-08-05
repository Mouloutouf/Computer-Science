#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &biggest = nums1.size() > nums2.size() ? nums1 : nums2;
        vector<int> &smallest = nums1.size() > nums2.size() ? nums2 : nums1;
        int i = 0, j = 0;
        vector<int> intersect;
        while (j < smallest.size()){
            if (biggest[i] == smallest[j]){
                intersect.push_back(biggest[i]);
                ++j;
            }
            ++i;
            if (i >= biggest.size()){
                ++j;
                i = 0;
            }
        }
    }
};