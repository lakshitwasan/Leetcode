#include <bits/stdc++.h>
using namespace std;

// THIS IS SIMPLER APPROACH
class Queue1
{
    // TIME COMPLEXITY : 0(N) & SPACE COMPLEXITY: O(2N)

    stack<int> input;
    stack<int> output;

public:
    void Push(int x)
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        cout << "The element pushed is " << x << endl;
        input.push(x);

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int Pop()
    {
        if (input.empty())
        {
            cout << " Stack is empty " << endl;
            return -1;
        }

        int n = input.top();
        input.pop();
        return n;
    }

    int Top()
    {
        if (input.empty())
        {
            cout << " Stack is empty " << endl;
            return -1;
        }
        return input.top();
    }

    int Size()
    {
        return input.size();
    }

    bool Empty()
    {
        return input.empty();
    }
};

// THIS IS BETTER APPROACH
class Queue2
{
    // TIME COMPLEXITY : 0(1) (AMORTISED - THIS MEANS THAT IT CAN BE DIFFERENT [O(N) IN THIS CASE] SOMETIMES BUTU MAJORLY THE TIME COMPLEXITY WILL BE O(1) ) & SPACE COMPLEXITY: O(2N)

    stack<int> input;
    stack<int> output;

public:
    void Push(int x)
    {
        cout << "The element pushed is " << x << endl;
        input.push(x);
    }

    int Pop()
    {
        if (output.empty())
        {
            if (input.empty())
            {
                cout << " Stack is empty " << endl;
                return -1;
            }
            else
            {
                while (!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
            }
        }

        int x = output.top();
        output.pop();
        return x;
    }

    int Top()
    {
        if (output.empty())
        {
            if (input.empty())
            {
                cout << " Stack is empty " << endl;
                return -1;
            }
            else
            {
                while (!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
            }
        }

        return output.top();
    }

    int Size()
    {
        return (output.size() + input.size());
    }

    bool Empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{

    Queue2 q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.Size() << endl;

    return 0;
}