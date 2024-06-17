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

Node *sortLL_0_1_2_variables(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    while (temp)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }

    return head;
}

Node *sortLL_0_1_2_LL(Node *head)
{
    Node *temp = head;
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main()
{

    vector<int> arr = {0, 0, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 0, 0};

    Node *head = arr2LL(arr);

    print(head);

    // head = sortLL_0_1_2_variables(head);

    // print(head);

    head = sortLL_0_1_2_LL(head);

    print(head);

    return 0;
}