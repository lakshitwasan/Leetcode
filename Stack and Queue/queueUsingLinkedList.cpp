#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

class Queue
{
public:
    int size;
    Node *front, *rear;

    Queue()
    {
        size = 0;
        front = NULL;
        rear = NULL;
    }

    void Enqueue(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }

        cout << "Element " << x << " inserted in the Queue" << endl;
        size++;
    }

    int Dequeue()
    {
        if (front == NULL)
        {
            cout << "The Queue is empty" << endl;
            return -1;
        }
        else
        {
            int x = front->data;
            Node *temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
            size--;
            return x;
        }
    }

    int Peek()
    {
        if (front == NULL)
        {
            cout << "The Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int Size()
    {
        return size;
    }

    bool Empty()
    {
        return front == NULL;
    }
};

int main()
{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    cout << "Element deleted from Queue: " << Q.Dequeue() << endl;
    cout << "The size of the Queue is " << Q.Size() << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}