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

Node *BuildTreeHelper(vector<int> inOrder, int inStart, int inEnd, vector<int> postOrder, int postStart, int postEnd, map<int, int> &inMap)
{
    if (postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    Node *root = new Node(postOrder[postEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = BuildTreeHelper(inOrder, inStart, inRoot - 1, postOrder, postStart, postStart + numsLeft - 1, inMap);
    root->right = BuildTreeHelper(inOrder, inRoot + 1, inEnd, postOrder, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

Node *BuildTree(vector<int> inOrder, vector<int> postOrder)
{
    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }

    Node *root = BuildTreeHelper(inOrder, 0, inOrder.size() - 1, postOrder, 0, postOrder.size() - 1, inMap);

    return root;
}

void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(Node *root)
{
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Node *root = BuildTree(inorder, postorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}