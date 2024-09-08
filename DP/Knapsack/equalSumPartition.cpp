#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> dp;

bool subsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    dp = vector<vector<bool>>(n + 1, vector<bool>(target + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

bool equalSumPartition(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return subsetSum(arr, sum / 2);
    }
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    int n = arr.size();

    cout << "Equal sum partition is " << (equalSumPartition(arr) ? "present" : "not present") << endl;

    return 0;
}