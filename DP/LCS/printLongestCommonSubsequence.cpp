#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

vector<char> LCS_TopDown(vector<char> x, vector<char> y, int n, int m)
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<char> s;

    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(s.begin(), s.end());

    return s;
}

int main()
{
    vector<char> x = {'A', 'B', 'C', 'D'};
    vector<char> y = {'A', 'B', 'D', 'E', 'C'};

    int n = x.size();
    int m = y.size();

    vector<char> LCS = LCS_TopDown(x, y, n, m);
    cout << "Longest Common Subsequence : ";

    for (int i = 0; i < LCS.size(); i++)
    {
        cout << LCS[i] << " ";
    }

    return 0;
}
