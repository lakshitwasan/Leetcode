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
        next = next;
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

void traverseLL(vector<int> arr, Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthofLL(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

bool searchInLL(Node *head, int val)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> arr = {144, 2222, 5553, 4444, 234234235};
    Node *head = arr2LL(arr);

    traverseLL(arr, head);

    int length = lengthofLL(head);

    cout << "Length of the Linked List is: " << length << endl;

    bool search = searchInLL(head, 222);

    cout << (search ? "True" : "False") << endl;

    return 0;
}