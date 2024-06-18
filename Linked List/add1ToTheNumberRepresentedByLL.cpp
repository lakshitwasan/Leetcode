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

Node *adding1ToRepresentingLLNumber(Node *head)
{
    Node *temp = head;
    int num = 0;

    while (temp)
    {
        num = (num * 10) + temp->data;
        temp = temp->next;
    }
    Node *newNode = new Node(num + 1);
    return newNode;
}

int main()
{
    vector<int> arr = {22, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    Node *ans = adding1ToRepresentingLLNumber(head);

    cout << ans->data;

    return 0;
}