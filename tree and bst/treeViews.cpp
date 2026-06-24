#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;
    Node *root = new Node(preorder[idx]);

    root->left = buildTree(preorder);  // left part
    root->right = buildTree(preorder); // right part

    return root;
}

//top view of binary tree
void topView(Node *root)
{
    map<int, int> store; //{col, value}

    queue< pair< Node*, int>> q; //{node, column}
    q.push({root, 0});

    while( !q.empty() ){
        auto it = q.front();
        q.pop();

        Node* temp = it.first;
        int col = it.second;

        if(store.find(col) == store.end()){
            store[col] = temp->data;
        }

        if(temp->left) q.push({temp->left, col-1});
        if(temp->right) q.push({temp->right, col+1});
    }

    for(auto it : store){
        cout << it.second << " ";
    }

}

//bottom view of binary tree
void bottomView(Node *root)
{
    map<int, int> store; //{col, value}

    queue< pair< Node*, int>> q; //{node, column}
    q.push({root, 0});

    while( !q.empty() ){
        auto it = q.front();
        q.pop();

        Node* temp = it.first;
        int col = it.second;

            store[col] = temp->data;

        if(temp->left) q.push({temp->left, col-1});
        if(temp->right) q.push({temp->right, col+1});
    }

    for(auto it : store){
        cout << it.second << " ";
    }
}

//left view of binary tree


int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(arr);

    cout << "Top view is:" << endl;
    topView(root);

    cout << endl;

    cout << "Bottom view is:" << endl;
    bottomView(root);

    return 0;
}