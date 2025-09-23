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

string serialize(Node *root)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (!root)
    {
        return "";
    }
    string s = "";

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (!node)
        {
            s += "#,";
        }
        else
        {
            s += to_string(node->data) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }

    return s;
}

Node *deserialize(string data)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    if (data.empty())
    {
        return NULL;
    }
    stringstream s(data);
    string str;

    getline(s, str, ',');
    Node *root = new Node(stoi(str));

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        getline(s, str, ',');

        if (str != "#")
        {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');

        if (str != "#")
        {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string data = serialize(root);
    cout << "Serialized tree: " << data << endl;

    Node *newRoot = deserialize(data);

    string check = serialize(newRoot);
    cout << "Serialized after deserialization: " << check << endl;

    return 0;
}
