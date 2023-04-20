#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Given the root node of a binary tree, find the deepest node in the tree
// To do this, we use recursion, in order to go through the tree and perform the same check at each step.
// The step is as follows, at a current node :
// - if there are no leaf nodes, return the current node, and its depth
// - if there is no right or no left leaf node, then search the other leaf node, increase the depth
// - if there are both leaf nodes, search both leaf nodes, then select the one with the greater depth, increase the depth
// In the end, return the deepest node and its depth

// Essentially, using a pair of node/depth allows us to perform the max check when both leaf nodes are present,
// so that we can check which one is greater using the second value from the pair

struct Node
{
    Node()
    {
    }
    Node(Node* _left = nullptr, Node* _right = nullptr)
        : left(_left), right(_right)
    {
    }

    Node* left;
    Node* right;
};

pair<Node*, int> increaseDepth(pair<Node*, int> nodeDepth)
{
    return pair<Node*, int>(nodeDepth.first, nodeDepth.second + 1);
}

pair<Node*, int> deepestNode(Node& node)
{
    if (node.left == nullptr && node.right == nullptr)
        return pair<Node*, int>(&node, 1);
    
    else if (node.right == nullptr)
        return increaseDepth(deepestNode(*node.left));
    else if (node.left == nullptr)
        return increaseDepth(deepestNode(*node.right));
    
    return increaseDepth(max(deepestNode(*node.left), deepestNode(*node.right), [](pair<Node*, int> first, pair<Node*, int> second)
    {
        return first.second > second.second;
    }));
}

Node* findDeepestNode(Node& rootNode)
{
    return deepestNode(rootNode).first;
}