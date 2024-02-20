#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// EXPLANATION

// Given a Binary Tree, return the maximum depth of the tree.

// Here we just go through each tree leaves recursively to retrieve the depth from each side, then pick the max depth we find.
// We then need to add one to increase the depth. And if the root node is empty we are on an empty leaf therefore there is no depth.
// We end up finding the maximum depth after looking at the entire tree.

class Solution {
public:

    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int depth = max(maxDepth(root->left), maxDepth(root->right));
        return depth + 1;
    }
};