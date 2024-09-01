#include <bits/stdc++.h>
using namespace std;

int perfectSum(int index, int &count, vector<int> &arr, int sum, int goal)
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

    sum += arr[index];
    perfectSum(index + 1, count, arr, sum, goal);

    sum -= arr[index];
    perfectSum(index + 1, count, arr, sum, goal);

    return count;
}

int perfectSum_count(int index, vector<int> &arr, int sum, int goal)
{
    int n = arr.size();

    if (index == n)
    {
        if (sum == goal)
        {
            return 1;
        }
        else
            return 0;
    }

    sum += arr[index];
    int l = perfectSum_count(index + 1, arr, sum, goal);

    sum -= arr[index];
    int r = perfectSum_count(index + 1, arr, sum, goal);

    return l + r;
}

bool perfectSum_bool(int index, vector<int> &ds, vector<int> &arr, int sum, int goal)
{
    // IF WE WANT ONLY ONE TRUE CASE AND PRINT THAT ONE CASE ONLY

    int n = arr.size();

    if (index == n)
    {
        if (sum == goal)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            return true;
        }
        else
            return false;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    if (perfectSum_bool(index + 1, ds, arr, sum, goal) == true)
    {
        return true;
    }

    ds.pop_back();
    sum -= arr[index];
    if (perfectSum_bool(index + 1, ds, arr, sum, goal) == true)
    {
        return true;
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int goal = 2;
    int count = 0;

    int ans = perfectSum(0, count, arr, 0, goal);

    cout << ans << endl;
    cout << (perfectSum_count(0, arr, 0, goal)) << endl;
    cout << (perfectSum_bool(0, ds, arr, 0, goal) ? "(True)" : "(False)") << endl;

    return 0;
}
