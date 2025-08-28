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

int diameter = 0;

int diameterOfTree_BF(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = diameterOfTree_BF(root->left);
    int rightHeight = diameterOfTree_BF(root->right);

    diameter = max(diameter, leftHeight + rightHeight); // LH + RH IS USED BECAUSE THE NUMBER OF EDGES IS ASKED
    // diameter = max(diameter, 1 + leftHeight + rightHeight); // LH + RH + 1 IS USED ONLY WHEN THE NUMBER OF NODES ARE ASKED

    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    // Calculate the diameter of the binary tree
    diameterOfTree_BF(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
