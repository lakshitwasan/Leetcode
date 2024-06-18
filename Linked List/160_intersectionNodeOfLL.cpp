#include <iostream>
#include <vector>
#include <unordered_map>
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

Node *insertNode(Node *&head, int data)
{

    if (head == NULL)
    {
        head = new Node(data);
        return head;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);

    return head;
}

Node *intersectionNodeIterate(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    while (head2)
    {
        Node *temp = head1;
        while (temp)
        {
            if (temp == head2)
            {
                return head2;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }

    return NULL;
}

Node *intersectionNodeHash(Node *head1, Node *head2)
{

    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    Node *temp = head1;
    unordered_map<Node *, int> hash;
    while (temp)
    {
        hash[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while (temp)
    {
        if (hash[temp] == 1)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int getDifference(Node *head1, Node *head2)
{
    int len1 = 0;
    int len2 = 0;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1)
        {
            ++len1;
            head1 = head1->next;
        }
        if (head2)
        {
            ++len2;
            head2 = head2->next;
        }
    }

    return len1 - len2;
}

Node *intersectionNodeDiffLengthIterate(Node *head1, Node *head2)
{
    int diff = getDifference(head1, head2);

    if (diff < 0)
    {
        while (diff != 0)
        {
            diff++;
            head2 = head2->next;
        }
    }
    else
    {
        while (diff != 0)
        {
            diff--;
            head1 = head1->next;
        }
    }
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 || temp2)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

Node *intersectionNodeIterateBest(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
        {
            return temp1;
        }

        if (temp1 == NULL)
        {
            temp1 = head2;
        }
        if (temp2 == NULL)
        {
            temp2 = head1;
        }
    }

    // SHORTER WAY OF THE ABOVE APPROACH

    // while (temp1 != temp2)
    // {
    //     temp1 = (temp1 == NULL) ? head2 : temp1->next;
    //     temp2 = (temp2 == NULL) ? head1 : temp2->next;
    // }
    return temp1;
}

int main()
{
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    Node *head1 = head;
    head = head->next->next->next;
    Node *headSec = NULL;
    insertNode(headSec, 3);
    Node *head2 = headSec;
    headSec->next = head;

    // Node *ans = intersectionNodeIterate(head1, head2);
    // Node *ans = intersectionNodeHash(head1, head2);
    // Node *ans = intersectionNodeDiffLengthIterate(head1, head2);
    Node *ans = intersectionNodeIterateBest(head1, head2);
    if (ans == NULL)
    {
        cout << "No intersection" << endl;
    }
    else
    {
        cout << "Intersection Node is " << ans->data << endl;
    }

    return 0;
}