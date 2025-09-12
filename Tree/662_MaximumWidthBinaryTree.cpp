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

int maxWidth_NoNull(Node *root)
{
    int ans = 0;
    if (!root)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans = max(ans, size);
    }
    return ans;
}

int maxWidth_withNull(Node *root)
{
    //  TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (!root)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node *, long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        long long levelMin = q.front().second;
        long long first = 0, last = 0;

        for (int i = 0; i < size; i++)
        {
            long long curr_id = q.front().second - levelMin;
            Node *node = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;

            if (node->left)
            {
                q.push({node->left, 2 * curr_id + 1});
            }
            if (node->right)
            {
                q.push({node->right, 2 * curr_id + 2});
            }
        }
        ans = max(ans, (int)(last - first + 1));
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);

    cout << "Maximum width (ignoring null gaps): " << maxWidth_NoNull(root) << endl;

    cout << "Maximum width (counting null gaps, LeetCode style): " << maxWidth_withNull(root) << endl;

    return 0;
}
