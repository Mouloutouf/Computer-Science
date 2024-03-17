#include <vector>
#include <map>

using namespace std;

class Node {
public:

    int val = 0;
    vector<Node*> neighbors = vector<Node*>();

    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

// EXPLANATION

// Given an undirected connected graph, return an exact copy of that graph.

// Here we just go through the nodes of the graph recursively, copy them as we go along, and assign them as neighbors.
// But in order to know if we have already cloned a node, we use a map to store the old and new pointer adress of the 'same' node, and check it to see if we have already cloned the node or not.

// The code is quite straightforward.

class Solution {
public:

    Node* cloneNode(Node* node, map<Node*, Node*>& map)
    {
        Node* newNode = new Node(node->val);
        map[node] = newNode;

        for (Node* neighbor : node->neighbors)
        {
            Node* newNeighbor;
            if (map.count(neighbor) == true)
            {
                newNeighbor = map[neighbor];
                newNode->neighbors.push_back(map[neighbor]);
            }
            else
            {
                newNeighbor = cloneNode(neighbor, map);
                newNode->neighbors.push_back(newNeighbor);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node)
    {
        if (node == nullptr)
            return nullptr;

        map<Node*, Node*> map;

        return cloneNode(node, map);
    }
};