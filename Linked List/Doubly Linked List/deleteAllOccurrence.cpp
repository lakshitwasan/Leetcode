#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node *arr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

Node *deleteAllOccurences(Node *head, int k)
{

    // TIME COMPLEXITY : O(N) & SPACE COMEPLEXITY : O(1)

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            Node *front = temp->next;
            Node *back = temp->prev;
            if (front)
            {
                front->prev = back;
            }
            if (back)
            {
                back->next = front;
            }

            delete temp;
            temp = front;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{

    vector<int> arr = {1, 4, 3, 2, 5, 7, 8, 9, 1, 2, 2};

    Node *head = arr2DLL(arr);

    print(head);

    head = deleteAllOccurences(head, 2);

    print(head);

    return 0;
}