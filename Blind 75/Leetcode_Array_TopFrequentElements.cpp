#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

// EXPLANATION

// Given an array nums, return the k most frequent elements, meaning the elements that appear the most in that array
// Example : [1,1,1,2,2,3], k = 2, should return [1,2] because 1 and 2 are the elements that appear the most in that array

// The idea to solve this problem, is to go through the array and count how many times we encounter each number, for that we can use a hashmap, which takes the num as key and count as value.
// And then we need to register these numbers in an array where each index represents the count of a number, then store the numbers according to their count.
// This will actually be an array of arrays, since several numbers may have the same count and will be registered at the same index.
// To finish the solution, we go through that array in reverse order, starting with the biggest count, and then add to the result array the numbers we find, until we hit k elements, then return.

// This first solution was quite inefficient since I was counting and registering the numbers at the same time, meaning I had to erase and re-insert numbers constantly inside of a set.
// This is therefore quite slow.

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (nums.size() == 0)
            return {};

        map<int, int> numberCounts;
        vector<set<int>> frequentElements = vector<set<int>>(nums.size() + 1, set<int>());

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];

            int count = 0;
            if (numberCounts.count(num))
                count = numberCounts[num];
            
            numberCounts[num]++;
            
            if (count > 0)
                frequentElements[count].erase(num);
            
            frequentElements[count + 1].insert(num);
        }

        vector<int> result = vector<int>();

        for (int j = frequentElements.size() - 1; j >= 0; --j)
        {
            for (int element : frequentElements[j])
            {
                result.push_back(element);

                if (result.size() == k)
                    return result;
            }
        }
        return result;
    }
};

// This is the best solution of the bunch, where I first count all the numbers and put them in a map, then I go through them to register them in the array, this is way more efficient,
// since I do not need to erase and register numbers again. I therefore don't need to use a set either and can use a standard array for the array of arrays.
// Also, using an unordered map is more efficient since we don't need to have the numbers (the keys) in a certain order.
// This is way faster.

// However, IMPORTANT, this is a bit memory inefficient, since we initialize the array of arrays to have the size of our input array, since we know that at most, the input array will have
// every single value be the same number, which means the count of that number will be at most the size of the array. Therefore our array of arrays will also have at most a max count of input array size.
// This can be improved however by using a priority queue, which does not need to be initialized with a large size, and can store elements in order of priority.

class GoodSolution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (nums.size() == 0)
            return {};

        unordered_map<int, int> counts;
        vector<vector<int>> frequentElements = vector<vector<int>>(nums.size() + 1, vector<int>());

        for (int i = 0; i < nums.size(); ++i)
            counts[nums[i]]++;

        for (auto& pair : counts)
        {
            int num = pair.first;
            int count = pair.second;

            frequentElements[count].push_back(num);
        }
        
        vector<int> result = vector<int>();

        for (int j = frequentElements.size() - 1; j >= 0; --j)
        {
            for (int element : frequentElements[j])
            {
                result.push_back(element);

                if (result.size() == k)
                    return result;
            }
        }
        return result;
    }
};
