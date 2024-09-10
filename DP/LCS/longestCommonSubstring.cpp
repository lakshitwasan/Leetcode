#include <bits/stdc++.h>
using namespace std;

int LCSubstring_recursion(vector<char> X, vector<char> Y, int n, int m, int l)
{
    if (n == 0 || m == 0)
    {
        return l;
    }

    if (X[n - 1] == Y[m - 1])
    {
        l = LCSubstring_recursion(X, Y, n - 1, m - 1, l + 1);
    }
    int len1 = LCSubstring_recursion(X, Y, n - 1, m, 0);
    int len2 = LCSubstring_recursion(X, Y, n, m - 1, 0);
    l = max(l, max(len1, len2));
    return l;
}

int LCSubstring_DP(vector<char> x, vector<char> y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                len = max(len, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return len;
}

int main()
{
    vector<char> X = {'A', 'B', 'C', 'D', 'E'};
    vector<char> Y = {'A', 'B', 'A', 'B', 'C', 'D', 'E'};

    int n = X.size();
    int m = Y.size();

    int result_recursive = LCSubstring_recursion(X, Y, n, m, 0);
    cout << "Length of Longest Common Substring (Recursive): " << result_recursive << endl;

    int result_dp = LCSubstring_DP(X, Y, n, m);
    cout << "Length of Longest Common Substring (DP): " << result_dp << endl;

    return 0;
}
