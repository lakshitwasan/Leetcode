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
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

int lengthOfCycle(Node *head)
{
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
            int count = 0;
            Node *temp = slow;
            do
            {
                count++;
                temp = temp->next;
            } while (temp != slow);

            return count;
        }
    }
    return 0;
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
    fifth->next = third;

    int ans = lengthOfCycle(head);
    cout << ans;

    return 0;
}