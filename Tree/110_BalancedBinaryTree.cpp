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
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    int level = 0;
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

bool is_tree_balanced_recursion(Node *root)
{
    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(1)

    if (root == NULL)
    {
        return true;
    }
    int lh = maxDepth_recursion(root->left);
    int rh = maxDepth_recursion(root->right);

    if (abs(lh - rh) <= 1 && is_tree_balanced_recursion(root->left) && is_tree_balanced_recursion(root->right))
    {
        return true;
    }

    return false;
}

bool is_tree_balanced_queue(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = maxDepth_queue(root->left);
    int rh = maxDepth_queue(root->right);

    if (abs(lh - rh) <= 1 && is_tree_balanced_queue(root->left) && is_tree_balanced_queue(root->right))
    {
        return true;
    }
    return false;
}

int is_tree_balanced_recursion_optimal(Node *root)
{
    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O(1)

    if (root == NULL)
    {
        return 0;
    }
    int lh = is_tree_balanced_recursion_optimal(root->left);
    if (lh == -1)
    {
        return -1;
    }

    int rh = is_tree_balanced_recursion_optimal(root->right);
    if (rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    return 1 + max(lh, rh);
}

int main()
{
    // ---------- Example 1: Balanced Tree ----------
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    cout << "Tree 1 (Perfect Binary Tree):" << endl;
    cout << "Max Depth (recursion): " << maxDepth_recursion(root1) << endl;
    cout << "Max Depth (queue): " << maxDepth_queue(root1) << endl;
    cout << "Balanced (recursion O(N^2)): " << (is_tree_balanced_recursion(root1) ? "Yes" : "No") << endl;
    cout << "Balanced (queue O(N^2)): " << (is_tree_balanced_queue(root1) ? "Yes" : "No") << endl;
    cout << "Balanced (recursion optimal O(N)): " << (is_tree_balanced_recursion_optimal(root1) != -1 ? "Yes" : "No") << endl;
    cout << "--------------------------------------------\n";

    // ---------- Example 2: Unbalanced Tree ----------
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    root2->left->left->left = new Node(4);

    cout << "Tree 2 (Left Skewed):" << endl;
    cout << "Max Depth (recursion): " << maxDepth_recursion(root2) << endl;
    cout << "Max Depth (queue): " << maxDepth_queue(root2) << endl;
    cout << "Balanced (recursion O(N^2)): " << (is_tree_balanced_recursion(root2) ? "Yes" : "No") << endl;
    cout << "Balanced (queue O(N^2)): " << (is_tree_balanced_queue(root2) ? "Yes" : "No") << endl;
    cout << "Balanced (recursion optimal O(N)): " << (is_tree_balanced_recursion_optimal(root2) != -1 ? "Yes" : "No") << endl;
    cout << "--------------------------------------------\n";

    return 0;
}
