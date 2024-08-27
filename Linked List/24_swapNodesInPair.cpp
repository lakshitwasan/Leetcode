#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

Node *swapPairs_variable(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *dummy = new Node(-1, head);
    Node *temp = dummy;

    while (temp->next->next && temp->next)
    {

        Node *back = temp->next;
        Node *front = back->next;

        back->next = front->next;
        front->next = back;
        temp->next = front;

        temp = back;
    }

    return dummy->next;
}

Node *swapPairs_variable(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *dummy = new Node(-1, head);
    Node *temp = dummy;

    Node *back = temp->next;
    Node *front = back->next;

    back->next = front->next;
    front->next = back;
    temp->next = front;

    temp = back;

    return dummy->next;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    head = swapPairs_variable(head);

    print(head);
    return 0;
}