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

    Node(int val, Node *l, Node *r)
    {
        data = val;
        left = l;
        right = r;
    }
};

Node *prevNode = NULL;

void flatten_BF(Node *node)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (!node)
    {
        return;
    }
    flatten_BF(node->right);
    flatten_BF(node->left);
    node->right = prevNode;
    node->left = NULL;
    prevNode = node;
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

    return 0;
}