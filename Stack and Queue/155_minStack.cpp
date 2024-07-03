#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class MinStack
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
        st.top();
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{

    return 0;
}