#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) return NULL;
    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);   // left part
    root->right = buildTree(preorder);  // right part

    return root;
}

int height(Node* root) {
    if (root == NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH) + 1;
}

int main() {
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(arr);
    cout << "HEight is: " << height(root) << endl;

    return 0;
}