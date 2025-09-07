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

vector<vector<int>> zigZag(Node *root)
{
    vector<vector<int>> result;

    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    bool L2F = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            int index = L2F ? i : (size - 1 - i);
            level[index] = node->data;

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }

        }
        L2F = !L2F;
        result.push_back(level);
    }

    return result;
}

int main()
{
    Node *root = new Node(11);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> res = zigZag(root);

    for (auto &level : res)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
