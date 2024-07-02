#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, currSize, maxSize;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        maxSize = 16;
        arr = new int[maxSize];
        currSize = 0;
    }

    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "The queue is full" << endl;
            return;
        }

        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = x;
        cout << "The element pushed is " << x << endl;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        int popped = arr[front];
        if (currSize == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    int top()
    {
        if (front == -1)
        {
            cout << "The queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        return currSize;
    }
};

int main()
{
    Queue q(6);
    q.pop();
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "Element Delete: " << q.pop() << endl;
    cout << "Element Delete: " << q.pop() << endl;
    cout << "Element Delete: " << q.pop() << endl;
    cout << "Element Delete: " << q.pop() << endl;
    cout << "Element Delete: " << q.pop() << endl;
    cout << "The peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.size() << endl;
    cout << "The first element to be deleted: " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.size() << endl;

    return 0;
}
