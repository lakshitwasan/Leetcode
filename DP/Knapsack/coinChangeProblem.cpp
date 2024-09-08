#include <bits/stdc++.h>
using namespace std;

int maxCoinChange(vector<int> &coins, int S)
{
    // SAME AS COUNT THE SUBSETSUM WITH GIVEN SUM BUT FOR UNBOUNDED KNAPSACK

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(S + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
        }
    }

    return dp[n][S];
}

int minCoinChange(vector<int> &coins, int S)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(S + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1; // If sum is 0, no coin is needed
            }

            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1; // If no coins are available, no sum can be formed
            }
        }
    }

    for (int j = 1; j <= S; j++)
    {
        if (j % coins[0] == 0)
        {
            dp[1][j] = j / coins[0]; // If j is a multiple of the first coin
        }
        else
        {
            dp[1][j] = INT_MAX - 1; // Otherwise, impossible
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
        }
    }

    return dp[n][S] == INT_MAX - 1 ? -1 : dp[n][S];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int S = 5;

    int maxWays = maxCoinChange(coins, S);
    cout << "Maximum number of ways for coins: " << maxWays << endl;

    int minCoins = minCoinChange(coins, S);
    if (minCoins != -1)
        cout << "Minimum number of coins to make sum: " << minCoins << endl;
    else
        cout << "No possible way to make the sum using given coins." << endl;

    return 0;
}