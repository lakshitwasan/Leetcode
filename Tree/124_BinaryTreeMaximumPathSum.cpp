#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int findMaxPathSum(Node *root, int &maxSum) {
    if (root == nullptr) {
        return 0;
    }

    int leftGain = max(0, findMaxPathSum(root->left, maxSum));
    int rightGain = max(0, findMaxPathSum(root->right, maxSum));

    maxSum = max(maxSum, leftGain + rightGain + root->data);

    return root->data + max(leftGain, rightGain);
}

int maxPathSum(Node *root) {
    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    return maxSum;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    int result = maxPathSum(root);

    cout << "The maximum path sum in the binary tree is: " << result << endl;

    return 0;
}
