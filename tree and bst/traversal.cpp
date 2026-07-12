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

// PreOrder Traversal
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// InOrder Traversal
void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// PostOrder Traversal
void postorderTraversal(Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Level Order Traversal ( Iterative)
void levelOrder(Node* root) {
    queue<Node*> q;

    q.push(root);

    while (q.size() > 0) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
}

// Level Order Traversal LineWise ( Iterative)
void levelOrderLineWise(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 0) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << temp->data << " ";

        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
}

int main() {
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(arr);

    cout << "Pre Order" << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "In Order" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Post Order" << endl;
    postorderTraversal(root);
    cout << endl;

    cout << "Level Order" << endl;
    levelOrder(root);
    cout << endl;

    cout << "Line Wise Level Order" << endl;
    levelOrderLineWise(root);
    cout << endl;

    return 0;
}