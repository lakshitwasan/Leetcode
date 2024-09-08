#include <bits/stdc++.h>
using namespace std;

int rodCuttingProblem(vector<int> &length, vector<int> &price, int L)
{
    // SAME AS UNBOUNDED KANPSACK BUT ASKED IN A DIFFERENT/BETTER WAY

    int n = length.size();
    vector<vector<int>> dp(n + 1, vector<int>(L + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            if (length[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
        }
    }

    return dp[n][L];
}

int main()
{
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int L = 8;

    int maxProfit = rodCuttingProblem(length, prices, L);

    cout << "Maximum profit in cutting rod: " << maxProfit << endl;

    return 0;
}