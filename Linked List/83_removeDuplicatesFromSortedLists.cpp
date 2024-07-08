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

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    Node *slow = temp;
    Node *fast = temp;

    while (fast)
    {
        if (slow->data == fast->data)
        {
            fast = fast->next;
        }
        else
        {
            slow->next = fast;
            slow = slow->next;
            fast = fast->next;
        }
    }
    slow->next = fast;

    return head;
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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3};
    Node *head = arr2LL(arr);
    print(head);

    head = removeDuplicates(head);

    print(head);

    return 0;
}