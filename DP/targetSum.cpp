// LITERALLY THE SAME AS COUNT THE NUMBER OF SUBSET WITH GIVEN DIFFERENCE ONLY THE WORDING HAS CHANGED OF THE PROBLEM STATEMENT (EXPLAINED IN THE NOTEBOOK)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int countSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    dp = vector<vector<int>>(n + 1, vector<int>(sum + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }

            if (j == 0)
            {
                dp[i][j] = 1;
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
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int countTheSubsetWithDifference(vector<int> &arr, int diff)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int s1 = (diff + sum) / 2;

    return countSubsetSum(arr, s1);
}

int main()
{

    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;

    cout << "Number of subsets with the given difference: " << countTheSubsetWithDifference(arr, diff) << endl;

    return 0;
}