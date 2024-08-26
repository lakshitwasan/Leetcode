#include <bits/stdc++.h>
using namespace std;

int perfectSum(int index, int &count, vector<int> &ds, vector<int> &arr, int sum, int goal)
{
    int n = arr.size();

    if (index == n)
    {
        if (sum == goal)
        {
            count++;
        }
        return count;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    perfectSum(index + 1, count, ds, arr, sum, goal);

    ds.pop_back();
    sum -= arr[index];
    perfectSum(index + 1, count, ds, arr, sum, goal);

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int goal = 2;
    int count = 0;

    int ans = perfectSum(0, count, ds, arr, 0, goal);

    cout << ans << endl;

    return 0;
}
