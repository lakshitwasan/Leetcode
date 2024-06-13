#include <iostream>
#include <vector>
#include <unordered_map>
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

bool detectLoop(Node *head)
{
    Node *temp = head;

    unordered_map<Node *, int> hash;

    while (temp)
    {
        if (hash.find(temp) != hash.end())
        {
            return true;
        }

        hash[temp] = 1;
        temp = temp->next;
    }

    return false;
}

bool detectLoop2(Node *head)
{
    // THIS IS USING TORTOISE AND HARE ALGORITHM

    Node *temp = head;

    Node *slow = temp;
    Node *fast = temp;

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = fourth;

    bool ans = detectLoop(head);
    if (ans)
    {
        cout << "The Linked list has a cycle" << endl;
    }
    else
    {
        cout << "The Linked List does not have a cycle" << endl;
    }

    bool ans2 = detectLoop(head);
    if (ans2)
    {
        cout << "The Linked list has a cycle" << endl;
    }
    else
    {
        cout << "The Linked List does not have a cycle" << endl;
    }

    return 0;
}