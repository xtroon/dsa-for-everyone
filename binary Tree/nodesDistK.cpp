#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root) {
        if (!root) return;

        if (root->left) parent[root->left] = root;
        inorder(root->left);

        if (root->right) parent[root->right] = root;
        inorder(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        
        inorder(root);   // build parent map

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while(!q.empty()){
            int n = q.size();

            if(k == 0) break;

            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                //left
                if(temp->left && !visited.count(temp->left)){
                    q.push(temp->left);
                    visited.insert(temp->left);
                }

                //right
                if(temp->right && !visited.count(temp->right)){
                    q.push(temp->right);
                    visited.insert(temp->right);
                }

                //parent
                if(parent.count(temp) && !visited.count(parent[temp])){
                    q.push(parent[temp]);
                    visited.insert(parent[temp]);
                }
            }
            k--;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

int main() {
    /*
            3
          /   \
         5     1
        / \   / \
       6   2 0   8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // Node 5
    int k = 2;

    Solution obj;
    vector<int> ans = obj.distanceK(root, target, k);

    cout << "Nodes at distance " << k << ": ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}