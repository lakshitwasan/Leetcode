#include <iostream>
#include <vector>
#include <stack>
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseDLLStack(Node *head)
{

    // USING STACK AND THE TIME COMPLEXITY IS O(2N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    stack<int> st;

    Node *temp = head;

    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node *reverseDLLPointer(Node *head)
{

    // USING NODES AND POINTERS AND THE TIME COMPLEXITY IS O(N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;

    Node *prev = NULL;

    while (temp)
    {
        prev = temp->back;
        temp->back = temp->next;
        temp->next = prev;

        temp = temp->back;
    }

    return prev->back;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2DLL(arr);

    print(head);

    // head = reverseDLLStack(head);

    // print(head);

    head = reverseDLLPointer(head);

    print(head);

    return 0;
}