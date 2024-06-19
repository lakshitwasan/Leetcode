#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *arr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, mover);
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

Node *deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *prev = temp;
    temp = temp->next;
    temp->back = NULL;
    delete temp;
    prev->next = nullptr;
    return head;
}

Node *deleteAtLocation_K(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) // k is greater than the number of nodes
    {
        return head;
    }

    Node *prevNode = temp->back;
    Node *nextNode = temp->next;
    if (prevNode == NULL && nextNode == NULL)
    {
        return NULL;
    }
    else if (prevNode == NULL)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        return deletehead(head);
    }
    else if (nextNode == NULL)
    {

        return deleteTail(head);
    }

    prevNode->next = nextNode;
    nextNode->back = prevNode;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void deleteGivenNode(Node *temp)
{
    // ASUMPTION: THE NODE WILL NEVER BE HEAD

    Node *prevNode = temp->back;
    Node *nextNode = temp->next;

    if (nextNode == NULL)
    {
        prevNode->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prevNode->next = nextNode;
    nextNode->back = prevNode;

    temp->next = temp->back = nullptr;
    delete temp;
}

int main()
{
    vector<int> arr = {1, 4, 3, 2, 5, 7, 8, 9, 1, 2, 2};

    Node *head = arr2DLL(arr);

    print(head);

    head = deletehead(head);

    print(head);

    head = deleteTail(head);

    print(head);

    head = deleteAtLocation_K(head, 40);

    print(head);

    deleteGivenNode(head->next->next->next);

    print(head);

    return 0;
}
