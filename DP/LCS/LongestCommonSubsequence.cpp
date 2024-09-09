#include <bits/stdc++.h>
using namespace std;

int LCS(vector<char> x, vector<char> y, int n, int m)
{

    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (x[n - 1] == y[m - 1])
    {
        return 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
    }
}

vector<vector<int>> dp;

int LCS_memoized(vector<char> x, vector<char> y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (x[n - 1] == y[m - 1])
    {
        return dp[n][m] = 1 + LCS_memoized(x, y, n - 1, m - 1);
    }
    else
    {
        return dp[n][m] = max(LCS_memoized(x, y, n, m - 1), LCS_memoized(x, y, n - 1, m));
    }
}

vector<vector<int>> dp2;

int LCS_TopDown(vector<char> x, vector<char> y, int n, int m)
{
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            if (x[i - 1] == y[j - 1])
            {
                dp2[i][j] = 1 + dp2[i - 1][j - 1];
            }
            else
            {
                dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
            }
        }
    }

    return dp2[n][m];
}

int main()
{
    vector<char> x = {'A', 'B', 'C', 'D', 'G', 'H'};
    vector<char> y = {'A', 'E', 'D', 'F', 'H', 'R'};

    int n = x.size();
    int m = y.size();

    int lengthLCS_recursive = LCS(x, y, n, m);
    cout << "Length of Longest Common Subsequence (Recursive): " << lengthLCS_recursive << endl;

    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    int lengthLCS_memoized = LCS_memoized(x, y, n, m);
    cout << "Length of Longest Common Subsequence (Memoized): " << lengthLCS_memoized << endl;

    int lengthLCS_topdown = LCS_TopDown(x, y, n, m);
    cout << "Length of Longest Common Subsequence (Top-Down): " << lengthLCS_topdown << endl;

    return 0;
}
