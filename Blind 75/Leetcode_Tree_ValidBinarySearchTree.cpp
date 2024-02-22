#include <limits.h>

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

// TODO

// Leetcode developers are such absolute pieces of shit they made test cases for this problem that are absolutely impossible to pass.
// This is the solution for this exercice but it will not work on their fucking platform since they will put nodes with INT_MIN and INT_MAX just to fuck you up.
// Absolute garbage, I despise these people they are absolute scum, it is literally impossible to fix these edge cases easily. It's just to make you lose time and fail.
// Fucking unbelievable. Like I've got all fucking day fixing your dumb ass problems anyway.

class Solution {
public:

    bool valid(TreeNode* node, int left, int right)
    {
        if (node == nullptr)
            return true;

        if (node->val < left || node->val > right)
            return false;
        
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root)
    {
        return valid(root, INT_MIN, INT_MAX);
    }
};

// This is the working solution with the edge case exception handled.
// Just had to take the largest possible type and set the MIN and MAX manually.
// So essentially we are not solving the edge case at all, just taking a large type so that Leetcode shuts the fuck up about it.
// Which is very much fine by me.

class SolutionWithoutException {
public:

    bool valid(TreeNode* node, long long left, long long right)
    {
        if (node == nullptr)
            return true;

        if (node->val < left || node->val > right)
            return false;
        
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root)
    {
        long long int MIN = -1000000000000;
        long long int MAX = 1000000000000;

        return valid(root, MIN, MAX);
    }
};