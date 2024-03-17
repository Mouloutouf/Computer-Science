#include <vector>
#include <unordered_map>

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

// TODO IMPORTANT

// /!\ Does not work, need to fix edge case will null subtree. Need to look at C++ solution which uses a custom recursive method for this

class TestSolution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.empty() == true || inorder.empty() == true)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        int i = 0;
        while (inorder[i] != preorder[0]) i++;

        int lSize = i;
        int rSize = inorder.size() - 1 - i;

        preorder.erase(preorder.begin());

        vector<int> lPreorder = vector<int>(preorder.begin(), preorder.begin() + lSize - 1);
        vector<int> lInorder = vector<int>(inorder.begin(), inorder.begin() + lSize - 1);
        vector<int> rPreorder = vector<int>(preorder.end() - rSize + 1, preorder.end());
        vector<int> rInorder = vector<int>(inorder.end() - rSize + 1, inorder.end());

        root->left = buildTree(lPreorder, lInorder);
        root->right = buildTree(rPreorder, rInorder);

        return root;
    }
};

// TODO ANALYSIS

// This is not my code

class Solution {
public:

    TreeNode* construct(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& index, int i, int j)
    {
        // Base case: If the start index exceeds the end index, return NULL (indicating a null subtree)
        if (i > j)
            return nullptr;
        
        // Create a new TreeNode with the value from the preorder traversal at the current index
        TreeNode* root = new TreeNode(preorder[index]);

        index++;
        
        // Find the index of the root value in the inorder traversal
        int mid = inorderMap[root->val];
        
        // Recursively build the left subtree with elements to the left of the root in the inorder traversal
        root->left = construct(preorder, inorderMap, index, i, mid - 1);
        
        // Recursively build the right subtree with elements to the right of the root in the inorder traversal
        root->right = construct(preorder, inorderMap, index, mid + 1, j);
        
        // Return the constructed root node
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // Create a map to store the indices of elements in the inorder traversal
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        // Initialize the index variable to track the current position in the preorder traversal
        int index = 0;
        
        // Call the recursive construct function to build the binary tree
        return construct(preorder, inorderMap, index, 0, inorder.size() - 1);
    }
};