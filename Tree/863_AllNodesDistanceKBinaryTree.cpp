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

void markParents(Node *root, unordered_map<Node *, Node *> &parent_track)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            parent_track[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            parent_track[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> parent_track;
    markParents(root, parent_track);

    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    int curr_level = 0;
    q.push(target);
    visited[target] = true;
    while (!q.empty())
    {
        int size = q.size();
        if (curr_level == k)
        {
            break;
        }
        curr_level++;
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();

            if (current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }

            if (current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }

            if (parent_track[current] && !visited[parent_track[current]])
            {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int>result;
    while (!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        result.push_back(temp->data);
    }
    return result;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* target = root->left; // Node with value 5
    int k = 2;

    vector<int> result = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target->data << ": ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
