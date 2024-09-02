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

vector<vector<int>> dp;

int knapsack_memoized(int n, vector<int> &weight, vector<int> &price, int W)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (weight[n - 1] > W)
    {
        return dp[n][W] = knapsack_recursion(n - 1, weight, price, W);
    }
    else
    {
        return dp[n][W] = max(price[n - 1] + knapsack_recursion(n - 1, weight, price, W - weight[n - 1]), knapsack_recursion(n - 1, weight, price, W));
    }
}

int main()
{

    vector<int> weight = {1, 3, 4, 5};
    vector<int> price = {1, 4, 5, 7};
    int n = weight.size();
    int W = 7;

    dp = vector<vector<int>>(n + 1, vector<int>(W + 1, -1));

    int max_profit1 = knapsack_recursion(n, weight, price, W);
    int max_profit2 = knapsack_memoized(n, weight, price, W);
    cout << "The maximum profit 1 that can be obtained is: " << max_profit1 << endl;
    cout << "The maximum profit 1 that can be obtained is: " << max_profit2 << endl;

    return 0;
}