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

// Given two Binary Trees, return if they are identical.

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr || q == nullptr)
        {
            if (p == nullptr && q == nullptr)
                return true;

            return false;
        }

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
        return false;
    }
};

// This is a better written solution than the one above

class SameSolution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};