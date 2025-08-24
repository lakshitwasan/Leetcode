#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    Node(int val, Node* l, Node* r)
    {
        data = val;
        left = l;
        right = r;
    }
};

void preOrder(Node* root, vector<int>& arr)
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


int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);
    root->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);

    vector<int> result;
    preOrder(root, result);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}