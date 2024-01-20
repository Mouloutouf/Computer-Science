#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (nums.size() == 0)
            return {};

        map<int, int> numberCounts;
        vector<set<int>> frequentElements = vector<set<int>>();

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int count = 0;

            if (numberCounts.count(num))
                count = numberCounts[num];
            
            numberCounts[num]++;
            
            if (count > 0)
                frequentElements[count].erase(num);
            
            if (frequentElements.size() == count)
                frequentElements.push_back(set<int>({num}));
            else
                frequentElements[count].insert(num);
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