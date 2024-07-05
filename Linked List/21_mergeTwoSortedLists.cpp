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

Node *mergeTwoSortedLists(Node *list1, Node *list2)
{

    // TIME COMPLEXITY: O(N + M) & SPACE COMPLEXITY: O(1)

    if (list1 == nullptr)
    {
        return list2;
    }
    if (list2 == nullptr)
    {
        return list1;
    }

    Node *dummy = new Node(-1);
    Node *temp = dummy;
    Node *t1 = list1;
    Node *t2 = list2;

    while (t1 && t2)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }

    if (t1)
    {
        temp->next = t1;
    }
    else
    {
        temp->next = t2;
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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {1, 2, 4};

    Node *head1 = arr2LL(arr1);

    print(head1);

    vector<int> arr2 = {1, 3, 4};

    Node *head2 = arr2LL(arr2);

    print(head2);

    Node *head3 = mergeTwoSortedLists(head1, head2);

    print(head3);

    return 0;
}