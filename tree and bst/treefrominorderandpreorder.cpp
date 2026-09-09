#include <bits/stdc++.h>
using namespace std;

// ==================== Tree Node ====================

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    unordered_map<int, int> hash;
    int idx = 0;

    TreeNode *solve(vector<int> preorder, int i, int j){
        if(i>j) return nullptr;
        if(idx >= preorder.size()) return nullptr;
        int root_val = preorder[idx++];

        TreeNode* root = new TreeNode(root_val);
        root->left = solve(preorder, i, hash[root_val]-1);
        root->right = solve(preorder, hash[root_val]+1, j);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for(int i=0; i<inorder.size(); i++){
            hash[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size()-1);
    }
};

// print treee
void printLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();

        while (size--)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr)
            {
                cout << "null ";
                continue;
            }
            cout << node->val << " ";

            q.push(node->left);
            q.push(node->right);
        }
        cout << "\n";
    }
}

int main()
{

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;

    TreeNode *root = solution.buildTree(preorder, inorder);

    printLevelOrder(root);

    return 0;
}