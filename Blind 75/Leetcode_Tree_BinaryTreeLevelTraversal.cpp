#include <vector>
#include <queue>

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

// Use a Breadth First Search

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result = vector<vector<int>>();

        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() == false)
        {
            int qLength = q.size();
            vector<int> values = vector<int>();

            for (int i = 0; i < qLength; ++i)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node != nullptr)
                {
                    values.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (values.empty() == false)
                result.push_back(values);
        }
        return result;
    }
};