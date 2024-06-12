#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
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

Node *MiddleNodeCount(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    temp = head;

    count = count / 2 + 1;

    while (temp)
    {
        count = count - 1;

        if (count == 0)
        {
            break;
        }

        temp = temp->next;
    }

    return temp;
}

Node *middleNode(Node *head)
{

    // TORTOISE AND HARE ALGORITHM

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{

    vector<int> arr = {1, 2, 1, 2, 5, 4, 2, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    Node *node = MiddleNodeCount(head);

    cout << node->data << endl;

    Node *node2 = middleNode(head);

    cout << node->data << endl;

    return 0;
}