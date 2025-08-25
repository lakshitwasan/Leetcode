#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void postorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(1);
    root->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);

    vector<int> result;
    postorder(root, result);

    cout << "Postorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}