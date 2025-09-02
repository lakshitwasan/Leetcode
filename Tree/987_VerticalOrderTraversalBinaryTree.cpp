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

vector<vector<int>> verticalOrder(Node *root)
{
    map<int, map<int, multiset<int>>> node_map;
    queue<pair<Node *, pair<int, int>>> qu;

    qu.push({root, {0, 0}});

    while (!qu.empty())
    {
        auto p = qu.front();
        qu.pop();

        Node *temp = p.first;

        int x = p.second.first;
        int y = p.second.second;

        node_map[x][y].insert(temp->data);

        if (temp->left)
        {
            qu.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            qu.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : node_map)
    {
        vector<int> column;
        for (auto q : p.second)
        {
            column.insert(column.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(column);
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(11);
    root->right->left = new Node(9);
    root->right->right->left = new Node(10);

    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:" << endl;
    for (auto &col : result)
    {
        for (int val : col)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}