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

bool isLeaf(Node *root)
{
    return (root != NULL && !(root->left) && !(root->right));
}

void addLeftBourndary(Node *root, vector<int> &arr)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            arr.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addLeaves(Node *root, vector<int> &arr)
{
    if (isLeaf(root))
    {
        arr.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeaves(root->left, arr);
    }
    if (root->right)
    {
        addLeaves(root->right, arr);
    }
}

void addRightBoundary(Node *root, vector<int> &arr)
{
    Node *curr = root->right;
    stack<int> st;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            st.push(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = 0; i < st.size(); i++)
    {
        arr.push_back(st.top());
        st.pop();
    }
}

vector<int> boundaryTraversal(Node *root)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeftBourndary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
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
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> result = boundaryTraversal(root);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}