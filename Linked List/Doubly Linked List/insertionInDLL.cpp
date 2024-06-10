#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *arr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, mover);
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

Node *insertBeforeHead(Node *head, int data)
{
    Node *newHead = new Node(data, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node *insertAfterHead(Node *head, int data)
{
    Node *temp = new Node(data, head->next, head);
    head->next = temp;
    return head;
}

Node *insertAfterTail(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data, nullptr, temp);
    temp->next = newNode;
    return head;
}

Node *insertBeforeTail(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prevNode = tail->back;

    Node *newNode = new Node(data, tail, prevNode);

    prevNode->next = newNode;
    tail->back = newNode;

    return head;
}

Node *insertAtKthLocation(Node *head, int data, int k)
{
    if (head == NULL)
    {
        return new Node(data);
    }
    if (k == 1)
    {
        return insertBeforeHead(head, data);
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return insertAfterTail(head, data);
    }

    Node *prevNode = temp->back;
    Node *newNode = new Node(data, temp, prevNode);
    prevNode->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(Node *node, int data)
{
    // ASSUMPTION: THE NODE WILL NEVER BE THE HEAD

    Node *prev = node->back;
    Node *newNode = new Node(data, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Node *head = arr2DLL(arr);

    print(head);

    head = insertBeforeHead(head, 10);

    print(head);

    head = insertAfterHead(head, 100000);

    print(head);

    head = insertAfterTail(head, 100000);

    print(head);

    head = insertBeforeTail(head, 6969);

    print(head);

    head = insertAtKthLocation(head, 6969, 11);

    print(head);

    insertBeforeNode(head->next->next, 420);

    print(head);

    return 0;
}