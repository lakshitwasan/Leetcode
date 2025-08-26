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

void inOrder(Node *root, vector<int> &arr)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

vector<int> inOrder_stack(Node *root)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N) [STACK IS USED AND VECTOR IS INITIATED TO STORE THE ANSWER]

    vector<int> inorder;
    if (root == NULL)
    {
        return inorder;
    }
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node !=NULL)
        {
            st.push(node);
            node = node ->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            node = st.top();
            st.pop();
            inorder.push_back(node -> data);
            node = node->right;
        }
    }
    return inorder;
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
    // inOrder(root, result);
    result = inOrder_stack(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}