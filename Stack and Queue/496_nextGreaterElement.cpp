#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr1, vector<int> arr2)
{

    // TIME COMPLEXITY : O(N + M) & SPACE COMPLEXITY: O(2N [STACK AND MAP] + M [NGE VECTOR])

    // Next greater element with two arrays and no circular array

    int n = arr2.size();
    vector<int> nge;
    stack<int> st;
    unordered_map<int, int> mp;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr2[i] >= st.top())
        {
            st.pop();
        }

        if (!st.empty())
        {
            mp[arr2[i]] = st.top();
        }
        else
        {
            mp[arr2[i]] = -1;
        }

        st.push(arr2[i]);
    }

    for (auto &el : arr1)
    {
        nge.push_back(mp[el]);
    }

    return nge;
}

int main()
{
    vector<int> arr1{5, 1, 6, 0};
    vector<int> arr2{5, 7, 1, 7, 6, 0};
    vector<int> res = nextGreaterElement(arr1, arr2);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
    return 0;
}