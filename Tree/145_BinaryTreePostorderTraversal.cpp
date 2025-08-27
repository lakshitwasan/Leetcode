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

void postorder(Node *root, vector<int> &arr)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (root == NULL)
    {
        return;
    }
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}

vector<int> postorder_2stack(Node *root)
{
    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY: O(2N)

    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left != nullptr)
        {
            st1.push(node->left);
        }
        if (node->right != nullptr)
        {
            st1.push(node->right);
        }
    }

    int size = st2.size();

    for (int i = 0; i < size; i++)
    {
        Node *node = st2.top();
        st2.pop();
        postorder.push_back(node->data);
    }

    return postorder;
}

vector<int> postorder_1stack_vector(Node *root)
{
    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY: O(2N)

    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }
    stack<Node *> st1;
    st1.push(root);

    while (!st1.empty())
    {
        Node *node = st1.top();
        st1.pop();
        postorder.push_back(node->data);
        if (node->left != nullptr)
        {
            st1.push(node->left);
        }
        if (node->right != nullptr)
        {
            st1.push(node->right);
        }
    }

    int n = postorder.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(postorder[i], postorder[n - i - 1]);
    }

    return postorder;
}

vector<int> postorder_1stack(Node *root)
{
    // TIME COMPLEXITY: O(2N) & SPACE COMPLEXITY: O(N)

    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }
    stack<Node *> st;
    Node *node = root;

    while (node != NULL || !st.empty())
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                node = temp;
            }
        }
    }

    return postorder;
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
    // postorder(root, result);
    result = postorder_1stack(root);
    // result = postorder_1stack_vector(root);
    // result = postorder_2stack(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}