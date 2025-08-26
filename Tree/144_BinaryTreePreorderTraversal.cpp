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

    Node(int val, Node *l, Node *r)
    {
        data = val;
        left = l;
        right = r;
    }
};

void preOrder(Node *root, vector<int> &arr)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (root == NULL)
    {
        return;
    }
    arr.push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

vector<int> preOrder_stack(Node *root)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N) [STACK IS USED AND VECTOR IS INITIATED TO STORE THE ANSWER]

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = s.top();
            s.pop();
            if (node->right != nullptr)
            {
                s.push(node->right);
            }
            if (node->left != nullptr)
            {
                s.push(node->left);
            }
            ans.push_back(node->data);
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(1);
    root->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);

    vector<int> result;
    // preOrder(root, result);
    result = preOrder_stack(root);

    cout << "Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}