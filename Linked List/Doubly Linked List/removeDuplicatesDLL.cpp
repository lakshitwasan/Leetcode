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
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "X" << endl;
}

// Node *removeDuplicates(Node *head)
// {
//     Node *temp = head;
//     Node *fast = temp->next;

//     while (temp && temp->next)
//     {
//         if (fast && temp->data == fast->data)
//         {
//             fast = fast->next;
//         }
//         else
//         {
//             temp->next = fast;
//             if (fast)
//             {
//                 fast->back = temp;
//                 temp = temp->next;
//                 fast = fast->next;
//             }
//         }
//     }

//     return head;
// }

Node *removeDuplicates(Node *head)
{
    Node *temp = head;

    while (temp && temp->next)
    {
        Node *fast = temp->next;

        while (fast && temp->data == fast->data)
        {
            Node *dummy = fast;
            fast = fast->next;
            delete dummy;
        }

        temp->next = fast;
        if (fast)
        {
            fast->back = temp;
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 4};

    Node *head = arr2DLL(arr);

    print(head);

    head = removeDuplicates(head);

    print(head);

    return 0;
}