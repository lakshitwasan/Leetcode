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

int maxDepth_recursion(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = maxDepth_recursion(root->left);
    int rh = maxDepth_recursion(root->right);

    return 1 + max(lh, rh);
}

int maxDepth_queue(Node *root)
{
    // TIME COMPLEXITY : O(N) & SPACE COMPLEXITY: O(N) [WORST CASE LAST LEVEL CAN HAVE N/2 NODES IF IT IS A PERFECT BINARY TREE]

    if (root == NULL)
    {
        return 0;
    }
    int level = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        level++;
    }
    return level;
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

    int result = maxDepth_recursion(root);
    // int result = maxDepth_queue(root);

    cout << "Max Depth: " << result;

    return 0;
}