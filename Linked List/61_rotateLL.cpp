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

Node *rotateLLbyK_bruteForce(Node *head, int k)
{
    // TIME COMPLEXITY : O(N X K) & SPACE COMPLEXITY : O(1)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }

        Node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }

    return head;
}

// Node *rotateLLByK(Node *head, int k)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     Node *temp = head;

//     while (temp->next)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
//     Node *lastNode = NULL;

//     while (k != 0)
//     {
//         lastNode = head;
//         head = head->next;
//         k--;
//     }

//     lastNode->next = nullptr;

//     return head;
// }

Node *rotateLLByK(Node *head, int k)
{
    // TIME COMPLEXITY : O(N) WHERE N IS THE LENGTH OF THE LL & SPACE COMPLEXITY : O(1)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int len = 1;

    while (temp->next)
    {
        temp = temp->next;
        ++len;
    }

    temp->next = head;
    k = k % len;

    int end = len - k;

    while (end--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    head = rotateLLByK(head, 2);

    print(head);

    head = rotateLLbyK_bruteForce(head, 2);

    print(head);

    return 0;
}