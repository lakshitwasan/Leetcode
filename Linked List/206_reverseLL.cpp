#include <iostream>
#include <vector>
#include <stack>
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

Node *reverseLLStack(Node *head)
{

    // USING STACK AND TOIME COMPLEXITY IS O(2N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;

    stack<int> st;

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

Node *reverseLLPointer(Node *head)
{

    // USING POINTERS AND NODE AND THE TIME COMPLEXITY IS O(N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;

    Node *prev = NULL;

    while (temp)
    {
        Node *front = temp->next;

        temp->next = prev;

        prev = temp;

        temp = front;
    }

    return prev;
}

Node *reverseLLRecursion(Node *head)
{

    // USING RECUSRION AND THE TUIME COMPLEXITY IS O(N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseLLRecursion(head->next);

    Node *front = head->next;

    front->next = head;

    head->next = NULL;

    return newHead;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = arr2LL(arr);

    print(head);

    head = reverseLLStack(head);

    print(head);

    head = reverseLLPointer(head);

    print(head);

    head = reverseLLRecursion(head);

    print(head);

    return 0;
}