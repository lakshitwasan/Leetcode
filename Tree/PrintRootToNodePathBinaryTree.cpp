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

bool rootToNodeHelper(Node *root, int target, vector<int> &arr)
{
    if (root == NULL)
    {
        return false;
    }

    arr.push_back(root->data);

    if (root->data == target)
    {
        return true;
    }

    if (rootToNodeHelper(root->left, target, arr) || rootToNodeHelper(root->right, target, arr))
    {
        return true;
    }

    arr.pop_back();
    return false;
}

vector<int> rootToNode(Node *root, int target)
{

    // TIME COMPLEXITY: O (N) & SPACE COMPLEXITY: O(N)

    vector<int> ans;

    if (!root)
    {
        return ans;
    }

    rootToNodeHelper(root, target, ans);

    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    int target1 = 6;
    vector<int> path1 = rootToNode(root, target1);

    cout << "Path from root to " << target1 << ": ";
    for (int val : path1)
    {
        cout << val << " ";
    }
    cout << endl;

    int target2 = 3;
    vector<int> path2 = rootToNode(root, target2);

    cout << "Path from root to " << target2 << ": ";
    for (int val : path2)
    {
        cout << val << " ";
    }
    cout << endl;

    int target3 = 7; // does not exist
    vector<int> path3 = rootToNode(root, target3);

    cout << "Path from root to " << target3 << ": ";
    if (path3.empty())
    {
        cout << "No path found!";
    }
    else
    {
        for (int val : path3)
        {
            cout << val << " ";
        }
    }
    cout << endl;

    return 0;
}
