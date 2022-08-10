// Remove duplicates from list
// Ex : [0,0,2,4,4,6,7,7,7,7] -> [0,2,4,6,7]

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        int v = nums[0];
        int x = 1;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] > v){
                v = nums[i];
                nums[x] = v;
                x++;
            }
        }
        return x;
    }
};
