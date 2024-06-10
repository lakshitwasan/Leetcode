#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *arr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node *node)
{
    Node *nextNode = node->next;

    while (nextNode)
    {
        if (nextNode)
        {
            node->data = nextNode->data;
        }
        if (nextNode->next == NULL)
        {
            node->next = nullptr;
        }
        node = nextNode;
        nextNode = nextNode->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    head->next = new Node(6969);

    print(head);

    deleteNode(head->next);

    print(head);

    return 0;
}