#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Best Solution
class BestSolution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        // Go through the list once and replace every element in place
        for (int i = 0; i < nums.size(); ++i) {
            // If the element is val, skip it
            // That way every val will be replaced, and the elements after each val will be shifted left
            if (nums[i] != val){
                nums[p] = nums[i];
                p++;
            }
        }
        // In the end return the placement index
        return p;
    }
};

// I Have Huge Balls Solution
class BigDickSolution {
public:
    // Does exactly the same thing
    int removeElement(vector<int>& nums, int val) {
 		int i = 0, p = 0, n = nums.size();
		while (i < n) {
			int x = nums[i];
			if (x != val) {
				nums[p++] = x;
			}
			++i;
		}
		return p;
    }
};