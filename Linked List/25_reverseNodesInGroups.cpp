#include <iostream>
#include <vector>
#include <stack>
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

Node *reverseLL(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

Node *getKthNode(Node *temp, int k)
{
    k -= 1;

    while (temp && k > 0)
    {
        k--;
        temp = temp->next;
    }

    return temp;
}

Node *reverseNodesInGroup(Node *head, int k)
{
    Node *temp = head;

    Node *prevLast = NULL;

    while (temp)
    {
        Node *kthNode = getKthNode(temp, k);

        if (kthNode == NULL)
        {
            if (prevLast)
            {
                prevLast->next = temp;
            }
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = NULL;

        reverseLL(temp);

        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevLast->next = kthNode;
        }

        prevLast = temp;

        temp = nextNode;
    }
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    head = reverseNodesInGroup(head, 2);

    print(head);

    return 0;
}