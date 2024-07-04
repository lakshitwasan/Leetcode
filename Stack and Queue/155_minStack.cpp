#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class MinStack1
{

    // TIME COMPLEXITY : O(1) & SPACE COMPLEXITY : O(2N)

    stack<pair<int, int>> st;

public:
    void Push(int x)
    {
        int minVal;
        if (st.empty())
        {
            minVal = x;
        }
        else
        {
            minVal = min(st.top().second, x);
        }
        st.push({x, minVal});
    }

    int pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

class MinStack2
{

    // TIME COMPLEXITY: 0(1) & SPACE COMPLEXITY: O(N)

public:
    stack<long long> st;
    long long minVal;

    MinStack2()
    {
        minVal = INT32_MAX;
    }

    void Push(int x)
    {
        long long val = x;
        if (st.empty())
        {
            minVal = val;
            st.push(val);
        }
        else
        {
            if (val < minVal)
            {
                st.push((2 * val) - minVal);
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void Pop()
    {
        if (st.empty())
        {
            cout << "The stack is empty" << endl;
            return;
        }
        else
        {
            long long el = st.top();
            if (el < minVal)
            {
                minVal = (2 * minVal) - el;
            }
            st.pop();
        }
    }

    int Top()
    {
        if (st.empty())
        {
            cout << "The stack  is empty" << endl;
        }
        long long el = st.top();
        if (el < minVal)
        {
            return minVal;
        }
        return el;
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{
    MinStack2 s;

    s.Push(2);
    s.Push(5);
    s.Push(10);
    s.Push(1);
    s.Push(5);

    cout << "Min element: " << s.getMin() << endl;

    s.Pop();
    cout << "Min element after one pop: " << s.getMin() << endl;

    s.Pop();
    cout << "Min element after two pops: " << s.getMin() << endl;

    s.Pop();
    cout << "Min element after three pops: " << s.getMin() << endl;

    cout << "stack's top element: " << s.Top() << "\n";
    cout << "Min element: " << s.getMin() << endl;

    return 0;
}