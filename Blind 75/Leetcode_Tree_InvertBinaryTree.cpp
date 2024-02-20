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

// Given a Binary Tree, reverse all the nodes, essentially meaning right leaf becomes left leaf and vice versa, in the entire tree.

// This is very easy, just inverse the leaves and do it recursively and you're done.

class Solution {
public:

    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
            return root;

        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};