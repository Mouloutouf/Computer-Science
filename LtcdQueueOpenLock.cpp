#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

class Solution {
    string directions[8] = {"+0001", "-0001", "+0010", "-0010", "+1000", "-1000", "+0100", "-0100"};
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> search;
        search.push("0000");

        set<string> visited;
        visited.emplace("0000");

        map<string, string> previous;

        while (search.empty() != true){
            string combination = search.front();
            search.pop();
            
            for (int i = 0; i < 4; ++i){
                for (int j = 0; j < 2; ++j){
                    int sign = j == 0 ? -1 : 1;
                    string direction = combination;
                    
                    int add = (direction[i] - '0') + sign;
                    if (add > 9){
                        add = 0;
                    }
                    else if (add < 0){
                        add = 9;
                    }
                    
                    direction[i] = add + '0';
                    
                    if (visited.count(direction) != 0){
                        continue;
                    }
                    for (string& deadend : deadends){
                        if (direction == deadend){
                            continue;
                        }
                    }
                    
                    search.push(direction);
                    visited.emplace(direction);
                    previous.emplace(direction, combination);
                }
            }
        }
        
        int steps = 0;
        for (string prev = target; prev.empty() == false; prev = previous[prev]){
            steps++;
            if (prev == "0000"){
                return steps;
            }
        }
        return -1;
    }
};