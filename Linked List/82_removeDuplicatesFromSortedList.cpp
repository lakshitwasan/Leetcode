#include <bits/stdc++.h>
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

Node *RemoveDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *dummy = new Node(0, head);
    Node *prev = dummy;

    while (head)
    {
        if (head->next && head->data == head->next->data)
        {
            while (head->next && head->data == head->next->data)
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }

        head = head->next;
    }

    return dummy->next;
}

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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4};

    Node *head = arr2LL(arr);

    print(head);

    head = RemoveDuplicates(head);

    print(head);

    return 0;
}