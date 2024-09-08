#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> dp;

bool subsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();

    dp = vector<vector<bool>>(n + 1, vector<bool>(sum + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
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
        for (int j = 1; j < sum + 1; j++)
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

    return dp[n][sum];
}

int minSubsetSumDifference(vector<int> &arr)
{
    int n = arr.size();
    vector<int> v;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    subsetSum(arr, sum);

    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i])
        {
            v.push_back(i);
        }
    }

    int minNum = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        minNum = min(minNum, sum - 2 * v[i]);
    }

    return minNum;
}

int main()
{

    vector<int> arr = {1, 6, 11, 5};

    int result = minSubsetSumDifference(arr);

    cout << "The minimum difference between subset sums is: " << result << endl;

    return 0;
}