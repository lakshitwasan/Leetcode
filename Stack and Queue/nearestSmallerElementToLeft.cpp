#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElement(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= st.top())
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(arr[i]);
    }

    return nse;
}

int main()
{

    vector<int> arr{4, 5, 2, 10, 8};
    vector<int> res = nearestSmallerElement(arr);
    cout << "The nearest smaller elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}