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

Node *oddEvenLLVector(Node *head)
{
    // TIME : O(2N AS IT IS N + (N/2 X 2) ) = O(N) & SPACE : O(N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    vector<int> arr;

    while (temp && temp->next)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
    {
        arr.push_back(temp->data);
    }

    temp = head->next;

    while (temp && temp->next)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
    {
        arr.push_back(temp->data);
    }

    int i = 0;
    temp = head;

    while (temp)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

Node *oddEvenLLPointer(Node *head)
{

    // TIME: O(N/2 X 2) = O(N) & SPACE : O(1)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *temp = head->next;

    while (even && even->next)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = temp;

    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    head = oddEvenLLVector(head);

    print(head);

    // head = oddEvenLL(head);

    // print(head);

    return 0;
}