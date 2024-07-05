#include <bits/stdc++.h>
using namespace std;

vector<int> astroidCollision1(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result;

    for (auto i : arr)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else if (i > 0)
        {
            st.push(i);
        }
        else if (i < 0)
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(i))
            {
                st.pop();
            }
            if (!st.empty() && st.top() > 0)
            {
                if (st.top() == abs(i))
                {
                    st.pop();
                }
            }
            else
            {
                st.push(i);
            }
        }
    }

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

vector<int> astroidCollision2(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            st.push(arr[i]);
        }
        else
        {
            while (!st.empty() && st.top() >= 0 && st.top() < abs(arr[i]))
            {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(arr[i]))
            {
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(arr[i]);
            }
        }
    }

    for (; !st.empty(); st.pop())
    {
        result.push_back(st.top());
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> arr = {-2, -1, 1, 2};
    vector<int> res = astroidCollision1(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}