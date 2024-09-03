#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int countOfSubsetsWithGivenSum(vector<int> arr, int sum)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }

    dp = vector<vector<int>>(n + 1, vector<int>(sum + 1, 0));

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
                dp[i][j] = pow(2, count); // IF NO ZEROES EXIST THEN THE ANSWER SHOPULD BE 1 AS NULL POINTER WILL BE THE ONLY CASE OTHER THEN THAT IF ZEROS ARER THERE THEN IT INCREASEs TO 2 ^ NUMBER OF ZEROES
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

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int targetSum = 10;

    int countSubsets = countOfSubsetsWithGivenSum(arr, targetSum);

    cout << "Count of subsets with sum " << targetSum << " is: " << countSubsets << endl;

    return 0;
}