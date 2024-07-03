#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// USING SINGLE QUEUE
class Stack
{
    queue<int> q;

public:
    void Push(int x)
    {

        // TIME COMPLEXITY : O(N)

        q.push(x);
        int s = q.size();
        for (int i = 0; i < s - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int Pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }

    int Top()
    {
        return q.front();
    }

    int Size()
    {
        return q.size();
    }
};

// USING TWO QUEUES
class Stack2
{
    queue<int> q1;
    queue<int> q2;

public:
    void Push(int x)
    {

        // TIME COMPLEXITY : O(N)

        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int Pop()
    {
        int n = q1.front();
        q1.pop();
        return n;
    }

    int Top()
    {
        return q1.front();
    }

    int Size()
    {
        return q1.empty();
    }
};

int main()
{

    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();

    return 0;
}