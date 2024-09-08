#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int> &weights, vector<int> &prices, int n, int w)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (weights[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(prices[i - 1] + dp[i][j - weights[i - 1]], dp[i - 1][j]);
            }
        }
    }

    return dp[n][w];
}

int main()
{

    vector<int> weights = {1, 3, 4, 5};
    vector<int> prices = {10, 40, 50, 70};
    int n = weights.size();
    int w = 8;

    int maxProfit = unboundedKnapsack(weights, prices, n, w);

    cout << "Maximum profit in unbounded knapsack: " << maxProfit << endl;

    return 0;
}