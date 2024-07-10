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

Node *removeElements(Node *head, int val)
{

    // TIME COMPLEXTY: O(N) & SPACE COMPLEXITY: O(1)

    Node *temp = head;
    Node *prev = nullptr;

    if (head == nullptr || head->next == NULL)
    {
        return head;
    }

    while (temp)
    {
        if (temp->data == val)
        {
            if (prev == nullptr)
            {
                Node *prevNode = head;
                head = head->next;
                temp = head;
                delete prevNode;
            }
            else if (temp->next == NULL)
            {
                prev->next = nullptr;
                delete temp;
                break;
            }
            else
            {
                Node *prevNode = temp;
                temp = temp->next;
                prev->next = temp;
                delete prevNode;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

int main()
{

    vector<int> arr = {1, 2, 6, 3, 4, 5, 6};

    Node *head = arr2LL(arr);

    print(head);

    head = removeElements(head, 6);

    print(head);

    return 0;
}