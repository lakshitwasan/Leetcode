#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child = nullptr;
    }

    Node(int data1, Node *next1, Node *child1)
    {
        data = data1;
        next = next1;
        child = child1;
    }
};

Node *arr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->child = temp;
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
        temp = temp->child;
    }
    cout << endl;
}

Node *flattenLL(Node *head)
{
    // TIME COMPLEXITY : O(MxNLOG(MxN))[M x N: WHILE ON TEMP, M x NLOG (M x N): SORTING, M x N : CONVERTING ARRAY TO LL] & SPACE COMPLEXITY : O(2N) [ARRAY AND ONE SORTED LL]

    Node *temp = head;
    vector<int> arr;

    while (temp)
    {
        Node *temp2 = temp;
        while (temp2)
        {
            arr.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    head = arr2LL(arr);

    return head;
}

Node *merge2lists(Node *t1, Node *t2)
{

    // TIME COPMEPLEXITY: O(N1 + N2) [LENGTH OF BOTH LISTS]

    Node *dummyNode = new Node(-1);
    Node *nextNode = dummyNode;

    while (t1 && t2)
    {
        if (t1->data < t2->data)
        {
            nextNode->child = t1;
            nextNode = nextNode->child;
            t1 = t1->child;
        }
        else
        {
            nextNode->child = t2;
            nextNode = nextNode->child;
            t2 = t2->child;
        }

        nextNode->next = NULL;
    }

    if (t1)
    {
        nextNode->child = t1;
    }
    else
    {
        nextNode->child = t2;
    }

    if (dummyNode->child)
    {
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

Node *flattenLL_recursion(Node *head)
{

    // NOT WORKING COMPLETELY

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mergeHead = flattenLL_recursion(head->next);

    head = merge2lists(head, mergeHead);

    return head;
}

int main()
{

    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    head = flattenLL(head);
    // head = flattenLL_recursion(head);

    print(head);

    return 0;
}