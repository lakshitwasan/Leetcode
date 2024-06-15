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

Node *removeNthLastElement(Node *head, int k)
{

    // TIME COMPLEXITY : O(2N) IN WORST CASE & SPACE = O(1)

    Node *temp = head;
    int count = 0;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    if (count == k)
    {
        Node *newHead = head->next;
        delete (head);
        return newHead;
    }

    int res = count - k;

    temp = head;

    // while (temp)
    // {
    //     res--;
    //     if (res == 0)
    //     {
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // Node *front = temp->next;
    // temp->next = temp->next->next;
    // front->next = nullptr;
    // delete front;
    // return head;

    for (int i = 1; i < count - k; i++)
    {
        temp = temp->next;
    }

    Node *front = temp->next;
    temp->next = temp->next->next;
    front->next = nullptr;
    delete front;

    return head;
}

Node *removeNthLastElement2(Node *head, int k)
{

    // TIME COMPLEXITY : O(N) AND SPACE = O(1)

    // if (head == NULL || head->next == NULL)
    // {
    //     return head;
    // }

    Node *fast = head;
    Node *slow = head;

    if (fast == NULL)
    {
        return head->next;
    }

    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    // head = removeNthLastElement(head, 4);

    // print(head);

    head = removeNthLastElement2(head, 2);

    print(head);

    return 0;
}