#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

// This code works quite fine, even handles all the smart ass edge cases from Leetcode, but still Leetcode thinks this is slow, even though there is no runtime
// complexity required anywhere in the damn exercice. So yeah, that's fucking Leetcode in a nutshell. They are making every single thing difficult for you, all the time.
// I'm starting to grow sick of their bullshit platform, for real.

// Actually, there is no way this code runs too slow. It's virtually impossible since at maxima, I will run it 80000 times, for 10000 elements, which is not a lot.
// So the code is probably stuck in some loop with larger inputs. But that too is impossible since my loops are fixed and my queue will eventually empty itself.
// So I have no clue what Leetcode did with their input to achieve a Timeout, but fucking congratulations guys, and thanks for not giving any logs nor any other
// way to debug this. Jesus christ.

// I swear to god if the timeout is caused by the checks on deadends for each neighbour of each elements (which indeed could cause a slower calculation, though, then again
// they never said anything about time complexity) I'm going to be real pissed. I mean how the fuck am I supposed to do this efficiently, when they give a god damn vector
// of deadends when they could have given a fucking hashset, and make things easier for everyone.
// Now I'm the one that has to convert their stupid jack ass data structure into a better one to solve the problem. I am sick of this shit, just make it easier for once.

// Okay well Leetcode here again, just fixed their hashset problem, although I shouldn't be the one to do it, but fair enough, it was quite obvious it could cause a problem,
// since there is no limit to the amount of deadends you can set.
// But still, it doesn't work, timeout again, this time with absolutely no reason, except a big amount of deadends, which should not be a problem since I have a hashset.
// So I have no idea why they timeout the shit out of my code everytime, even though there is now virtually no way it can exceed 100000 frames

class Solution {
    string directions[8] = {"+0001", "-0001", "+0010", "-0010", "+1000", "-1000", "+0100", "-0100"};
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> visited;
        for (string& deadend : deadends){
            if (deadend == "0000"){
                return -1;
            }
            visited.emplace(deadend);
        }
        visited.emplace("0000");

        queue<string> search;
        search.push("0000");

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
                    
                    search.push(direction);
                    visited.emplace(direction);
                    previous.emplace(direction, combination);
                }
            }
        }
        
        int steps = 0;
        for (string prev = target; prev.empty() == false; prev = previous[prev]){
            if (prev == "0000"){
                return steps;
            }
            steps++;
        }
        return -1;
    }
};