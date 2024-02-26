#include <vector>
#include <map>
#include <set>

using namespace std;

// EXPLANATION

// Build up the graph with nodes

// Then go through the nodes with DFS starting at the lowest value node (could be any node but that's just so we can start somewhere)
// We will then go through the graph and mark each node as visited into a set until all nodes have been visited.

// During this process, if we ever encounter a loop we return false immediately.
// We encounter a loop whenever we explore a node that was already visited, e.g. already added to the visited set.

// Everytime we are on a node and need to continue, we will try to visit every neighbor of that node, unless that neighbor is the node we just came from.
// This is very important as it will prevent us from encountering false loops. We therefore need to keep track of the previous node during the process.

// At the end of the process, we shall check if the number of nodes in the set is equal to the number n of nodes given as input.
// If they are not equal then some of the nodes are not connected to the other nodes, and the tree is therefore invalid.
// Otherwise, the graph is a valid tree where all nodes are connected and in which there are no loops.

struct Node
{
    int val = 0;
    vector<Node*> neighbors = vector<Node*>();

    Node(int x) : val(x) {}
};

class Solution {
public:

    bool dfs(Node* cur, Node* prev, set<int>& visited)
    {
        if (visited.count(cur->val))
            return false;
        
        visited.insert(cur->val);

        for (Node* n : cur->neighbors)
        {
            if (n == prev)
                continue;
            
            if (dfs(n, cur, visited) == false)
                return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (n == 0)
            return false;

        map<int, Node*> nodes;

        for (int i = 0; i < edges.size(); ++i)
        {
            int val1 = edges[i][0];
            int val2 = edges[i][1];

            Node* first = nodes.count(val1) ? nodes[val1] : new Node(val1);
            Node* second = nodes.count(val2) ? nodes[val2] : new Node(val2);
            first->neighbors.push_back(second);
            second->neighbors.push_back(first);
        }

        Node* root = nodes[0];

        set<int> visited;

        Node* dum = new Node(-1);
        bool search = dfs(root, dum, visited);
        delete dum;

        if (search == false || visited.size() != n)
            return false;

        return true;
    }
};

// Other Solution

// This works perfectly
// It is the same solution as above but uses an adjacency list to represent a node and its neighbors, instead of making actual nodes, which is definitely simpler.
// The solution above does not work but I don't know why, it's the exact same logic apart from the construction of the graph itself.

class Solution {
public:

    bool dfs(vector<vector<int>>& adjacencyList, set<int>& visited, int prev, int cur)
    {
        if (visited.count(cur))
            return false;
        
        visited.insert(cur);
    
        for (int n : adjacencyList[cur])
        {
            if (n == prev)
                continue;
            
            if (dfs(adjacencyList, visited, cur, n) == false)
                return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < edges.size(); ++i)
        {
            adjacencyList[edges[i][0]].push_back(edges[i][1]);
            adjacencyList[edges[i][1]].push_back(edges[i][0]);
        }
        
        set<int> visited;

        if (dfs(adjacencyList, visited, -1, 0) == false || visited.size() != n)
            return false;
        
        return true;
    }
};