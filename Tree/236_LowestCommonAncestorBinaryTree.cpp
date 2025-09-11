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

Node *LCA_optimal(Node *root, Node *p, Node *q)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N) [IF INCLUDING AUXILARRY STACK SPACE OF RECURSION]

    if (root == NULL || root == q || root == p)
    {
        return root;
    }
    Node *left = LCA_optimal(root->left, p, q);
    Node *right = LCA_optimal(root->right, p, q);

    if (!left)
    {
        return right;
    }
    else if (!right)
    {
        return left;
    }
    else
    {
        return root;
    }
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node *p = root->left;              // Node 5
    Node *q = root->left->right->right; // Node 4

    Node *ancestor = LCA_optimal(root, p, q);

    if (ancestor)
        cout << "LCA of " << p->data << " and " << q->data << " is " << ancestor->data << endl;
    else
        cout << "LCA not found." << endl;

    p = root->left;  // Node 5
    q = root->right; // Node 1

    ancestor = LCA_optimal(root, p, q);
    if (ancestor)
        cout << "LCA of " << p->data << " and " << q->data << " is " << ancestor->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
