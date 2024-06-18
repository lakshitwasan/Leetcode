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

// Node *adding1ToRepresentingLLNumber(Node *head)
// {
//     Node *temp = head;
//     int num = 0;

//     while (temp->next)
//     {
//         num = (num * 10) + temp->data;
//         temp = temp->next;
//     }
//     Node *newNode = new Node(num + 1);
//     temp->next = newNode;
//     return newNode;
// }

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

Node *adding1ToRepresentingLLNumber_Reversing(Node *head)
{

    //  TIME COMPELEXITY: O(3N) & SPACE COMPLEXITY: 0(1)

    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;

    while (temp)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if (carry == 1)
    {
        Node *newNode = new Node(carry);
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }

    head = reverseLL(head);
    return head;
}

int helper(Node *temp)
{

    // TIME COMPLEXITY : O(N) * SPACE COMPLEXITY: 0(N)[INT CARRY]

    if (temp == NULL)
    {
        return 1;
    }

    int carry = helper(temp->next);

    temp->data = temp->data + carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *adding1ToRepresentingLLNumber_Recursion(Node *head)
{
    Node *temp = head;
    int carry = helper(temp);

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {9, 9, 9, 9};

    Node *head = arr2LL(arr);

    print(head);

    // head = adding1ToRepresentingLLNumber_Reversing(head);
    head = adding1ToRepresentingLLNumber_Recursion(head);

    print(head);

    return 0;
}