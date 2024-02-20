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

// Given a Binary Search Tree, and two nodes in that tree, find the Lowest Common Ancestor for these nodes.

// This essentially means we want to find the deepest (lowest) node in the tree which is an ancestor to both nodes.
// First of all, a Binary Search Tree is ordered in a way such that the left leaf of a node is always inferior to the node, and the right leaf is always superior.
// The way we solve this then, is by finding the split of nodes in the tree. Meaning, finding the node in the tree which is superior to one of the input node and inferior to the other input node.
// If we find this, then we have found the common ancestor to both nodes.
// This works since, for example, if we have a tree starting at 6, and two input nodes 0 and 8, then 6 is where the split occurs, and is therefore the lowest common ancestor.
// This is because if we ever go down one leaf or the other, we will never find the other value, hence this is their last common ancestor, which makes sense since they split afterwards.
// Therefore, the solution is actually quite straightforward, we loop through the tree, and go down one leaf or the other if both nodes are superior or inferior, until we find the split,
// e.g. until both nodes are not on the same side of the tree, one is inferior and one is superior, at which point we return the current node we are in, which the lowest common ancestor.
// In the case where one of the input nodes turns out to be the lowest common ancestor itself, nothing changes really since the split occurs just the same.
// For example, if the tree starts at 5, and the input nodes are 5 and 7, then the lowest common ancestor is 5, since we are not going to find that value going down the tree afterwards.

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* current = root;

        while (root != nullptr)
        {
            if (p->val > current->val && q->val > current->val)
                current = current->right;
            else if (p->val < current->val && q->val < current->val)
                current = current->left;
            else
                return current;
        }
        return nullptr;
    }
};