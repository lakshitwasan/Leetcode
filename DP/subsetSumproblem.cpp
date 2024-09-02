#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> dp;

bool subsetSum(int n, vector<int> &arr, int sum)
{
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

int main()
{

    vector<int> arr = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = arr.size();

    dp = vector<vector<bool>>(n + 1, vector<bool>(sum + 1));

    cout << "Subset is " << (subsetSum(n, arr, sum) ? "present" : "not present") << endl;

    return 0;
}