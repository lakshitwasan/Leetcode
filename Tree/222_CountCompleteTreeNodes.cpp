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

void inorder(Node *root, int &count)
{
    if (!root)
    {
        return;
    }

    count++;
    inorder(root->left, count);
    inorder(root->right, count);
}

int countNode_BF(Node *root)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(LOGN)

    if (!root)
    {
        return 0;
    }

    int count = 0;

    inorder(root, count);

    return count;
}

int leftHeight(Node *node)
{
    if (!node)
    {
        return 0;
    }
    int count = 0;
    while (node)
    {
        count++;
        node = node->left;
    }
    return count;
}

int rightHeight(Node *node)
{
    if (!node)
    {
        return 0;
    }
    int count = 0;
    while (node)
    {
        count++;
        node = node->right;
    }
    return count;
}

int countNode_Optimal(Node *root)
{
    // TIME COMPLEXITY: O(LOGN x LOGN) & SPACE COMPLEXITY: O(LOGN)

    if (!root)
    {
        return 0;
    }

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }

    return 1 + countNode_Optimal(root->left) + countNode_Optimal(root->right);
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Total number of nodes (Brute Force): " << countNode_BF(root) << endl;
    cout << "Total number of nodes (Optimal): " << countNode_Optimal(root) << endl;

    return 0;
}