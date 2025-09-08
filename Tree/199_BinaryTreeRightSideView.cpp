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

vector<int> LeftView(Node *root)
{
    vector<int> ans;

    vector<vector<int>> levelTraversal = LevelOrder(root);

    for (auto x : levelTraversal)
    {
        ans.push_back(x.front());
    }
    return ans;
}

vector<int> RightView(Node *root)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    vector<int> ans;

    vector<vector<int>> levelTraversal = LevelOrder(root);

    for (auto x : levelTraversal)
    {
        ans.push_back(x.back());
    }
    return ans;
}

vector<vector<int>> LevelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }

    return ans;
}

int main()
{

    return 0;
}