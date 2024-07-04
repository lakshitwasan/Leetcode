#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterNumber(vector<int> arr)
{

    // TIME COMPLEXITY: O(N) & SPACE COMPLEXITY: O(N)

    // CIRCULAR ARRAY MANDATORY

    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = (2 * n - 1); i >= 0; i--)
    {
        while (!st.empty() && arr[i % n] >= st.top())
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
            {
                nge[i] = st.top();
            }
        }

        st.push(arr[i % n]);
    }

    return nge;
}

int main()
{
    vector<int> v{5, 7, 1, 7, 6, 0};
    vector<int> res = nextGreaterNumber(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}