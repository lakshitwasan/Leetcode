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

vector<int> LeftView_BF(Node *root)
{
    vector<int> ans;

    vector<vector<int>> levelTraversal = LevelOrder(root);

    for (auto x : levelTraversal)
    {
        ans.push_back(x.front());
    }
    return ans;
}

vector<int> RightView_BF(Node *root)
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


void RecursionLeft(Node *node, int level, vector<int> &ans)
{
    if (node == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->data);
    }
    if (node->left)
    {
        RecursionLeft(node->left, level + 1, ans);
    }
    if (node->right)
    {
        RecursionLeft(node->right, level + 1, ans);
    }
}

vector<int> LeftViewRecursion(Node *root)
{
    vector<int> ans;
    RecursionLeft(root, 0, ans);
    return ans;
}


void RecursionRight(Node *node, int level, vector<int> &ans)
{
    if (node == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->data);
    }
    if (node->right)
    {
        RecursionRight(node->right, level + 1, ans);
    }
    if (node->left)
    {
        RecursionRight(node->left, level + 1, ans);
    }
}

vector<int> RightViewRecursion(Node *root)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(H) [IN WORST CASE O(N) AS WELL]

    vector<int> ans;
    RecursionRight(root, 0, ans);
    return ans;
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->right = new Node(8);

    // BFS approach
    vector<int> leftViewBF = LeftView_BF(root);
    vector<int> rightViewBF = RightView_BF(root);

    cout << "BFS Left View: ";
    for (int val : leftViewBF) cout << val << " ";
    cout << endl;

    cout << "BFS Right View: ";
    for (int val : rightViewBF) cout << val << " ";
    cout << endl;

    // DFS approach
    vector<int> leftViewDFS = LeftViewRecursion(root);
    vector<int> rightViewDFS = RightViewRecursion(root);

    cout << "DFS Left View: ";
    for (int val : leftViewDFS) cout << val << " ";
    cout << endl;

    cout << "DFS Right View: ";
    for (int val : rightViewDFS) cout << val << " ";
    cout << endl;

    return 0;
}