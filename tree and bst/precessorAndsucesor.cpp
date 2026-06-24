// problem link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

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

Node *floor(Node *root, int key)
{
    Node *temp = nullptr;
    while (root)
    {
        if (root->data < key)
        {
            temp = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return temp;
}

Node *ceil(Node *root, int key)
{
    Node *temp = nullptr;
    while (root)
    {
        if (root->data > key)
        {
            temp = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return temp;
}

vector<Node *> findPreSuc(Node *root, int key)
{
    Node *pre = floor(root, key);
    Node *suc = ceil(root, key);
    return {pre, suc};
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(1);
    root->right = new Node(9);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(10);

    vector<Node*> ans = findPreSuc(root, 8);
    cout << ans[0]->data << " " << ans[1]->data;
    return 0;
}