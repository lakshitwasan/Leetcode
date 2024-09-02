#include <bits/stdc++.h>
using namespace std;

int knapsack_recursion(int n, vector<int> &weight, vector<int> &price, int W)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (weight[n - 1] > W)
    {
        return knapsack_recursion(n - 1, weight, price, W);
    }
    else
    {
        return max(price[n - 1] + knapsack_recursion(n - 1, weight, price, W - weight[n - 1]), knapsack_recursion(n - 1, weight, price, W));
    }
}

vector<vector<int>> dp1;
vector<vector<int>> dp2;

int knapsack_memoized(int n, vector<int> &weight, vector<int> &price, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp1[n][W] != -1)
    {
        return dp1[n][W];
    }

    if (weight[n - 1] > W)
    {
        return dp1[n][W] = knapsack_recursion(n - 1, weight, price, W);
    }
    else
    {
        return dp1[n][W] = max(price[n - 1] + knapsack_recursion(n - 1, weight, price, W - weight[n - 1]), knapsack_recursion(n - 1, weight, price, W));
    }
}

int knapsack_DP(int n, vector<int> &weights, vector<int> &prices, int w)
{
    // BASE CONDITION
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    // RECURSION CALLS
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (weights[i] > j)
            {
                dp2[i][j] = dp2[i - 1][j];
            }
            else
            {
                dp2[i][j] = max(prices[i] + dp2[i - 1][j - weights[i - 1]], dp2[i - 1][j]);
            }
        }
    }

    return dp2[n][w];
}

int main()
{

    vector<int> weight = {1, 3, 4, 5};
    vector<int> price = {1, 4, 5, 7};
    int n = weight.size();
    int W = 7;

    dp1 = vector<vector<int>>(n + 1, vector<int>(W + 1, -1));
    dp2 = vector<vector<int>>(n + 1, vector<int>(W + 1));

    int max_profit1 = knapsack_recursion(n, weight, price, W);
    int max_profit2 = knapsack_memoized(n, weight, price, W);
    int max_profit3 = knapsack_memoized(n, weight, price, W);
    cout << "The maximum profit 1 that can be obtained is: " << max_profit1 << endl;
    cout << "The maximum profit 2 that can be obtained is: " << max_profit2 << endl;
    cout << "The maximum profit 3 that can be obtained is: " << max_profit3 << endl;

    return 0;
}