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

bool isPalindrome(Node *head)
{
    Node *temp = head;
    vector<int> arr;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int n = arr.size();

    int i = arr[0];
    int j = arr[n - 1];

    while (i <= j)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLL(head->next);

    Node *front = head->next;

    front->next = head;

    head->next = NULL;

    return newHead;
}

bool isPalindrome2(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseLL(slow->next);

    Node *first = head;

    Node *second = newHead;

    while (second)
    {
        if (first->data != second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newHead);
    return true;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(3);
    Node *fourth = new Node(3);
    Node *fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    bool ans = isPalindrome2(head);
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}