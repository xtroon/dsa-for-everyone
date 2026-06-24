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

bool isLeaf(Node* root){
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

void leftNodes(Node* root, vector<int> &ans){
    Node* curr = root->left;

    while(curr){
        // if not leaf then push to array 
        if(!isLeaf(curr)) ans.push_back(curr->data);

        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void leafNodes(Node* root, vector<int> &ans){
    if(root == NULL) return;

    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}


void rightNodes(Node* root, vector<int> &ans){
    Node* curr = root->right;
    vector<int> temp;
    while(curr){

        if(!isLeaf(curr)) temp.push_back(curr->data);

        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i = temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }

}


void boundaryTraversal(Node* root){
     if(root == NULL) return;

    vector<int> ans;
    
    if(!isLeaf(root)) ans.push_back(root->data); 

    leftNodes(root, ans);
    leafNodes(root, ans);
    rightNodes(root, ans);

    for(int x : ans) cout << x << " ";
}

int main() {
    vector<int> arr = {
    1,
    2,
    4,-1,-1,
    5,-1,-1,
    3,
    6,-1,-1,
    7,-1,-1
};

    Node* root = buildTree(arr);

    cout << "Boundary Traversal: " << endl;
    boundaryTraversal(root);

    return 0;
}