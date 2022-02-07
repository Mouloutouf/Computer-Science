#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Average Solution
class MySolution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 0)
            return;
        int p = 0;
        // Go through the list starting at the second element
        // Check for each element the previous one
        for (int i = 1; i < nums.size(); ++i){
            // If previous is a zero and element is not, replace the element at position p, increase p
            if (nums[i] != 0 && nums[i - 1] == 0){
                nums[p] = nums[i];
                nums[i] = 0;
                p++;
            }
            // If element is a zero and previous is not, set the value of p to be the position of the current element
            if (nums[i] == 0 && nums[i - 1] != 0){
                p = i;
            }
        }
    }
};

// Best Solution
class SmartSolution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0;
        // Go through the list and replace every element in place
        // If the element is a zero, skip it
        // That way every zero will be replaced, and the elements after each zero will be shifted left
        for (int i=0;i<nums.size();i++) {
            if (nums[i]!=0) {
                nums[p]=nums[i];
                p++;
            }
        }
        // In the end, when every element has been replaced in place, and all zeros in the initial list have been overwritten
        // Replace everything left in the list with zeros
        while (p<nums.size()) {
            nums[p]=0;
            p++;
        }
    }
};