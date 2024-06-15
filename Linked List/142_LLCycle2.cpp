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
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *detectLoop(Node *head)
{
    Node *temp = head;

    unordered_map<Node *, int> hash;

    while (temp)
    {
        if (hash[temp] != 0)
        {
            return temp;
        }
        hash[temp] = 1;
        temp = temp->next;
    }

    return nullptr;
}

Node *detectLoop2(Node *head)
{
    //  USING TORTOISE AND HARE ALGORITHM

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{

    Node *head = new Node(5);
    Node *second = new Node(4);
    Node *third = new Node(3);
    Node *fourth = new Node(2);
    Node *fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;

    Node *ans = detectLoop(head);

    cout << ans->data << endl;

    Node *ans2 = detectLoop2(head);

    cout << ans2->data << endl;

    return 0;
}