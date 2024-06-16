#include <iostream>
#include <vector>
#include <algorithm>
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

Node *sortLL(Node *head)
{

    // TIME COMPLEXITY: O(NLOGN) AS WE HAVE USED SORT ALGO =

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    vector<int> nums;

    while (temp)
    {
        nums.push_back(temp->data);
        temp = temp->next;
    }

    temp = head;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        temp->data = nums[i];
        temp = temp->next;
    }

    return head;
}

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Node *sortLLMergeSort(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     Node *temp = head;

//     Node *middle = findMiddle(head);

//     Node *leftHead = head;
//     Node *rightHead = middle->next;
//     middle->next = NULL;
// }

int main()
{

    vector<int> arr = {1222, 4534232, 566677887, 44343333, 1};

    Node *head = arr2LL(arr);

    print(head);

    head = sortLL(head);

    print(head);

    return 0;
}