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

bool SymmetricTreeHelper(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    return ((root1->data == root2->data) && SymmetricTreeHelper(root1->left, root2->right) && SymmetricTreeHelper(root1->right, root2->left));
}

bool SymmetricTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    return SymmetricTreeHelper(root->left, root->right);
}

int main()
{
    // Symmetric Tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    cout << "Tree 1 is Symmetric? " << (SymmetricTree(root1) ? "Yes" : "No") << endl;

    // Non-Symmetric Tree
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(2);
    root2->left->right = new Node(3);
    root2->right->right = new Node(3);

    cout << "Tree 2 is Symmetric? " << (SymmetricTree(root2) ? "Yes" : "No") << endl;

    return 0;
}