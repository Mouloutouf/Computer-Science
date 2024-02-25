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

class Solution {
public:

    bool sameTree(TreeNode* s, TreeNode* t)
    {
        if (s == nullptr && t == nullptr)
            return true;

        if (s == nullptr || t == nullptr || s->val != t->val)
            return false;

        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        // A null subtree is a valid subtree of another tree
        if (subRoot == nullptr)
            return true;

        // A null tree cannot have any subtrees
        if (root == nullptr)
            return false;

        // Check if they are the same recursively
        if (sameTree(root, subRoot) == true)
            return true;

        // They are not the same, thus, explore both the left and right subtrees of the tree resursively
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};