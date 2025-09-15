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

void changeTree(Node *root)
{
    if (!root)
    {
        return;
    }
    int childSum = 0;
    if (root->left)
    {
        childSum += root->left->data;
    }
    if (root->right)
    {
        childSum += root->right->data;
    }

    if (childSum > root->data)
    {
        root->data = childSum;
    }
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
    {
        total += root->left->data;
    }
    if (root->right)
    {
        total += root->right->data;
    }

    if (root->left || root->right)
    {
        root->data = total;
    }
}

void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    cout << "Inorder before change: ";
    inorderTraversal(root);
    cout << endl;

    changeTree(root);

    cout << "Inorder after change: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
