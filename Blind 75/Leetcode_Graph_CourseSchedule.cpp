#include <vector>
#include <set>
#include <queue>

using namespace std;

// TODO IMPORTANT

// /!\ Review this

// This is a correct solution

class Solution {
public:

    bool dfs(vector<vector<int>>& adjacencyList, set<int>& validCourses, set<int>& path, int course)
    {
        if (path.count(course))
            return false;
        
        path.insert(course);

        for (int n : adjacencyList[course])
        {
            if (validCourses.count(n))
                continue;

            if (dfs(adjacencyList, validCourses, path, n) == false)
                return false;
        }

        path.erase(course);
        validCourses.insert(course);

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adjacencyList(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i)
            adjacencyList[prerequisites[i][1]].push_back(prerequisites[i][0]);

        set<int> validCourses;
        set<int> path;

        int invalid = 0;

        for (int i = 0; i < numCourses; ++i)
        {
            if (validCourses.count(i))
                continue;

            invalid += dfs(adjacencyList, validCourses, path, i) == false;
        }

        return invalid == 0;
    }
};

// TODO ANALYSIS

// This is not my code

// I do not fully understand this solution, especially what indegree means specifically, but I can see how this works
// I think that indegree just means the number of required courses at the moment

class OtherSolution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adjacency(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            adjacency[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (q.empty() == false)
        {
            int course = q.front();
            q.pop();

            result.push_back(course);

            for (int n : adjacency[course])
            {
                indegree[n]--;

                if (indegree[n] == 0)
                    q.push(n);
            }
        }

        return result.size() == numCourses;
    }
};