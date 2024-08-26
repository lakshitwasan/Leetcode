#include <bits/stdc++.h>
using namespace std;

void subsequence(int ind, vector<int> &ds, vector<int> arr)
{

    // TIME COMEPLXITY: O(2^N x N) & SPACE COMPLEXITY: O(N)

    int n = arr.size();

    if (ind == n)
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i] << " ";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[ind]);
    subsequence(ind + 1, ds, arr);
    ds.pop_back();
    subsequence(ind + 1, ds, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;

    subsequence(0, ds, arr);
    return 0;
}