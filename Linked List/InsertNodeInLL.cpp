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

Node *InsertNodeHead(int data, Node *head)
{
    Node *temp = new Node(data, head);
    return temp;
}

Node *insertNodeTail(Node *head, int data)
{
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);

    return head;
}

Node *insertNodeLocation(Node *head, int data, int k)
{
    if (head == NULL)
    {
        return new Node(data);
    }
    else if (k == 1)
    {
        Node *temp = new Node(data, head);
        return temp;
    }
    int count = 0;
    Node *temp = head;

    while (temp)
    {
        count++;

        if (count == k - 1)
        {
            Node *node = new Node(data, temp->next);
            temp->next = node;

            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *insertNodeBeforeElement(Node *head, int data, int element)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->data == element)
    {
        return new Node(data, head);
    }
    Node *temp = head;

    while (temp)
    {
        if (temp->next->data == element)
        {
            Node *node = new Node(data, temp->next);
            temp->next = node;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp->next)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    head = InsertNodeHead(1000, head);

    print(head);

    head = insertNodeTail(head, 1000);
    print(head);

    head = insertNodeLocation(head, 1000, 6);
    print(head);

    head = insertNodeBeforeElement(head, 1000, 3);
    print(head);

    return 0;
}
