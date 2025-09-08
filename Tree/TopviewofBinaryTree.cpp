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

vector<int> TopView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<int, Node *>> que;
    que.push({0, root});
    while (!que.empty())
    {
        auto p = que.front();
        que.pop();
        Node *temp = p.second;
        int x = p.first;

        if (mp.find(x) == mp.end())
        {
            mp[x] = temp->data;
        }

        if (temp->left)
        {
            que.push({x - 1, temp->left});
        }
        if (temp->right)
        {
            que.push({x + 1, temp->right});
        }
    }

    for (auto item : mp)
    {
        ans.push_back(item.second);
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

    vector<int> result = TopView(root);

    cout << "Top View: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}