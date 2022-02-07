#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Find missing numbers in array :
// Given an array of n elements where elements range from 1 to n, find all the numbers in that range that are not present in the array.
// And return an array containing these missing numbers
// Ex : Given an array of 5 elements [1, 3, 2, 2, 1], find all the numbers in the range [1, 5] that are not present in the array.
// Here, the program should return [4, 5]

// Smart Solution

// This is O(n) and in-place

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // Initialize the return array with zeros, and with the size of the array of numbers
        vector<int> d(n, 0);
        // For each element in the array of numbers, place the element inside the return array, at the position of that number
        // Ex : for an element of value 4, place it in the return array at the same position, which is 3 (since our range starts at 1 but the array starts at 0)
        for (int i = 0; i < n; i++) {
            int x = nums[i] - 1;
            d[x] = nums[i];
        }
        // Then, loop again to check for all the remaining zeros inside the return array
        // For each zero found, overwrite the corresponding number in the return array, from the start of the array, then increase the count
        // Ex : if a zero is found at position 4, the corresponding number would be 5 (since our range starts at 1 and that of the array starts at 0)
        // then write that number in the same array at the count position (if this is the third zero found, position will be 2, for instance)
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (d[j] == 0) {
                d[c] = j + 1;
                c++;
            }
        }
        // After that, resize the array to contain only the missing numbers, and shrink that array so that size and capacity are the same
        // (this is only necessary for c++ vectors)
        // return the array of missing numbers
        d.resize(c);
        d.shrink_to_fit();
        return d;
    }
};