#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

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

Node *twoLLSum(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummy = new Node();
    Node *curr = dummy;
    int carry = 0;

    while (temp1 || temp2)
    {
        int sum = carry;
        if (temp1)
        {
            sum = sum + temp1->data;
        }
        if (temp2)
        {
            sum = sum + temp2->data;
        }

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;

        if (temp1)
        {
            temp1 = temp1->next;
        }
        if (temp2)
        {
            temp2 = temp2->next;
        }
    }

    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummy->next;
}

int main()
{

    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    Node *head1 = arr2LL(arr1);
    Node *head2 = arr2LL(arr2);

    print(head1);
    print(head2);

    Node *finalHead = twoLLSum(head1, head2);

    print(finalHead);

    return 0;
}