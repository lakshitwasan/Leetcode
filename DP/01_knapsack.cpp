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

int main()
{

    vector<int> weight = {1, 3, 4, 5};
    vector<int> price = {1, 4, 5, 7};
    int n = weight.size();
    int W = 7;

    int max_profit = knapsack_recursion(n, weight, price, W);
    cout << "The maximum profit that can be obtained is: " << max_profit << endl;

    return 0;
}