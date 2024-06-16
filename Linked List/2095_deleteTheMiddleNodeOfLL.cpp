#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
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

Node *deleteMiddleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *temp = nullptr;

    while (fast && fast->next)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = temp->next->next;
    slow->next = nullptr;
    delete slow;
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Node *head = arr2LL(arr);

    print(head);

    head = deleteMiddleNode(head);

    print(head);

    return 0;
}