#include <set>

using namespace std;

set<set<int>> powerset(set<int> baseSet)
{
    set<set<int>> result;
    result.insert({});

    // go through each number in the set
    // then implement something else cause this ain't right

    for (int i = 1; i <= baseSet.size(); ++i)
    {
        for (int j = 0; j < baseSet.size(); ++j)
        {
            if (i == 1)
            {
                result.insert({baseSet[j]});
            }
            if (i == 2)
            {
                for (int k = 0; k < baseSet.size(); ++k)
                {
                    if (k == j)
                        continue;
                    
                    set<int> newest(baseSet[j]);
                    newest.insert(baseSet[k]);
                }
            }
        }
    }
    
    return result;
}