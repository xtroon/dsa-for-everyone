#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;
    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder); //left part
    root->right = buildTree(preorder); //right part

    return root;
}


// Iterative Preorder Traversal of Binary Tree
void preorderTraversal(Node* root){
    stack<Node*> st;
    st.push(root);

    while( !st.empty()){
        Node* temp = st.top();

        st.pop();

        cout << temp->data << " ";

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}


// Iterative Inorder Traversal of Binary Tree
void inorderTraversal(Node* root){

    stack<Node*> st;
    Node* temp = root;

    while( temp || !st.empty()){
        while(temp){
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();

        cout << temp->data << " ";

        temp = temp->right;
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


    return 0;
}