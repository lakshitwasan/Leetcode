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

vector<pair<int, int>> pairsOfgivenSum(Node *head, int k)
{

    // TIME COMPLEXITY : O(N) & SPACE COMPLEXITY : O(N)

    // CAN BE DONE WITH O(N2) AS WELL WITH TWO POINTERS ONE ON FIRST AND SECOND ITERATING AND CHECKING THE REST OF THE LL

    Node *t1 = head;
    Node *t2 = head;
    vector<pair<int, int>> arr;

    while (t2->next)
    {
        t2 = t2->next;
    }

    while (t1->data < t2->data)
    {
        if (t1->data + t2->data == k)
        {
            arr.push_back(make_pair(t1->data, t2->data));
            t1 = t1->next;
            t2 = t2->back;
        }
        else if (t1->data + t2->data > k)
        {
            t2 = t2->back;
        }
        else if (t1->data + t2->data < k)
        {
            t1 = t1->next;
        }
    }

    return arr;
}

void printVectorPair(vector<pair<int, int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "(" << arr[i].first << "," << arr[i].second << ")" << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};

    Node *head = arr2DLL(arr);

    print(head);

    vector<pair<int, int>> arr2 = pairsOfgivenSum(head, 7);

    printVectorPair(arr2);

    return 0;
}