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

tuple<vector<int>, vector<int>, vector<int>> PreInPostOrder(Node *root)
{
    // TIME COMPLEXITY: O(3N) & SPACE COMPLEXITY: O(4N)

    vector<int> pre, in, post;
    if (root == NULL)
    {
        return {};
    }
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first -> data);
        }
    }

    return {pre, in, post};
}

int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // get all three traversals
    vector<int> pre, in, post;
    tie(pre, in, post) = PreInPostOrder(root);

    // print preorder
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << "\n";

    // print inorder
    cout << "Inorder: ";
    for (int x : in) cout << x << " ";
    cout << "\n";

    // print postorder
    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << "\n";

    return 0;
}
